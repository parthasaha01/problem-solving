#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
int sum[mx+5],vis[mx+5],bad[mx+5];
void sieve()
{
    for(int i=1; i<=mx; i++)
    {
        int cnt = 0;
        int n = i;
        while(n!=0)
        {
            int r = n%10;
            if(r&1)cnt+=r;
            n/=10;
        }
        bad[i]=cnt;
    }

    for(int i=1; i<=mx; i++)
    {
        for(int j=i; j<=mx; j+=i)
        {
            sum[j]+=bad[i];
        }
    }
}
int main()
{
    sieve();
    int tt; scanf("%d",&tt);

    while(tt--)
    {
        int n; scanf("%d",&n);
        printf("%d\n",sum[n]);
    }
    return 0;
}
