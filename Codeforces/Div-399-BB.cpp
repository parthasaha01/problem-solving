#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lenth(ll nd)
{
    ll lg = (ll)log2(nd);
    ll len =  1LL<<(lg+1);

    return len-1;
}
ll fun(ll nd,ll b, ll e,ll lf,ll rg)
{
    if(lf>rg)return 0LL;

    ll md = (b+e)/2;

    if(rg<md){
        return fun(nd/2,b,md-1,lf,rg);
    }
    else if(lf>md){
        return fun(nd/2,md+1,e,lf,rg);
    }
    else{
        ll xx = fun(nd/2,b,md-1,lf,md-1);
        ll yy = fun(nd/2,md+1,e,md+1,rg);

        return xx + (nd&1) + yy;
    }
}
int main()
{
    ll n,lf,rg;
    while(cin>>n>>lf>>rg)
    {
        if(n<2){
            cout << n << endl;
            continue;
        }

        ll ln = lenth(n);

        if(lf>rg)swap(lf,rg);

        ll ans = fun(n,1,ln,lf,rg);

        cout << ans << endl;
    }

    return 0;
}


