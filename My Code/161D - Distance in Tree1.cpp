#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int dp[50002][502];
vector<int>ed[50002];
void DFS(int u,int pr)
{
    dp[u][0]=1;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;

        DFS(v,u);

        for(int j=0; j<k; j++){
            ans += dp[u][j]*dp[v][k-j-1];
        }

        for(int j=1; j<=k; j++){
            dp[u][j] += dp[v][j-1];
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<n; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    DFS(1,0);

    printf("%d\n",ans);

    return 0;
}

