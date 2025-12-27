#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>ed[100005];
int dp[100005][2];
void DFS(int u,int pr)
{
    //bool leaf = true;
    dp[u][0] = 0;
    dp[u][1] = 1;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;
        //leaf = false;
        DFS(v,u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0],dp[v][1]);
    }

}
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<n; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    DFS(1,0);

    int ans = min(dp[1][0],dp[1][1]);

    printf("%d\n",ans);

    return 0;
}
