#include<bits/stdc++.h>
using namespace std;
#define mod 100000000
#define ll long long
int FM,HM,FK,HK;
int dp[105][105][15][15];
int fun(int fm,int hm,int fk,int hk)
{
    if(fm+hm==FM+HM){
        if(fm==FM && hm==HM && fk<=FK && hk<=HK) return 1;
        else return 0;
    }

    if(dp[fm][hm][fk][hk]!=-1) return dp[fm][hm][fk][hk];

    if(fm>FM || hm>HM) return 0;

    int ret1=0,ret2=0;

    if(fk<FK) ret1 += fun(fm+1,hm,fk+1,0)%mod;
    if(hk<HK) ret2 += fun(fm,hm+1,0,hk+1)%mod;

    return dp[fm][hm][fk][hk] = (ret1 + ret2)%mod;
}
int main()
{
    while(scanf("%d%d%d%d",&FM,&HM,&FK,&HK)==4)
    {
        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0,0,0);
        printf("%d\n",ans);
    }

    return 0;
}

