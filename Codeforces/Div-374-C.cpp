#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 10000000001LL
#define mx 5002
vector<int>ed[mx],cost[mx];
vector<int>vv;
ll dp[mx+2][mx+2];
int n,m,t;
ll dfs(int u,int cnt)
{
    if(cnt==0)
    {
        if(u==n){
            return 0;
        }
        else{
            return inf;
        }
    }
    //ll &ret=dp[u][cnt];
    if(dp[u][cnt]!=-1){
        return dp[u][cnt];
    }

    ll ret=inf;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v=ed[u][i];
        ll w=cost[u][i];
        ret=min(ret,w+dfs(v,cnt-1));
    }
    return dp[u][cnt]=ret;
}
ll path(int u,int cnt)
{
    if(cnt==0)
    {
        if(u==n){
            vv.push_back(u);
            return 0;
        }
        else{
            return inf;
        }
    }

    ll temp=dfs(u,cnt);

    for(int i=0; i<ed[u].size(); i++)
    {
        int v=ed[u][i];
        ll w=cost[u][i];
        if(temp==w+dfs(v,cnt-1))
        {
            vv.push_back(u);
            return path(v,cnt-1);
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&t)==3)
    {
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ed[u].push_back(v);
            cost[u].push_back(w);
        }

        memset(dp,-1,sizeof(dp));

        for(int i=n-1; i>=1; i--)
        {
            ll ans=dfs(1,i);

            if(ans<=t){
                path(1,i);

                printf("%d\n",vv.size());
                for(int i=0; i<vv.size(); i++){
                    if(i<vv.size()-1){
                        printf("%d ",vv[i]);
                    }
                    else{
                        printf("%d\n",vv[i]);
                    }
                }
                vv.clear();
                break;
            }

        }

        for(int i=0; i<=n; i++){
            ed[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
