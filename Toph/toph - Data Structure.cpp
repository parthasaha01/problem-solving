#include<bits/stdc++.h>
using namespace std;
#define N 1000000
int tree[4*N], a[100005], q[100005], ans[100005];
void update(int node, int b, int e, int x){
    if(b==x && e==x){
        tree[node]++;
        return;
    }
    int lson=2*node, rson=lson+1, m=(b+e)/2;
    if(x<=m)update(lson,b,m,x);
    else update(rson,m+1,e,x);
    tree[node] = tree[lson]+tree[rson];
}
int query(int node, int b, int e, int k){
    if(b==e) return b;
    int lson=2*node, rson=lson+1, m=(b+e)/2;
    if(tree[lson]>=k)return query(lson,b,m,k);
    else return query(rson,m+1,e,k-tree[lson]);
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d",&q[i]);
    }

    for(int i=1; i<=n; i++){
        update(1,1,N,a[i]);
        ans[i] = query(1,1,N,q[i]);
    }

    for(int i=1; i<=n; i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}
