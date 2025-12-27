#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll n,m,k;
ll BinarySearch(ll v)
{
    ll sl,sr;
    if(k==1) sl=0;
    else{
        ll so = (v*(v+1))/2;
        ll kk;
        ll d = 0;
        if(v>=k-1) kk=v-k+1;
        else{
            kk = 0;
            d = k-v;
        }

        ll st = (kk*(kk+1))/2L;
        sl = so-st+d;
    }

    if(k==n)sr=0;
    else{
        ll so = (v*(v+1))/2L;
        ll kr = n-k;
        ll d = 0;
        ll kk;
        if(v>=kr)kk=v-kr;
        else{
            kk = 0;
            d = kr-v;
        }
        ll st = (kk*(kk+1))/2;
        sr = so-st+d;
    }

    ll sum = sl+(v+1)+sr;
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
            ll flag = BinarySearch(md-1);

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
