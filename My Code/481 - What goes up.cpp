#include<bits/stdc++.h>
using namespace std;
vector<int>ed[100005],vv;
int k,dp[100005],a[100005];
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
    if(x==0){
        return;
    }

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        int ret = lis(v);
        if(ret==x){
            vv.push_back(a[v]);
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
        while(scanf("%d",&a[k])==1){
            k++;
        }
        k--;
        //printf("k=%d\n",k);
        for(int i=1; i<=k; i++)
        {
            for(int j=k; j>i; j--)
            {
                if(a[j]>a[i]){
                    ed[i].push_back(j);
                }
            }
        }

        memset(dp,-1,sizeof(dp));
        int ans = lis(1);

        int p=0;
        for(int i=k; i>=1; i--){
            if(dp[i]==ans){
                p=i;
                break;
            }
        }
        vv.push_back(a[p]);
        path(p,ans-1);
        printf("%d\n-\n",ans);

        for(int i=0; i<vv.size(); i++){
            printf("%d\n",vv[i]);
        }

        vv.clear();
        for(int i=1; i<=k; i++)ed[i].clear();
    //}
    return 0;
}
