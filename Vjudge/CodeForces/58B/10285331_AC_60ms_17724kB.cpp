#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>vv;
vector<int>ed[1000005],uu;
int dp[1000005];
int lis(int u)
{
    if(ed[u].size()==0)return dp[u]=1;

    if(dp[u]!=-1)return dp[u];

    int ret = 0;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        ret = max(ret,1+lis(v));
    }

    return dp[u] = ret;
}
void path(int u,int x)
{
    if(x==0) return;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        int ret = lis(v);
        if(ret==x)
        {
            uu.push_back(vv[v]);
            path(v,x-1);
            break;
        }
    }
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        //int sq = sqrt(n);
        vv.clear();
        vv.push_back(0);
        for(int i=1; i<=n; i++)
        {
            if(n%i==0)
            {
                vv.push_back(i);
            }
        }
        int sz=vv.size();

        for(int i=1; i<sz; i++)
        {
            for(int j=i+1; j<sz; j++)
            {
                if(vv[j]%vv[i]==0)
                {
                    ed[i].push_back(j);
                }
            }
        }

        memset(dp,-1,sizeof(dp));
        int ans = lis(1);

        uu.clear();
        uu.push_back(1);
        path(1,ans-1);

        sort(uu.begin(),uu.end());

        int uz = uu.size();
        printf("%d",uu[uz-1]);

        for(int i=uz-2; i>=0; i--)
        {
            printf(" %d",uu[i]);
        }
        printf("\n");

        for(int i=1; i<=sz; i++)ed[i].clear();
    }

    return 0;
}
