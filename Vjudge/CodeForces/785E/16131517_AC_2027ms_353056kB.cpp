#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
const int Size = 200010;
const int SQRT = 450; /// Maximum no of block
int N, Q, A[Size], bit[SQRT][Size], BUCKET_SIZE;
LL inversion = 0;

void update (int bit[], int u, int v, int MAX) {
    while (u < MAX){
        bit[u] += v;
        u += (u & -u);
    }
}

int query (int bit[], int u) {
    int sum = 0;
    while (u > 0){
        sum += bit[u];
        u -= (u & -u);
    }
    return sum;
}

int findBlock(int u){
    int b = (u - 1)/BUCKET_SIZE + 1;
    return b;
}

/// Returns number of elements smaller than A[u] and A[v] from u+1 to v-1;
pii queryBit(int u, int v){
    int b1  = findBlock(u);
    int st1 = (b1-1)*BUCKET_SIZE + 1;
    int ed1 = b1*BUCKET_SIZE;
    ed1 = min(ed1, N);

    int b2 = findBlock(v);
    int st2 = (b2-1)*BUCKET_SIZE + 1;
    int ed2 = b2*BUCKET_SIZE;
    ed2 = min(ed2, N);

    int res1 = 0,res2 = 0;
    if(b1 == b2){
        for(int p=u+1; p<v; p++){
            if(A[p]<A[u]) res1++;
            if(A[p]<A[v]) res2++;
        }
        return make_pair(res1,res2);
    }

    for(int p=u+1; p<=ed1; p++){
        if(A[p]<A[u]) res1++;
        if(A[p]<A[v]) res2++;
    }

    for(int p=st2; p<v; p++){
        if(A[p]<A[u]) res1++;
        if(A[p]<A[v]) res2++;
    }

    for(int b=b1+1; b<b2; b++){
        res1 += query(bit[b], A[u]-1);
        res2 += query(bit[b], A[v]-1);
    }
    return make_pair(res1,res2);
}

void updateBit(int u, int v){
    int b1 = findBlock(u);
    int b2 = findBlock(v);
    update(bit[b1], A[u], -1, Size);
    update(bit[b2], A[v], -1, Size);
    update(bit[b1], A[v],  1, Size);
    update(bit[b2], A[u],  1, Size);
}

void solve(int u, int v){
    pii rtt = queryBit(u, v);
    int tot = v - u + 1 - 2;
    int smlU = rtt.first;
    int smlV = rtt.second;
    int bigU = tot - smlU;
    int bigV = tot - smlV;

    inversion -= smlU;
    inversion += bigU;

    inversion -= bigV;
    inversion += smlV;

    if(A[u]>A[v]) inversion--;
    else inversion++;

    updateBit(u, v);

    swap(A[u], A[v]);
    printf("%lld\n",inversion);
}

int main(){
	scanf("%d %d",&N,&Q);
	BUCKET_SIZE = sqrt(N);
	memset(bit,0,sizeof(bit));
	for(int i=1; i<=N; i++){
        A[i] = i;
        int b = findBlock(i);
        update(bit[b], A[i], 1, Size);
	}

	for(int i=0; i<Q; i++){
        int u,v; scanf("%d %d",&u,&v);
        if(u>v) swap(u,v);
        if(u == v){
            printf("%lld\n",inversion);
            continue;
        }
        solve(u, v);
	}
	return 0;
}
