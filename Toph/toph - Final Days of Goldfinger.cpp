#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define inf 1000000000000000LL
#define lf nd<<1
#define rg (nd<<1)+1
#define m (int)((b+e)>>1)
#define N tree[nd]
#define L tree[lf]
#define R tree[rg]

int a[MAXN],h[MAXN];
struct data{
    ll prefix,suffix,infixx,sum;
}tree[4*MAXN];

data maxData(data x, data y){
    data z;
    z.prefix = max(x.prefix, x.sum + y.prefix);
    z.suffix = max(y.suffix, y.sum + x.suffix);
    z.infixx = max(max(x.infixx, y.infixx), x.suffix + y.prefix);
    z.sum    = x.sum + y.sum;
    return z;
}
void build(int nd,int b,int e){
    if(b==e){
        N.prefix = N.suffix = N.infixx = N.sum = a[b];
        return;
    }
    build(lf,b,m);
    build(rg,m+1,e);
    N = maxData(L,R);
}
void update(int nd,int b,int e,int x,int v){
    if(b==e && b==x){
        N.prefix = N.suffix = N.infixx = N.sum = a[b] = v;
        return;
    }
    if(x<=m)update(lf,b,m,x,v);
    else update(rg,m+1,e,x,v);
    N = maxData(L,R);
}
data query(int nd,int b,int e,int x,int y){
    if(b>y || e<x){
        data INF;
        INF.prefix = INF.suffix = INF.infixx = INF.sum = -inf;
        return INF;
    }
    if(b>=x && e<=y) return tree[nd];
    data f1 = query(lf,b,m,x,y);
    data f2 = query(rg,m+1,e,x,y);
    return maxData(f1,f2);
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        printf("Case %d:\n",ks);
        int n,q; scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++) scanf("%d",&h[i]);
        for(int i=2; i<=n; i++) a[i] = h[i]-h[i-1];
        memset(tree,0,sizeof(tree));
        build(1,1,n);

        while(q--){
            int t,x,y; scanf("%d%d%d",&t,&x,&y);
            if(t==1){
                h[x] = y;
                if(x>1){
                    a[x] = h[x] - h[x-1];
                    update(1,1,n,x,a[x]);
                }
                if(x<n){
                    a[x+1] = h[x+1] - h[x];
                    update(1,1,n,x+1,a[x+1]);
                }

            }else{
                if(x==y){
                    printf("0\n");
                }else{
                    data ans = query(1,1,n,x+1,y);
                    ll res = max(max(ans.prefix,ans.suffix), max(ans.infixx,ans.sum));
                    printf("%lld\n",max(0LL,res));
                }
            }
        }
    }
    return 0;
}

