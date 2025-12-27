#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000
int ara[20002];
int n, K;
ll dp[20002][12];

ll fun(int pos, int k)
{
    //cout << pos << " " << k << endl;
    //getchar();


    if(k == K)
    {
        return 1;
    }
    if(pos > n) return 0;


    if(dp[pos][k] != -1)
        return dp[pos][k];

    ll p1 = 0;
    for(int i = pos + 1; i <= n; i++)
    {
        if(ara[pos] > ara[i])
        {
           p1 += fun(i , k + 1)%mod;
        }
    }

    //p2 += fun(pos + 1, k);

    //ll ans = ((p1 % mod) + (p2 % mod) )% mod;
    return dp[pos][k] = p1%mod;
}

int main()
{

    scanf("%d %d",&n, &K);
    ara[0]=n+5;
    for(int i = 1; i <= n; i++){
        scanf("%d",&ara[i]);
    }

    memset(dp, -1, sizeof(dp));

    //printf("fgjdfhj\n");
    ll ans = fun(0, 0);

    printf("%lld\n",ans);
}
