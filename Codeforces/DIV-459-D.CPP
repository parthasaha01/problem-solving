#include<bits/stdc++.h>
using namespace std;
int dp[101][101][27][2];
int cost[101][101];
int ans[101][101];
vector<int>ed[101];
int fun(int u,int v,int k,int id)
{

    if(dp[u][v][k][id]!=-1)return (dp[u][v][k][id]^1);
    int ret=0;
    //int flag=0;

    if(id==0)
    {
        for(int i=0; i<ed[u].size(); i++)
        {
            int x = ed[u][i];
            int w = cost[u][x];
            if(w<k)continue;

            ret |= fun(x,v,w,1-id);
        }
    }
    else
    {
        for(int i=0; i<ed[v].size(); i++)
        {
            int x = ed[v][i];
            int w = cost[v][x];
            if(w<k)continue;

            ret |= fun(u,x,w,1-id);

        }
    }

    dp[u][v][k][id] = ret;
    return ret^1;
}
int main()
{
    int n,m; scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++)
    {
        int u,v;
        char c;
        scanf("%d %d %c",&u,&v,&c);
        //printf("%d %d %c\n",u,v,c);
        ed[u].push_back(v);
        cost[u][v] = c-'a'+1;
    }

    memset(dp,-1,sizeof(dp));

    //int res = fun(2,2,0,0);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int res = fun(i,j,0,0);
            //ans[i][j] = res;
            ans[i][j] = dp[i][j][0][0];
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(ans[i][j]==1)printf("A");
            else printf("B");
        }
        printf("\n");
    }

    return 0;
}
/*
5 8
5 3 h
1 2 c
3 1 c
3 2 r
5 1 r
4 3 z
5 4 r
5 2 h
*/
