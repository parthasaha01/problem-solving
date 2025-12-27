#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10000001
bool flag[mx+5];
int sum[mx+5];
void sieve()
{
    flag[0]=true;
    flag[1]=true;
    for(int i=4; i<=mx; i+=2)flag[i]=true;
    ll sq = sqrt(mx);
    for(ll i=3; i<=sq; i+=2){
        if(flag[i]==false){
            for(ll j=i*i; j<=mx; j+=(i+i)){
                flag[j]=true;
            }
        }
    }

    sum[0]=0;
    for(int i=0; i<=mx; i++){
        if(flag[i]==false){
            sum[i]=sum[i-1]+1;
        }
        else{
            sum[i]=sum[i-1];
        }
    }
}
int main()
{
    sieve();

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        printf("%d\n",sum[n-1]);
    }
    return 0;
}
