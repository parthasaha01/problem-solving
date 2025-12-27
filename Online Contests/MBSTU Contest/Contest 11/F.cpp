#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10005];
int ans[10005];
int node[10005];
int dfs(int u)
{
    if(graph[u].size()==0)
    {
        //printf("u=%d\n",u);
        //getchar();
        ans[u]=0;
        return 0;
    }

    int sum=0;
    int ret=0;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        //int vl=dfs(v)+1;
        int vl=dfs(v)+1;
        //printf("u=%d ans=%d\n",u,ret);
        //getchar();
        ans[u]+=vl*ret;
        ret+=vl;
        //sum+=vl;
    }
    ans[u]+=ret;
    return node[u]=ret;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        memset(ans,0,sizeof(ans));
        memset(node,0,sizeof(node));

        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            int x;
            scanf("%d",&x);
            graph[x].push_back(i);
        }
        //getchar();
        dfs(0);

        printf("Forest#%d:",ks);
        for(int i=1; i<=n; i++)
        {
            printf(" %d",ans[i]);
        }
        printf("\n");

        for(int i=0; i<=n; i++){
            graph[i].clear();
        }
    }

    return 0;
}

