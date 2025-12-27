#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000007
#define mx 1000002
ll a[mx+5];
bool sm[mx+5];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n,m;
        scanf("%lld%lld",&n,&m);

        ll p,q,r,x,y,z;
        scanf("%lld%lld%lld%lld%lld%lld",&p,&q,&r,&x,&y,&z);

        for(int i=1; i<=n; i++)
        {
            a[i]=p*i*i;
            a[i]%=mod;
            a[i]+=q*i;
            a[i]%=mod;
            a[i]+=r;
            a[i]%=mod;
        }
        memset(sm,false,sizeof(sm));
        for(int i=1; i<=m; i++)
        {
            ll si;
            si=x*i*i;
            si%=n;
            si+=y*i;
            si%=n;
            si+=z;
            si%=n;
            si+=1;
            sm[si]=true;
        }

        ll minn=9999999999;
        ll idx=0;
        for(int i=1; i<=n; i++){
            if(sm[i]==false && a[i]<minn){
                idx=i;
                minn=a[i];
            }
        }

        ll ans=0;
        a[idx]=0;
        for(int i=1; i<=n; i++){
            ans+=(minn*a[i]);
        }
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
