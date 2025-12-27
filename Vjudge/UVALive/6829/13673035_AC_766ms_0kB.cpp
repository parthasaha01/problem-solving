#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>ed[mx],cs[mx];
int flag[mx],fr[mx];
int dp[mx][2];
void DFS(int u,int pr)
{
    if(flag[u]==1)fr[u]=1;

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v!=pr){
            DFS(v,u);
            fr[u]+=fr[v];
        }
    }
}
void fun(int u,int pr)
{
    //if(fr[u]==0)return;

    dp[u][0]=0;
    dp[u][1]=0;

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        int w = cs[u][i];
        if(v!=pr && fr[v]>0){
            fun(v,u);
            dp[u][1] += w + dp[v][1];
        }
    }

    int minn = 1000000000;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        int w = cs[u][i];
        if(v!=pr && fr[v]>0){
            int cost = dp[u][1]-dp[v][1]+dp[v][0]-w;
            minn = min(minn,cost);
        }
    }
    dp[u][0]=minn;
    if(dp[u][0]==1000000000)dp[u][0]=0;
}
int main()
{
    int n,f;
    while(scanf("%d%d",&n,&f)==2)
    {
        memset(dp,0,sizeof(dp));
        memset(flag,0,sizeof(flag));
        memset(fr,0,sizeof(fr));

        for(int i=1; i<n; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ed[u].push_back(v);
            ed[v].push_back(u);
            cs[u].push_back(w);
            cs[v].push_back(w);
        }

        for(int i=1; i<=f; i++)
        {
            int x; scanf("%d",&x);
            flag[x]=1;
        }

        DFS(1,0);

        fun(1,0);

        printf("%d\n",dp[1][0]);

        for(int i=0; i<=n; i++){
            ed[i].clear();
            cs[i].clear();
        }
    }
}
