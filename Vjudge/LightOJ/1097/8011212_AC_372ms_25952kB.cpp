#include<bits/stdc++.h>
using namespace std;
#define mx 1429450
int tree[4*mx+5];
int ans[100005];
void init(int nd,int b,int e)
{
    if(b==e){
        if(b&1)tree[nd]=1;
        else tree[nd]=0;
        return;
    }
    int lf = nd*2;
    int rg = nd*2+1;
    int md = (b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);
    tree[nd] = tree[lf]+tree[rg];
}
void update(int nd,int b,int e,int x)
{
    if(b==x && e==x){
        tree[nd]=0;
        return;
    }

    if(x<b || x>e)return;

    int lf = nd*2;
    int rg = nd*2+1;
    int md = (b+e)/2;

    update(lf,b,md,x);
    update(rg,md+1,e,x);
    tree[nd] = tree[lf]+tree[rg];
}
int query(int nd,int b,int e,int x)
{
    if(b==e){
        return b;
    }
    int lf = nd*2;
    int rg = nd*2+1;
    int md = (b+e)/2;

    if(x<=tree[lf]){
        return query(lf,b,md,x);
    }
    else{
        return query(rg,md+1,e,x-tree[lf]);
    }
}
void precalculate()
{
    init(1,1,mx);
    ans[1]=1;
    for(int i=2; i<=mx; i++){
        if(i>tree[1])break;

        int v = query(1,1,mx,i);
        ans[i] = v;

        vector<int>pv;
        for(int j=v; j<=mx; j+=v){
            if(j>tree[1])break;
            int p = query(1,1,mx,j);
            pv.push_back(p);
        }

        for(int j=0; j<pv.size(); j++){
            update(1,1,mx,pv[j]);
        }
    }
}
int main()
{
    precalculate();

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        printf("Case %d: %d\n",ks,ans[n]);
    }
    return 0;
}
