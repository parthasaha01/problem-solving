#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll n,m,k;
ll BinarySearch(ll v)
{
    ll sum = v;
    ll lf = k-1;
    ll rg = n-k;
    ll vv = v-1;
    ll xx = (vv*(vv+1))/2;

    if(lf<=vv){
        sum += xx;
        ll p = vv-lf;
        ll q = (p*(p+1))/2;
        sum -= q;
    }
    else{
        sum += xx;
        sum += lf-vv;
    }

    if(rg<=vv){
        sum += xx;
        ll p = vv-rg;
        ll q = (p*(p+1))/2;
        sum -= q;
    }
    else{
        sum += xx;
        sum += rg-vv;
    }
    if(sum<=m)return 1;
    else return 0;
}
int main()
{
    while(cin>>n>>m>>k)
    {
        ll lo=1;
        ll hi=m;
        ll ans = 1;

        while(lo<=hi)
        {
            ll md = (lo+hi)/2;
            ll flag = BinarySearch(md);

            if(flag==1){
                ans = md;
                lo = md+1;
            }
            else{
                hi = md-1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
