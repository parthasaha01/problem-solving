#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx],b[mx];
ll n,s,tt,ansk,anst;
bool possible(ll x)
{
    for(int i=1; i<=n; i++){
        b[i] = a[i] + (i*x);
    }

    sort(b+1,b+n+1);

    tt = 0;
    ll cnt=0;

    for(int i=1; i<=n; i++)
    {
        if(tt+b[i]<=s)
        {
            cnt++;
            tt += b[i];

            if(cnt==x)break;
        }
        else
        {
            break;
        }
    }

    if(cnt>=x)return true;
    else return false;
}
int main()
{
    scanf("%I64d",&n);
    scanf("%I64d",&s);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        b[i] = a[i];
    }

    ll lo=1;
    ll hi=n;
    ansk = 0;
    anst = 0;

    while(lo<=hi)
    {
        ll md = (lo+hi)/2;

        bool flag = possible(md);

        if(flag==true)
        {
            ansk = md;
            anst = tt;

            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }

    printf("%I64d %I64d\n",ansk,anst);

    return 0;
}
