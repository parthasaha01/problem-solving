#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 100000007
#define mx 5000000
int vis[mx+5],pr[mx+5],k;
int a[mx+5],ber[mx+5],frq[mx+5],ans[mx+5];
void sieve()
{
    for(int i=1; i<=mx; i++)vis[i]=i;
    for(int i=2; i<=mx; i+=2)vis[i]=2;
    pr[++k] = 2;
    for(ll i=3; i<=mx; i+=2){
        if(vis[i]==i){
            pr[++k]=i;
            for(ll j=i*i; j<=mx; j+=i+i){
                vis[j] = i;
            }
        }
    }
}
void factorize(int v)
{
    while(v>1)
    {
        frq[vis[v]]++;
        printf("v=%d p=%d f=%d\n",v,vis[v],frq[vis[v]]);
        v /= vis[v];
    }
}
void calculate(int v)
{
    ll sum = 1;
    for(int i=1; i<=k&&pr[i]<=v; i++)
    {
        ll ff = frq[pr[i]];
        sum *= (ff+1);
        sum %= MOD;
    }
    ans[v] = sum;
}
int main()
{
    sieve();

//    for(int i=1; i<=25; i++){
//        printf("%d ",pr[i]);
//    }
//    printf("\n");

    int n,cnt = 0;
    while(scanf("%d",&n))
    {
        if(n==0)break;
        a[++cnt] = n;
        ber[n]=1;
    }

    ans[1] = 1;

    for(int v=2; v<=4; v++)
    {
        factorize(v);
        if(ber[v]==1){
            cout << "v=" << v << endl;
            calculate(v);
        }
    }

    for(int i=1; i<=cnt; i++)
    {
        printf("%d\n",ans[a[i]]);
    }

    return 0;
}
