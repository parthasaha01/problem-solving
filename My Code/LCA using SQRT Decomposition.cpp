#include<bits/stdc++.h>
using namespace std;
#define ll lomg long
#define mx 100005
int height,block_sz;
int depth[mx],parent[mx],jump_parent[mx];
vector<int>ed[mx];
void dfsHeight(int u,int h,int pr)
{
    height = max(height,h);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v!=pr)dfsHeight(v,h+1,u);
    }
}
void DFS(int u,int lv,int pr)
{
    depth[u]=lv;
    parent[u] = pr;

    if(depth[u]%block_sz==0)jump_parent[u]=parent[u];
    else jump_parent[u] = jump_parent[pr];

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v!=pr)DFS(v,lv+1,u);
    }
}
int LCANaive(int u,int v)
{
    if(u==v)return u;

    if(depth[u]>depth[v])swap(u,v);
    while(depth[u]!=depth[v]){
        v = parent[v];
    }

    while(u!=v)
    {
        u = parent[u];
        v = parent[v];
    }
    return u;
}
//int LCANaive(int u,int v)
//{
//    if(u==v)return u;
//    if(depth[u]>depth[v])swap(u,v);
//    v = parent[v];
//    return LCANaive(u,v);
//}
int LCASQRT(int u,int v)
{
    while(jump_parent[u]!=jump_parent[v])
    {
        if(depth[u]>depth[v])swap(u,v);
        v = jump_parent[v];
    }
    // u and v have same jump_parent
    // u and v are now same block
    int lca = LCANaive(u,v);
    return lca;
}
void preprocess()
{
   height = 0;
   dfsHeight(1,1,0);
   block_sz = sqrt(height);
   depth[0]=-1;
   DFS(1,0,0);
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)break;

        for(int i=1; i<n; i++){
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        preprocess();

        int q; scanf("%d",&q);
        while(q--)
        {
            int u,v; scanf("%d%d",&u,&v);
            int lca = LCASQRT(u,v);
            printf("%d\n",lca);
        }

        for(int i=0; i<=n; i++)ed[i].clear();
    }
    return 0;
}
/*
35
1 2
1 3
1 4
2 5
3 6
3 7
4 8
6 9
6 10
6 11
8 12
9 13
9 14
11 15
12 16
14 17
14 18
14 19
15 20
15 21
17 22
19 23
19 24
21 25
21 26
23 27
23 28
25 29
25 30
28 31
28 32
28 33
30 34
30 35

*/
