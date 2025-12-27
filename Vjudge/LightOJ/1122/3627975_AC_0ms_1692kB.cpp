#include<bits/stdc++.h>

#define in1(a) scanf("%lld",&a)
#define in2(a,b) scanf("%lld %lld",&a,&b)
#define in3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

#define out1(a) printf("%lld",a)
#define out2(a,b) printf("%lld %lld",a,b)
#define out3(a,b,c) printf("%lld %lld %lld",a,b,c)

#define loop(a,b) for(ll i=a; i<b; i++)

#define lcm(a,b) a*b/__gcd(a,b)
#define mset(a,x) memset(a,x,sizeof a)
#define mod 100000007

typedef long long ll;

using namespace std;

ll m,n,ar[15],dp[15][15];

bool chk_diff(ll a, ll b)
{
    if(a<b) swap(a,b);
    if(a-b<=2) return 1;
    return 0;
}

ll call(ll pos, ll digit)
{
    if(n==pos) return 1;
    if(dp[pos][digit]!=-1) return dp[pos][digit];

    ll ret = 0;
    for(ll i=0; i<m; i++) if(chk_diff(digit,ar[i])) ret += call(pos+1,ar[i]);
    return dp[pos][digit] = ret;
}

int main()
{
    ll t,kase=0;
    in1(t);
    while(t--)
    {
        in2(m,n);
        for(ll i=0; i<m; i++) in1(ar[i]);

        ll ans = 0; mset(dp,-1);
        for(ll i=0; i<m; i++) ans += call(1,ar[i]);

        printf("Case %lld: %lld\n",++kase,ans);
    }
}
