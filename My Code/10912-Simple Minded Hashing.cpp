#include<bits/stdc++.h>
using namespace std;
int dp[27][27][352];
int fun(int v,int k,int s)
{
    if(k<0)return 0;
    if(v==27){
        if(s==0 && k==0)return 1;
        return 0;
    }

    if(dp[v][k][s]!=-1)return dp[v][k][s];

    int ret=0;
    if(s-v>=0)ret += fun(v+1,k-1,s-v);
    ret += fun(v+1,k,s);

    return dp[v][k][s] = ret;
}
int main()
{
    int ks=0,k,s;
    memset(dp,-1,sizeof(dp));

    while(scanf("%d%d",&k,&s)==2)
    {
        if(!k&&!s)break;

        if(k>26 || s>351){
            printf("Case %d: 0\n",++ks);
            continue;
        }

//        int maxx=0;
//        for(int i=1; i<=26; i++){
//            for(int j=1; j<=351; j++){
//                int ans = fun(1,i,j);
//                maxx = max(maxx,ans);
//            }
//        }
//        printf("maxx=%d\n",maxx);

        int ans = fun(1,k,s);
        printf("Case %d: %d\n",++ks,ans);
    }
    return 0;
}
