#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000005
ll phi[mx+5],sum[mx+5];
void EulerPhi()
{
    for(int i=2; i<=mx; i++)phi[i]=i;

    for(int i=2; i<=mx; i++){
        if(phi[i]==i){
            phi[i] = i-1;
            for(int j=i+i; j<=mx; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }

    for(int i=1; i<=mx; i++)
        sum[i]=sum[i-1]+phi[i];
}
int main()
{
    EulerPhi();

    int n;
    while(scanf("%d",&n) && n)
    {
        printf("%lld\n",sum[n]);
    }
    return 0;
}
