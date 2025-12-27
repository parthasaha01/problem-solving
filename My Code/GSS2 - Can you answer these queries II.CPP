#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define lf nd<<1
#define rg (nd<<1)+1
#define m (int)((b+e)>>1)
#define N tree[nd]
#define L tree[lf]
#define R tree[rg]

struct qry{
    int x,y,i;
}qr[MAXN];
bool cmp(qry A, qry B){
    return A.y < B.y;
}

int n,a[MAXN],pre[2*MAXN],cnt[MAXN];
ll ans[MAXN];
struct data{
    ll best_sum, sum, best_lazy, lazy;
}tree[4*MAXN];

void pushUp(int nd){
    N.best_sum  = max(L.best_sum, R.best_sum);
    N.sum       = max(L.sum, R.sum);
}
void pushDown(int nd){
    L.best_sum  = max(L.best_sum,  L.sum  + N.best_lazy);
    L.sum  += N.lazy;
    L.best_lazy = max(L.best_lazy, L.lazy + N.best_lazy);
    L.lazy += N.lazy;

    R.best_sum  = max(R.best_sum,  R.sum  + N.best_lazy);
    R.sum  += N.lazy;
    R.best_lazy = max(R.best_lazy, R.lazy + N.best_lazy);
    R.lazy += N.lazy;

    N.best_lazy = N.lazy = 0;
}
void update(int nd,int b,int e,int x,int y,int val){
    if(b==x && e==y){
        N.best_sum  = max(N.best_sum,  N.sum  + val);
        N.sum += val;
        N.best_lazy = max(N.best_lazy, N.lazy + val);
        N.lazy += val;
        return;
    }

    pushDown(nd);

    if(y<=m)update(lf,b,m,x,y,val);
    else if(x>m) update(rg,m+1,e,x,y,val);
    else{
        update(lf,b,m,x,m,val);
        update(rg,m+1,e,m+1,y,val);
    }

    pushUp(nd);
}
ll query(int nd,int b,int e,int x,int y){
    if(b==x && e==y) return N.best_sum;

    pushDown(nd);

    if(y<=m) return query(lf,b,m,x,y);
    else if(x>m) return query(rg,m+1,e,x,y);
    else{
        ll f1 = query(lf,b,m,x,m);
        ll f2 = query(rg,m+1,e,m+1,y);
        return max(f1,f2);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    int q; scanf("%d",&q);
    for(int i=1; i<=q; i++){
        int x,y; scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        qr[i].x = x;
        qr[i].y = y;
        qr[i].i = i;
        cnt[y]++;
    }

    sort(qr+1,qr+q+1,cmp);

    memset(pre,0,sizeof(pre));
    memset(tree,0,sizeof(tree));
    int cur = 1;

    for(int i=1; i<=n; i++){
        int v = a[i] + 100000;

        update(1,1,n,pre[v]+1,i,a[i]);
        pre[v] = i;

        for(int j=1; j<=cnt[i]; j++){
            int x = qr[cur].x;
            int y = qr[cur].y;
            ll res = query(1,1,n,x,y);
            ans[qr[cur].i] = res;
            cur++;
        }
    }

    for(int i=1; i<=q; i++){
        printf("%lld\n",ans[i]);
    }

    return 0;
}

/*

8
1 2 -1 3 2 -1 2 -1
2
1 8
2 8

4
1 2 -1 -1
1
2 3


*/
