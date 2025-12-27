#include <bits/stdc++.h>
using namespace std;
map < int, map < int, map<int,int> > > dp;
int coin[17],bill[17],Mxmask, n, m;
int solve (int shop, int mask, int val)
{
    if (shop == 0){
        int cnt=0;
        for (int i = 0; i < n; i++){
            if (( mask & ( 1 << i ))) cnt++;
        }
        return cnt;
    }

    if( mask == Mxmask ) return 23;

    if (dp[shop][mask][val] != 0) return dp[shop][mask][val];

    int ret = 23;

    for (int i = 0; i < n; i++){
        if (!( mask & ( 1 << i ) ) && coin[i] <= val ){
            int rem = val - coin[i];
            if (rem == 0)
                ret = min (ret, solve (shop-1, mask | (1 << i), bill[shop - 1]));
            else
                ret = min (ret, solve (shop, mask | (1 << i), rem));
        }
    }
    return dp[shop][mask][val] = ret;
}

int main()
{
    int t; scanf("%d", &t);
    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)scanf("%d", &coin[i]);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)scanf("%d", &bill[i]);
        Mxmask = (1 << n) - 1;

        dp.clear();

        int ans = solve (m, 0, bill[m]);
        if (ans>n) ans = -1;
        printf ("Case %d: %d\n", ks, ans);
    }
    return 0;
}

