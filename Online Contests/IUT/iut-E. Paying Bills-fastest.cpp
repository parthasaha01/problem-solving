#include <bits/stdc++.h>
using namespace std;

const int mx = 1 << 15;
const int INF = 34;

int maskMx, n, m;
map < int, map < int, int > > dp[17];
map < int, map < int, int > > vp[17];
int coin[20];
int bill[20];

int solve (int shp, int mask, int bl)
{
    int i, cns;
    int ret = 0;
    if (shp <= 0)
    {
        for (i = 0; i < n; i++)
        {
            if (!( mask & ( 1 << i ) ))
            {
                ret++;
            }
        }
        return ret;
    }

    if( mask == maskMx ) return -INF;

    if (vp[shp][mask][bl] == 1) return dp[shp][mask][bl];

    vp[shp][mask][bl] = 1;
    ret = -INF;

    for (i = 0; i < n; i++)
    {
        if (!( mask & ( 1 << i ) ) && coin[i] <= bl )
        {
            cns = bl - coin[i];
            cns = max (cns, 0);
            if (cns == 0)
            {
                ret = max (ret, solve (shp-1, mask | (1 << i), bill[shp - 1]));
            }
            else
            {
                ret = max (ret, solve (shp, mask | (1 << i), cns));
            }
        }
    }
    return dp[shp][mask][bl] = ret;
}

int main()
{
    int t, i, j, cs = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &coin[i]);
        }
        scanf("%d", &m);
        for (i = 1; i <= m; i++)
        {
            scanf("%d", &bill[i]);
        }
        maskMx = (1 << n) - 1;
        for( int i=0; i<17; i++ )
        {
            dp[i].clear();
            vp[i].clear();
        }
        int ans = solve (m, 0, bill[m]);
        if (ans == -INF) ans = -1;
        else ans = n - ans;
        printf ("Case %d: %d\n", ++cs, ans);
    }
    return 0;
}
