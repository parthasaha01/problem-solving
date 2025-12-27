#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll factorFive(ll n)
{
    ll cnt=0;

    for(ll i=5; n/i>=1; i*=5){
        cnt+=(n/i);
    }

    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll q;
        scanf("%lld",&q);

        ll lb=1;
        ll hb=999999999;

        bool flag=false;
        ll ans=0;
        while(lb<=hb)
        {
            ll mid=(lb+hb)/2;
            ll val=mid*5;
            ll cnt=factorFive(val);

            if(cnt==q){
                flag=true;
                ans=val;
                break;
            }
            else if(cnt>q){
                hb=mid-1;
            }
            else{
                lb=mid+1;
            }
        }

        if(flag)
            printf("Case %d: %lld\n",ks,ans);
        else
            printf("Case %d: impossible\n",ks);
    }

    return 0;
}

