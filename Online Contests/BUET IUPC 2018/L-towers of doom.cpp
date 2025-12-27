#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],h[105],s[15],lcm[1<<13];

int LCM(int mask)
{
    int L = 1;
    for(int i=0; i<m; i++){
        if(mask&(1<<i)){
            int G = __gcd(L,s[i]);
            L = (L*s[i])/G;
        }
    }
    return L;
}
int solve(int x)
{
    int cnt = 0;
    for(int mask=1; mask<(1<<m); mask++){
        int bit = __builtin_popcount(mask);
        if(bit&1) cnt += (x/lcm[mask]);
        else cnt -= (x/lcm[mask]);
    }
    return cnt;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&m);

        for(int i=0; i<n; i++){
            scanf("%d",&h[i]);
        }

        for(int i=0; i<m; i++){
            scanf("%d",&s[i]);
        }

        for(int mask=1; mask<(1<<m); mask++){
            lcm[mask] = LCM(mask);
        }

        for(int i=0; i<n; i++){
            a[i] = solve(h[i]);
            a[i] += 1; // for zero
        }

        int xxor = 0;
        for(int i=0; i<n; i++){
            xxor ^= a[i];
        }

        if(xxor>0)printf("Case %d: Alice\n",ks);
        else printf("Case %d: Bob\n",ks);
    }
    return 0;
}
