#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool flag[1000005];
void sieve()
{
    flag[1]=true;
    for(int i=4; i<=1000005; i+=2)flag[i]=true;
    for(ll i=3; i<=1001; i+=2){
        if(!flag[i]){
            for(ll j=i*i; j<=1000005; j+=i+i){
                flag[j]=true;
            }
        }
    }
}
int main()
{
    sieve();
    int t; scanf("%d\n",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n; scanf("%d",&n);

        if(flag[n])printf("%d is not a prime number.\n",n);
        else printf("%d is a prime number.\n",n);
    }
    return 0;
}
