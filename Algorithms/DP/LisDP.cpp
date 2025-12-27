#include<bits/stdc++.h>
using namespace std;
#define mx 10005
int a[mx],dp[mx];
vector<int>ed[mx];
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
    int tt;scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                if(a[j]<=a[i])
                    ed[i].push_back(j);


        int ans = 0;
        int start = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=1; i<=n; i++){
            int cnt = lis(i);
            if(cnt>ans){
                start = i;
                ans = cnt;
            }
        }

        printf("%d\n",ans);
        int v = ans;
        for(int i=start; i<=n && v; i++){
            if(dp[i]==v){
                printf("%d ",a[i]);
                v--;
            }
        }
        printf("\n");

        for(int i=0; i<=n; i++)ed[i].clear();

    }
    return 0;
}
