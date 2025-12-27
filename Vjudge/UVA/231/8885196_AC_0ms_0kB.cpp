#include<bits/stdc++.h>
using namespace std;
#define mx 40005
int dp[mx];
vector<int>ed[mx],a;
int lis(int u)
{
    if(ed[u].size()==0){
        return dp[u] = 1;
    }
    if(dp[u]!=-1)return dp[u];
    int ret = 0;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        ret = max(ret,1 + lis(v));
    }
    return dp[u] = ret;
}
int main()
{
    int ks=0;
    int x;
    while(scanf("%d",&x) && x!=-1)
    {
        if(ks)printf("\n");

        a.push_back(x);

        while(scanf("%d",&x) && x!=-1){
            a.push_back(x);
        }

        int n = a.size();
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(a[j]<=a[i])
                    ed[i].push_back(j);


        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n; i++){
            int cnt = lis(i);
            ans = max(ans,cnt);
        }
        printf("Test #%d:\n",++ks);
        printf("  maximum possible interceptions: %d\n",ans);

        for(int i=0; i<=n; i++)ed[i].clear();
        a.clear();

    }
    return 0;
}

