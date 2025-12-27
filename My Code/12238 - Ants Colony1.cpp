#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int height,block_sz;
int depth[mx],parent[mx],jump_parent[mx];
ll block_weight[mx],par_weight[mx];
vector<int>ed[mx];
vector<ll>cost[mx];
void dfsHeight(int u,int h,int pr)
{
    height = max(height,h);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v!=pr)dfsHeight(v,h+1,u);
    }
}
void DFS(int u,int lv,int pr,ll cur,ll sum)
{
    depth[u]=lv;
    parent[u] = pr;
    par_weight[u]=cur;

    if(depth[u]%block_sz==0)jump_parent[u]=parent[u];
    else jump_parent[u] = jump_parent[pr];

    if(depth[u]%block_sz==0)sum=0;
    block_weight[u] = sum+cur;

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        ll w = cost[u][i];
        if(v!=pr)DFS(v,lv+1,u,w,block_weight[u]);
    }
}
//ll LCANaive(int u,int v)
//{
//    if(u==v)return 0;
//
//    ll sum = 0;
//
//    if(depth[u]>depth[v])swap(u,v);
//    while(depth[u]!=depth[v]){
//        sum += par_weight[v];
//        v = parent[v];
//    }
//
//    while(u!=v)
//    {
//        sum += par_weight[u];
//        sum += par_weight[v];
//        u = parent[u];
//        v = parent[v];
//    }
//    return sum;
//}
ll LCANaive(int u,int v)
{
    if(u==v)return 0;
    if(depth[u]>depth[v])swap(u,v);
    ll ret = par_weight[v];
    v = parent[v];
    return ret + LCANaive(u,v);
}
ll LCASQRT(int u,int v)
{
    ll sum = 0;
    while(jump_parent[u]!=jump_parent[v])
    {
        if(depth[u]>depth[v])swap(u,v);
        sum += block_weight[v];
        v = jump_parent[v];
    }
    // u and v have same jump_parent
    // u and v are now same block
    sum += LCANaive(u,v);
    return sum;
}
void preprocess()
{
   height = 0;
   dfsHeight(1,1,0);
   block_sz = sqrt(height);
   depth[0]=-1;
   DFS(1,0,0,0,0);
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)break;

        for(int u=2; u<=n; u++){
            int v; ll w;
            scanf("%d%lld",&v,&w);
            v++;
            ed[u].push_back(v);
            ed[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        preprocess();

        int q; scanf("%d",&q);
        while(q--)
        {
            int u,v; scanf("%d%d",&u,&v);
            u++, v++;
            ll ans = LCASQRT(u,v);
            if(q==0)printf("%lld\n",ans);
            else printf("%lld ",ans);
        }

        for(int i=0; i<=n; i++){
            ed[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

