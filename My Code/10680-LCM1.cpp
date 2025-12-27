#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
#define ll long long int
#define mod 4294967296LL
bool vis[mx+3];
int sum[78500],prime[78500],p[78500];
int sz;
void sieve()
{
    prime[sz++]=2;
    for(ll i=3; i<=mx; i+=2){
        if(!vis[i]){
            prime[sz++]=i;
            for(ll j=i*i; j<=mx; j+=2*i){
                vis[j]=true;
            }
        }
    }

    swap(prime[1],prime[2]);
}
int calculate(int n)
{
    int ans=1;

    int c2=0,c5=0;
    for(int i=2; i<=n; i*=2){
        c2++;
    }
    for(int i=5; i<=n; i*=5){
        c5++;
    }
    for(int i=1; i<=c2-c5; i++){
        ans=(ans*2)%10;
    }

    //printf("ans=%d c2=%d c5=%d\n",ans,c2,c5);

    for(int i=2; prime[i]<=n && i<sz; i++)
    {
        int x=n;
        int cnt=1;

        while(x>=prime[i])
        {
            x/=prime[i];
            ans=(ans*prime[i])%10;
        }
    }

    return ans;
}
int main()
{
    sieve();

    int n;
    while(scanf("%d",&n)&&n)
    {
        int ans;
        if(n==1){
            ans=1;
        }
        else{
            ans=calculate(n);
        }

        printf("%d\n",ans);
    }

    return 0;
}
