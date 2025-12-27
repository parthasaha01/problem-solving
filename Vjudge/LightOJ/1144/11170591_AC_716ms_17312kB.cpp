#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mob[1000005],vis[1000005];
void mobius()
{
    for(int i=1; i<=1000000; i++)mob[i]=1;

    mob[1]=1;
    for(ll i=2; i<=1000000; i++)
    {
        if(vis[i]==0)
        {
            mob[i]=-1;
            for(ll j=i+i; j<=1000000; j+=i)
            {
                if(j%(i*i)==0)mob[j]=0;
                mob[j] *= (-1);
                vis[j]=1;
            }
        }
    }
}
ll solve(ll n,ll m)
{
    ll ans=n*m;
    for(ll g=2; g<=n; g++)
    {
        ans += mob[g]*((n/g) * (m/g));
    }

    ans += 2;
    return ans;
}
int main()
{
    mobius();
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n,m; scanf("%lld%lld",&n,&m);
        if(n>m)swap(n,m);

        ll ans;
        if(n==0 && m==0)ans=0;
        else if(n==0 || m==0)ans=1;
        else ans = solve(n,m);

        printf("Case %d: %lld\n",ks,ans);
    }
    return 0;
}
