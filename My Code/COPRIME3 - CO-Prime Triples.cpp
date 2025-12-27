#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000002
ll a[mx+5],d[mx+5],mob[mx+5],vis[mx+5],c[mx+5][4];
int main()
{
    for(int i=1; i<=mx; i++)mob[i]=1;
    for(ll i=2; i<=mx; i++)
    {
        if(vis[i]==0)
        {
            mob[i]=-1;
            for(ll j=i+i; j<=mx; j+=i)
            {
                if(j%(i*i)==0)mob[j]=0;
                mob[j] *= (-1);
                vis[j]=1;
            }
        }
    }

    c[0][3]=c[1][3]=c[2][3]=0;
    for(ll i=3; i<=100000; i++)
    {
        ll v = (i*(i-1)*(i-2))/ (1*2*3);
        c[i][3]=v;
    }

    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)scanf("%lld",&a[i]);

    for(int i=1; i<=n; i++)
    {
        int v = a[i];
        for(int j=1; j*j<=v; j++)
        {
            if(v%j==0)
            {
                d[j]++;
                if(j!=(v/j))d[v/j]++;
            }
        }
    }

    ll ans = c[n][3];

    for(int i=2; i<=1000000; i++)
    {
        ans += (mob[i]*c[d[i]][3]);
    }

    printf("%lld\n",ans);

    return 0;
}

