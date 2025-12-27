#include<bits/stdc++.h>
using namespace std;
int a[55][55];
int b[105];
int dp[105][55];
int n,m;
int score(int pos,int prev)
{
    if(pos==n){
        return 0;
    }
    
    if(dp[pos][prev]!=-1)
        return dp[pos][prev];

    int ret=0;

    if(b[pos]!=-1)
    {
        ret=max(ret,a[prev][b[pos]]+score(pos+1,b[pos]));
    }
    else
    {
        for(int i=1; i<=m; i++)
        {
            ret=max(ret,a[prev][i]+score(pos+1,i));

        }
    }

    return dp[pos][prev]=ret;
}
int main()
{
    int T,maxx;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%d %d",&n,&m);

        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                scanf("%d",&a[i][j]);
            }
        }

        for(int i=0; i<n; i++){
            scanf("%d",&b[i]);
        }

        maxx=score(0,0);

        printf("%d\n",maxx);
    }

    return 0;
}
