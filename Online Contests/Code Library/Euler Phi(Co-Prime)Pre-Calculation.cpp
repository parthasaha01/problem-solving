#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
int phi[mx+2];
bool isprime[mx+2];
void totientPhi()
{
    for(int i=2; i<=mx; i++) phi[i]=i;

    for(int i=2; i<=mx; i++)
    {
        if(!isprime[i])
        {
            phi[i]=i-1;
            for(int j=i+i; j<=mx; j+=i)
            {
                phi[j]=phi[j]-(phi[j]/i);
                isprime[j]=true;
            }
        }
    }
}
int main()
{
    totientPhi();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",phi[n]);
    }
    return 0;
}
