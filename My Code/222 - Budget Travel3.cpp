#include<bits/stdc++.h>
using namespace std;
int n,k,zz;
double ss,sz,ml,c,half;
double w[55],cc[55][55],d[55],dd[55][55],dp[55][100000];
double fun(int p,int v)
{
    if(p==n)return 0;

    //if(dp[p][v]!=-1.0)return dp[p][v];

    double ret1=1000000000.0, ret2=1000000000.0;
    if((double)v>half)
    {
        if(v<cc[p][p+1]){
            double tm = ceil(((double)zz - cc[p][p+1]));
            double nd = (double)(zz-v);
            double uu = 200.0 + ((nd*w[p])/100.0);
            ret1 = uu + fun(p+1,(int)tm);
        }
        else{
            double tm = ceil(((double)v - cc[p][p+1]));
            ret2 = fun(p+1,(int)tm);
        }
    }
    else
    {
        if(v<cc[p][p+1]){
            double tm = ceil(((double)zz - cc[p][p+1]));
            double nd = zz-v;
            double uu = 200 + ((nd*w[p])/100.0);
            ret1 = uu + fun(p+1,(int)tm);
        }
        else{
            double tm = ceil(((double)zz - cc[p][p+1]));
            double nd = zz-v;
            double uu = 200 + ((nd*w[p])/100.0);
            ret1 = uu + fun(p+1,(int)tm);

            tm = ceil(((double)v - cc[p][p+1]));
            ret2 = fun(p+1,(int)tm);
        }
    }

    double ret;
    if(ret1<ret2)ret=ret1;
    else ret = ret2;
    return ret;
    //return dp[p][v] = ret;
}
int main()
{
    int ks=0;
    while(scanf("%lf",&ss))
    {
        if(ss<0.0)break;

        scanf("%lf%lf%lf",&sz,&ml,&c);
        scanf("%d",&k);

        zz = (int)(sz*100);

        d[0]=0.0;
        w[0]=(c*100.0);
        for(int i=1; i<=k; i++){
            scanf("%lf%lf",&d[i],&w[i]);
        }
        n=k+1;
        d[n]=ss;
        for(int i=0; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                dd[i][j] = d[j]-d[i];
                cc[i][j] = (dd[i][j]*100.0)/ml;
            }
        }

        double tm = ceil(((double)zz - cc[0][1]));
        double ans = w[0] + fun(1,tm);
        ans = ans/100.0;

        printf("Data Set #%d\n",++ks);
        printf("minimum cost = $%.2lf\n",ans);
    }
    return 0;
}
