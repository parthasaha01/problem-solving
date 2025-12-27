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
#define SZ 100005
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define FastIO ios_base::sync_with_stdio(0)
const int inf = 0x7f7f7f7f;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};
int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};


LL fun(LL n)
{
    if(n==0) return 0;
    return fun(n/2LL)+(n%2);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //FastIO;
    int t; sf("%d", &t);
    while(t--) {
        LL n; sf("%lld", &n);
        LL ans = fun(n);
        printf("%lld\n", ans);
    }

    //main();
    return 0;
}

