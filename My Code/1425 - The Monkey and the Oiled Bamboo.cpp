#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1000000005
ll a[100005];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n;
        scanf("%lld",&n);
        a[0]=0;
        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
        }

        ll lo=1;
        ll hi=mx*n;
        ll ans;

        while(lo<=hi)
        {
            ll md=(lo+hi)/2;
            ll x=md;

            bool flag=true;
            for(int i=0; i<n; i++){
                ll d=abs(a[i+1]-a[i]);

                if(d>x){
                    flag=false;
                    break;
                }
                else if(d==x){
                    x--;
                }
            }

            if(!flag||x<0){
                lo=md+1;
            }
            else{
                ans=md;
                hi=md-1;
            }
        }

        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
