#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int flag[mx+5];
void sieve()
{
    for(int i=1; i<=mx; i++)flag[i]=1;
    for(int i=4; i<=mx; i+=2)flag[i]=2;
    int sq = sqrt(mx);
    for(ll i=3; i<=sq; i+=2)
    {
        if(flag[i]==1)
        {
            for(ll j=i*i; j<=mx; j+=2*i){
                flag[j] = 2;
            }
        }
    }
}
int main()
{
    sieve();

    int n;

    while(cin>>n)
    {

        if(n<3){
            printf("1\n");
            if(n==1)printf("1\n");
            else printf("1 1\n");
            continue;
        }

        printf("2\n");

        for(int i=2; i<=n; i++)
        {
            printf("%d ",flag[i]);
        }
        printf("%d\n",flag[n+1]);
    }

    return 0;
}
