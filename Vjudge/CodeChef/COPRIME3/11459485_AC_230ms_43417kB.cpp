#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005],d[1000005],mob[1000005],vis[1000005],c[100005][4];
void mobius()
{
    for(int i=1; i<=1000000; i++)mob[i]=1;
    for(ll i=2; i<=1000000; i++)
    {
        if(vis[i]==0)
        {
            mob[i]=-1;
            for(ll j=i+i; j<=1000000; j+=i)
            {
                if(j%(i*i)==0)mob[j]=0;
                mob[j] *= (-1);
                vis[j]=1;
            }
        }
    }
}
void nCr()
{
    c[0][3]=c[1][3]=c[2][3]=0;
    for(ll i=3; i<=100000; i++)
    {
        ll v = (i*(i-1)*(i-2))/ (1*2*3);
        c[i][3]=v;
    }
}
int main()
{
    mobius();
    nCr();

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
