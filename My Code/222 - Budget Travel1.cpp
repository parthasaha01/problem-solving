#include<bits/stdc++.h>
using namespace std;
int n,k;
double ss,sz,ml,c,half,zz;
double w[55],cc[55][55],d[55],dd[55][55]; //dp[55][100000];
map< pair <int,double> , double>dp;
double fun(int p,double v)
{
    if(p==n)return 0;

    pair <int,double> pp;
    pp = make_pair(p,v);
    if(dp[pp]!=0.0)return dp[pp];

    double ret1=1000000000.0, ret2=1000000000.0;
    if((double)v>half)
    {
        if(v<cc[p][p+1]){
            //double tm = ceil(((double)zz - cc[p][p+1]));
            double tm = zz - cc[p][p+1];
            double nd = (double)(zz-v);
            double uu = 200.0 + ((nd*w[p]));
            ret1 = uu + fun(p+1,tm);
        }
        else{
            //double tm = ceil(((double)v - cc[p][p+1]));
            double tm = v - cc[p][p+1];
            ret2 = fun(p+1,tm);
        }
    }
    else
    {
        if(v<cc[p][p+1]){
            //double tm = ceil(((double)zz - cc[p][p+1]));
            double tm = zz - cc[p][p+1];
            double nd = zz-v;
            double uu = 200.0 + ((nd*w[p]));
            ret1 = uu + fun(p+1,tm);
        }
        else{
            //double tm = ceil(((double)zz - cc[p][p+1]));
            double tm = zz - cc[p][p+1];
            double nd = zz-v;
            double uu = 200.0 + ((nd*w[p]));
            ret1 = uu + fun(p+1,tm);

            //tm = ceil(((double)v - cc[p][p+1]));
            tm = v - cc[p][p+1];
            ret2 = fun(p+1,tm);
        }
    }

    double ret;
    if(ret1<ret2)ret=ret1;
    else ret = ret2;
    //return ret;

    pair <int,double> qq;
    qq = make_pair(p,v);
    return dp[qq] = ret;
}
int main()
{
    int ks=0;
    while(scanf("%lf",&ss))
    {
        if(ss<0.0)break;

        scanf("%lf%lf%lf",&sz,&ml,&c);
        scanf("%d",&k);

        //zz =(sz*100.0);
        zz = sz;
        half = sz/2.0;

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
                //cc[i][j] = (dd[i][j]*100.0)/ml;
                cc[i][j] = (dd[i][j])/ml;
            }
        }

        dp.clear();

        double ans = w[0] + fun(1,zz-cc[0][1]);
        ans = ans/100.0;

        printf("Data Set #%d\n",++ks);
        printf("minimum cost = $%.2lf\n",ans);
    }
    return 0;
}

