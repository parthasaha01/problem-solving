#include<bits/stdc++.h>
using namespace std;
#define mx 10000005
#define ll long long int
bool vis[mx+5];
vector<int>prime;
void sieve()
{
    for(int i=4; i<=mx; i+=2){
        vis[i]=true;
    }
    prime.push_back(2);
    for(ll i=3; i<=mx; i++){
        if(!vis[i]){
            prime.push_back(i);
            for(ll j=i*i; j<=mx; j+=i+i){
                vis[j]=true;
            }
        }
    }
}
int calculate(int n)
{
    int cnt=0;
    for(int i=0; 2*prime[i]<=n; i++)
    {
        int j=n-prime[i];
        if(vis[j]==false){
            cnt++;
        }
    }

    return cnt;
}
int main()
{
    sieve();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);
        int ans=calculate(n);
        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
