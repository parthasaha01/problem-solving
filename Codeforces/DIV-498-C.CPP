#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define ll long long
ll n,a[mx],sum[mx],rev[mx];
int possible(int l, int r,ll v)
{
    if(r>n)return 0;
    if(l>n)return 0;

    int lo=l, hi=r;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(rev[md]==v){
            return 1;
        }
        else if(rev[md]>v){
            lo=md+1;
        }
        else{
            hi = md-1;
        }
    }
    return 0;
}
ll solve()
{
    ll tot = 0;
    sum[0]=0;
    for(int i=1; i<=n; i++){
        sum[i]=sum[i-1]+a[i];
        tot+=a[i];
    }
    sum[n+1]=sum[n];

    rev[n+1]=0;
    for(int i=n; i>=1; i--){
        rev[i]=rev[i+1]+a[i];
    }
    rev[0]=rev[1];

    ll each = tot/2;
    int k = 0;
    for(int i=1; i<=n; i++){
        if(sum[i]>each)break;
        k=i;
    }

    for(int i=k; i>=1; i--){
        ll v = sum[i];
        if(possible(k+1,n,v)){
            return v;
        }
    }

    return 0;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];

    ll ans = solve();
    cout<<ans<<endl;
   // main();

    return 0;
}

