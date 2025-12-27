#include<bits/stdc++.h>
using namespace std;
int n,k,dp[1005];
vector<int>ed[1005];
int DFS(int u,int pr)
{
    int sz = ed[u].size();
    if(sz<k && u==1)return dp[u]=1;
    if(sz<=k && u!=1)return dp[u]=1;

    vector<int>cnt;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;
        int x = DFS(v,u);
        cnt.push_back(x);
    }

    sort(cnt.begin(),cnt.end());
    sz = cnt.size();
    int sum = 0;
    for(int i=sz-1, j=1; j<=k; j++,i--)
    {
        sum += cnt[i];
    }

    cnt.clear();

    //cout << u << " " << sum << endl;

    return dp[u] = sum+1;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&k);

        for(int i=1; i<=n-1; i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        int ans = DFS(1,0);

        printf("Case %d: %d\n",ks,ans);

        for(int i=1; i<=n; i++)ed[i].clear();
    }
    return 0;
}
