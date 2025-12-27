#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pii pair<int,int>
map< pair<int,int>, ll> dp;
//map< int, map<int, int> > vs;
int a[150005],n;
ll w[150005];
ll fun(int pos,int maxx)
{
    if(pos==n)return 0LL;

    pii p;
    p = mp(pos,maxx);

    if(dp.find(p)!=dp.end())return dp[p];

    ll ret1 = 0,ret2=0, ret;
    if(a[pos]>maxx){
        ret1 += w[pos]+fun(pos+1,a[pos]);
    }

    ret2 = fun(pos+1,maxx);

    ret = max(ret1,ret2);

    return dp[p]=ret;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%lld",&w[i]);
        }
        dp.clear();
        //vs.clear();
        ll ans = fun(0,0);

        printf("%lld\n",ans);
    }
    return 0;
}

