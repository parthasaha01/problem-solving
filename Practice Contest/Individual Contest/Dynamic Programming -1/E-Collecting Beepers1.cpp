#include<bits/stdc++.h>
using namespace std;
int r,c,n,w[15][15],dp[12][1<<12];
struct dt{ int x,y; }s[15];
int check(int mask,int pos){ return mask & (1<<pos); }
int seton(int mask,int pos){ return mask | (1<<pos); }
int fun(int u,int mask)
{
    if(mask == (1<<(n+1))-1){ return w[u][0];}

    if(dp[u][mask]!=-1)return dp[u][mask];

    int ret = 1<<28;

    for(int i=1; i<=n; i++)
    {
        if(check(mask,i)==0)
        {
            ret = min(ret, w[u][i]+fun(i,seton(mask,i)));
        }
    }

    return dp[u][mask]=ret;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d%d",&r,&c);

        scanf("%d%d",&s[0].x,&s[0].y);
        scanf("%d",&n);
        //n++;
        for(int i=1; i<=n; i++){
            scanf("%d%d",&s[i].x,&s[i].y);
        }

        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                w[i][j] = abs(s[i].x-s[j].x) + abs(s[i].y-s[j].y);
            }
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,1);
        printf("The shortest path has length %d\n",ans);
    }
    return 0;
}
