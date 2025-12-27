#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 10000000000000000LL
#define MAXN 100005
#define lf nd<<1
#define rg (nd<<1)+1
#define m (int)((b+e)>>1)
#define N tree[nd]
#define L tree[lf]
#define R tree[rg]
struct data{
    ll sum,mxx;
}tree[4*MAXN];
ll a[MAXN];
void build(int nd,int b,int e)
{
    if(b==e){
        N.sum = N.mxx = a[b];
        return;
    }
    build(lf,b,m);
    build(rg,m+1,e);
    N.sum = L.sum + R.sum;
    N.mxx = max(L.mxx, R.mxx);
}
void update(int nd,int b,int e,int x,int y)
{
    if(N.mxx==1)return;
    if(b==e){
        N.sum = N.mxx = a[b] = (ll)sqrt(a[b]);
        return;
    }
    if(m>=y)update(lf,b,m,x,y);
    else if(x>m) update(rg,m+1,e,x,y);
    else{
        update(lf,b,m,x,m);
        update(rg,m+1,e,m+1,y);
    }
    N.sum = L.sum + R.sum;
    N.mxx = max(L.mxx, R.mxx);
}
ll query(int nd,int b,int e,int x,int y){
    if(b==x && e==y)return N.sum;

    if(m>=y)return query(lf,b,m,x,y);
    else if(x>m) return query(rg,m+1,e,x,y);
    else{
        ll f1 = query(lf,b,m,x,m);
        ll f2 = query(rg,m+1,e,m+1,y);
        return f1+f2;
    }
}
int main()
{
    int n,ks=0;
    while(scanf("%d",&n)==1){
        printf("Case #%d:\n",++ks);
        for(int i=1; i<=n; i++)scanf("%lld",&a[i]);

        build(1,1,n);

        int q; scanf("%d",&q);
        while(q--){
            int t,x,y; scanf("%d%d%d",&t,&x,&y);
            if(x>y)swap(x,y);
            if(t==0){
                update(1,1,n,x,y);
            }
            else{
                ll ans = query(1,1,n,x,y);
                printf("%lld\n",ans);
            }
        }
        printf("\n");
    }
    return 0;
}
