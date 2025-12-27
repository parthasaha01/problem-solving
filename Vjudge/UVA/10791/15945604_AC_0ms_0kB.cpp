#include<bits/stdc++.h>
using namespace std;
#define ll long long
int vis[46360];
vector<ll>pr;
void sieve()
{
    pr.push_back(2);
    for(ll i=3; i<=46350; i+=2){
        if(vis[i]==0){
            pr.push_back(i);
            for(ll j=i*i; j<=46350; j+=i+i){
                vis[j]=1;
            }
        }
    }
}
long long solve(ll n)
{
    //cout << "partha";
    ll ans = 0;
    ll m = n;
    int x = 0;
    for(int i=0; i<pr.size() && pr[i]*pr[i]<=n; i++){
        if(n%pr[i]==0){
            ll cnt=1;
            while(n%pr[i]==0){
                cnt *= pr[i];
                n /= pr[i];
            }
            //cout << cnt << " ";
            ans += cnt;
            x++;
        }
    }
    if(n>1 && n<m){
        ans+=n;
        x++;
    }
    //cout << n << " " << x << " " << ans << endl;
    if(n==m || x==1)ans = m+1LL;
   // cout << " = " << ans << endl;
    return ans;
}
int main()
{
    sieve();
    ll n;
    int ks=0;
    while(scanf("%lld",&n))
    {
        if(n==0)break;

        ll ans = solve(n);
        printf("Case %d: %lld\n",++ks,ans);
    }
    return 0;
}
