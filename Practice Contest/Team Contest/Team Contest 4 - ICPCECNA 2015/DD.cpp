#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[50][50],n,q;
ll dp[25][5][5][5];
ll fun(int pos,int i,int ma, int mb)
{
    if(pos==n){
        return 1LL;
    }

    //if(dp[pos][i][ma][mb]!=-1)return dp[pos][i][ma][mb];

    ll ret = 0;

    if(a[pos][i]!=-1)
    {
        //if((ma&(1<<i))==0)
        {
            if(i<2)
            {
                ret += fun(pos,i+1,(ma|(1<<i)),mb);
            }
            else
            {
                ret += fun(pos+1,0,mb,0);

            }

            if(i<2)
            {
                if(a[pos][i+1]!=-1 && (ma&(1<<(i+1)))==0)
                {
                    if(i<1){
                        int nm = ma;
                        nm = (nm|(1<<i));
                        nm = (nm|(1<<(i+1)));
                        ret += fun(pos,i+2,nm,mb);
                    }
                    else{
                        //int nm = ma;
                        //nm = (nm|(1<<i));
                        //nm = (nm|(1<<(i+1)));
                        ret += fun(pos+1,0,mb,0);
                    }
                }
            }

            if(pos<(n-1))
            {
                if(a[pos+1][i]!=-1 && (mb&(1<<i))==0)
                {
                    if(i<2)
                    {
                        ret += fun(pos,i+1,(ma|(1<<i)),(mb|(1<<i)));
                    }
                    else
                    {
                        ret += fun(pos+1,0,(mb|(1<<i)),0);
                    }
                }
            }
        }
    }

    return dp[pos][i][ma][mb] = ret;
}
int main()
{
    //int n,q;
    //scanf("%d%d",&n,&q);
    cin>>n>>q;

    for(int i=1; i<=q; i++)
    {
        double x, y;
        //scanf("%lf %lf",&x,&y);
        cin>>x>>y;
        int u = (int)x;
        int v = (int)y;
        a[u][v] = -1;
    }

    memset(dp,-1,sizeof(dp));
    ll ans = fun(0,0,0,0);
    cout << ans << endl;

    return 0;
}
