#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll length(ll nd)
{
    ll lg = (ll)log2(nd);
    ll len =  1LL<<(lg+1);

    return len-1;
}
ll fun(ll nd,ll lf,ll rg)
{
    if(nd<2){
        return nd;
    }

    ll len = length(nd);

    if(len==rg-lf+1)return nd;

    ll ret,ret1,ret2;
    ret = ret1 = ret2 = 0;

    ll ln = length(nd/2);

    if(rg<=ln){
        ret1 = fun(nd/2,lf,min(rg,ln));
    }
    else if(lf>=ln+2){
        ret2 = fun(nd/2,lf-(ln+1),rg-(ln+1));
    }
    else{
        if(lf<=ln)ret1 = fun(nd/2,lf,ln);
        if(rg>ln+1)ret2 = fun(nd/2,1,rg-(ln+1));
        ret  = (nd&1);
    }

    return ret1 + ret + ret2;
}
int main()
{
    ll n,l,r;
    while(cin>>n>>l>>r)
    {
        if(n<2){
            cout << n << endl;
            continue;
        }

        ll ans = fun(n,l,r);

        cout << ans << endl;
    }

    return 0;
}
