#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,T[mx],L[mx],ww[mx],P[mx][20];
vector<int>ed[mx];
void DFS(int u,int fr,int lv)
{
    T[u]=fr;
    L[u]=lv;

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==fr)continue;
        DFS(v,u,lv+1);
    }
}
void lca_init()
{
    memset(P,-1,sizeof(P));
    for(int i=0; i<=n; i++)P[i][0]=T[i];

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(P[i][j-1]!=-1){
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}
int lca_query(int k,int v)
{
    //int log = (int)log2(n);
    int log = (int)log2(L[k]);
    int ans = k;

    for(int i=log; i>=0; i--)
    {
        if(P[k][i]!=-1){
            int u = P[k][i];
            if(ww[u]>=v)
            {
                ans = u;
                k = u;
            }
        }
    }

    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);

        scanf("%d",&n);
        int q; scanf("%d",&q);

        for(int u=1; u<=n-1; u++)
        {
            int v,w; scanf("%d%d",&v,&w);
            ed[v].push_back(u);
            ww[u] = w;
        }
        ww[0]=1;

        DFS(0,-1,0);
        lca_init();

        while(q--)
        {
            int k,v;
            scanf("%d%d",&k,&v);
            int ans = lca_query(k,v);
            printf("%d\n",ans);
        }

        for(int i=0; i<=n; i++)ed[i].clear();
    }
    return 0;
}
