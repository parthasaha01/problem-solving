#include<bits/stdc++.h>
using namespace std;
#define mx 100000002
#define ll long long int
#define ui unsigned int
#define mod 4294967296LL
ui sum[5761460];
int prime[5761460];
int sz;
ll col[mx/64+10];
void sieve()
{
    ll i,j;
    for(i=3;i<mx;i+=2)
         if(!(col[i/64]&(1LL<<(i%64))))
                for(j=i*i;j<mx;j+=2*i)
                    col[j/64]|=(1LL<<(j%64));

    prime[sz++]=2;
    for (int i = 3; i<mx; i+=2)
        if(!(col[i/64]&(1LL<<(i%64))))
            prime[sz++] = i;
}
void summation()
{
    sum[0]=2;
    for(int i=1; i<sz; i++){
        sum[i]=sum[i-1]*prime[i];
    }
}
ll calculate(int n)
{
    int sq=sqrt(n);
    ui ans=1;
    for(int i=0; prime[i]<=sq; i++)
    {
        int x=n/prime[i];
        ui cnt=1;
        while(x>=prime[i])
        {
            x/=prime[i];
            cnt*=prime[i];
        }
        ans*=cnt;
    }

    int ub=upper_bound(prime, prime+sz, n)-prime;
    ans*=sum[ub-1];
    return ans;
}
int main()
{
    sieve();
    summation();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);
        ui ans=calculate(n);
        printf("Case %d: %u\n",ks,ans);
    }

    return 0;
}
