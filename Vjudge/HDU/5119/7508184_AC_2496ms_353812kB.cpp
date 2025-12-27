#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define D double
#define pb push_back
#define mp make_pair
#define sf scanf
#define pf printf
#define ff first
#define ss second
#define SZ 1000005
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define FastIO ios_base::sync_with_stdio(0)
const int inf = 0x7f7f7f7f;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};
//int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};

LL n, m;
LL a[45];
LL dp[45][SZ];

LL fun(int pos, LL sum)
{
    if(pos>=n)
    {
        if(sum>=m) return 1;
        return 0;
    }

    if(dp[pos][sum]!=-1LL) return dp[pos][sum];

    LL ret1 = 0, ret2 = 0;
    ret1 = fun(pos+1, sum^a[pos]);
    ret2 = fun(pos+1, sum);

    return dp[pos][sum] = ret1 + ret2;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //FastIO;

    int t, ks = 0; sf("%d", &t);
    while(t--) {
        sf("%lld %lld", &n, &m);

        for(int i=0; i<n; i++) {
            sf("%lld", &a[i]);
        }

        mem(dp, -1);

        LL ans = fun(0,0);

        pf("Case #%d: %lld\n", ++ks, ans);
    }

    //main();
    return 0;
}

