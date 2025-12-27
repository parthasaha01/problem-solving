#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 50005
struct data{
    ll prefix,suffix,infixx,sum;
}tree[4*MAXN];
int a[MAXN];
void maxInfo(int nd)
{
    int lf = 2*nd, rg = 2*nd+1;
    tree[nd].prefix = max(tree[lf].prefix, tree[lf].sum + tree[rg].prefix);
    tree[nd].suffix = max(tree[rg].suffix, tree[rg].sum + tree[lf].suffix);
    tree[nd].infixx = max(tree[lf].infixx, tree[rg].infixx);
    tree[nd].infixx = max(tree[nd].infixx, max(tree[lf].suffix, tree[rg].prefix));
    tree[nd].infixx = max(tree[nd].infixx, tree[lf].suffix+tree[rg].prefix);
    tree[nd].sum    = tree[lf].sum + tree[rg].sum;
}
void build(int nd,int b,int e){
    if(b==e){
        tree[nd].prefix = a[b];
        tree[nd].suffix = a[b];
        tree[nd].infixx = a[b];
        tree[nd].sum = a[b];
        return;
    }

    int  m=(b+e)/2;

    build(2*nd,b,m);
    build(2*nd+1,m+1,e);
    maxInfo(nd);
}
data query(int nd,int b,int e,int x,int y){
    if(b>y || e<x){
        data INF;
        INF.prefix = INF.suffix = INF.infixx = INF.sum = -1000000000;
        return INF;
    }
    if(b>=x && e<=y){
        return tree[nd];
    }
    int m = (b+e)/2;
    data p1 = query(2*nd,b,m,x,y);
    data p2 = query(2*nd+1,m+1,e,x,y);

    data ans;
    ans.prefix = max(p1.prefix, p1.sum + p2.prefix);
    ans.suffix = max(p2.suffix, p2.sum + p1.suffix);
    ans.infixx = max(p1.infixx, p2.infixx);
    ans.infixx = max(ans.infixx, max(p1.suffix, p2.prefix));
    ans.infixx = max(ans.infixx, p1.suffix+p2.prefix);
    ans.sum    = p1.sum + p2.sum;
    return ans;
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    build(1,1,n);

    int q; scanf("%d",&q);
    while(q--){
        int x,y; scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        data ans = query(1,1,n,x,y);
        ll res = max(ans.prefix, max(ans.suffix,ans.infixx));
        //res = max(res,0);
        printf("%lld\n",res);
    }

    return 0;
}
