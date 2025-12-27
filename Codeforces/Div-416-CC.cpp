#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],dp[5005],vis[5005],vs[5005],last[5005];
struct dt
{
    int bg,ed;
}st[5005];
int fun(int i)
{
    if(i>n)return 0;
    if(vis[i]==0)return 0;

    if(dp[i]!=-1)return dp[i];

    int ret1=s[i], ret2=0;
    for(int j=last[i]+1; j<=n; j++){
        ret1 = max(ret1, s[i]+fun(j));
    }
    ret2 = fun(i+1);

    return dp[i] = max(ret1,ret2);
}
int main()
{
    while(scanf("%d",&n)==1)
    {

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
        {
            if(vis[a[i]]==0){
                st[a[i]].bg=i;
                vis[a[i]]=1;
            }
        }

        memset(vis,0,sizeof(vis));
        for(int i=n; i>=1; i--)
        {
            if(vis[a[i]]==0){
                st[a[i]].ed=i;
                vis[a[i]]=1;
            }
        }

        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
        {
            if(st[a[i]].bg==i){
                int z = st[a[i]].ed;
                bool flag=true;
                for(int j=i; j<=z; j++){
                    z = max(z,st[a[j]].ed);
                    if(st[a[j]].bg<i){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    last[i] = z;
                    vis[i] = 1;

                    int xr=0;
                    memset(vs,0,sizeof(vs));
                    for(int j=i; j<=z; j++){
                        if(vs[a[j]]==0){
                            xr = xr^a[j];
                            vs[a[j]]=1;
                        }
                    }
                    s[i] = xr;
                }
            }
        }

        memset(dp,-1,sizeof(dp));
        int ans=0,cnt;
        for(int i=1; i<=n; i++){
            if(vis[i]==1){
                cnt=fun(i);
                ans=max(ans,cnt);
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}

