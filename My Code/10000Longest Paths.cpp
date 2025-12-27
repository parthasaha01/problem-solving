#include<bits/stdc++.h>
using namespace std;
vector<int>G[105];
int vis[105];
int val[105];
int dp[105];
int des[105];
int src;
int dfs(int s)
{
    if(dp[s]!=-1){
        return dp[s];
    }

    int sz=G[s].size();

    if(sz==0){
        des[s]=s;
        dp[s]=0;
        return 0;
    }
    int ret=0;
    for(int i=0; i<sz; i++){
        int u=G[s][i];
        //printf("%d %d\n",s,u);

        ret=1+dfs(u);
        if(ret>dp[s]){
            des[s]=des[u];
            dp[s]=ret;
        }
        else if(ret==dp[s]){
            if(des[u]<des[s]){
               des[s]=des[u];
            }
        }

        //dp[s] = max(dp[s],1+dfs(u));
    }

    return dp[s];
}
int main()
{
    int n,kase=0;

    while(scanf("%d",&n) && n)
    {
        scanf("%d",&src);

        memset(dp,-1,sizeof(vis));
        memset(val,0,sizeof(val));

        int u,v;
        while(scanf("%d %d",&u,&v))
        {
            if(u==0 && v==0)
                break;
            G[u].push_back(v);
        }

        int maxx=dfs(src);

        /*for(int i=1; i<=n; i++){
            printf("node=%d val=%d des=%d\n",i,dp[i],des[i]);
        }
        int endd=src,maxx=0;
        for(int i=1; i<=n; i++){
            if(val[i]>maxx){
                maxx=val[i];
                endd=i;
            }
        }*/

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++kase,src,maxx,des[src]);

        for(int i=1; i<=n; i++){
            G[i].erase(G[i].begin(),G[i].end());
        }
    }

    return 0;
}
