#include<bits/stdc++.h>
using namespace std;
vector<int>ed[1005],vv;
int k,dp[1005],a[1005],w[1005];
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
    if(x==0)return;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        int ret = 1+lis(v);
        if(ret==x){
            vv.push_back(v);
            path(v,x-1);
            break;
        }
    }
}
int main()
{
    //while(scanf("%d",&a[1])==1)
    //{
        k=1;
        while(scanf("%d%d",&w[k],&a[k])==2){
            k++;
        }
        k--;
        //printf("k=%d\n",k);
        for(int i=1; i<=k; i++)
        {
            for(int j=1; j<=k; j++)
            {
                if(i==j)continue;

                if(w[j]>w[i] && a[j]<a[i]){
                    ed[i].push_back(j);
                }
            }
        }

        for(int i=1; i<=k; i++)ed[0].push_back(i);

        memset(dp,-1,sizeof(dp));
        int ans = lis(0);

        path(0,ans);

        printf("%d\n",ans-1);
        for(int i=0; i<vv.size(); i++){
            printf("%d\n",vv[i]);
        }

        vv.clear();
        for(int i=0; i<=k; i++)ed[i].clear();
    //}
    return 0;
}

