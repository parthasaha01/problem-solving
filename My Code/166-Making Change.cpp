#include<bits/stdc++.h>
using namespace std;
int a[]={5,10,20,50,100,200};
int dp[10][505],wp[10][505],step[505],w[10];
int calc(int p,int v)
{
    if(v==0)return 0;
    if(p==6)return 10000000;

    if(wp[p][v]!=-1)return wp[p][v];

    int ret1=10000000,ret2=10000000;

    if(v-a[p]>=0)ret1 = 1+calc(p,v-a[p]);
    ret2 = calc(p+1,v);

    return wp[p][v] = min(ret1,ret2);
}
int fun(int p,int v)
{
    if(v==0)return 0;
    if(v<0){
            v=(-1)*v;
            if(v<=500)return step[v];
            else return 10000000;
    }
    if(p==6)return 10000000;

    if(dp[p][v]!=-1)return dp[p][v];

    int ret1=10000000,ret2=10000000;
    for(int i=1; i<=w[p]; i++)
    {
        ret1 = min(ret1, i+fun(p+1,v-(a[p]*i)));
    }
    ret2 = fun(p+1,v);

    return dp[p][v] = min(ret1,ret2);
}
int main()
{
    memset(wp,-1,sizeof(wp));
    for(int v=5; v<=500; v+=5)
    {
        int cnt=calc(0,v);
        step[v]=cnt;
    }

//    for(int i=5; i<=500; i+=5){
//        printf("%d %d\n",i,step[i]);
//    }

    while(scanf("%d%d%d%d%d%d",&w[0],&w[1],&w[2],&w[3],&w[4],&w[5]))
    {
        int ws=w[0]+w[1]+w[2]+w[3]+w[4]+w[5];
        if(ws==0)break;

        double vd; scanf("%lf",&vd);

        int v = (int)(vd*100.0);
        if((v%5)!=0)v++;

        //if(v%5!=0)while(1);

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,v);

        printf("%3d\n",ans);
    }
    return 0;
}
