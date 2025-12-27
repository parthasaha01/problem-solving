#include<bits/stdc++.h>
using namespace std;
#define mx 5000002
#define ll unsigned long long int
ll phi[mx+2];
bool isprime[mx+2];
void totientPhi()
{
    for(int i=2; i<=mx; i++){
        phi[i]=i;
    }

    for(int i=2; i<=mx; i++){
        if(!isprime[i]){`
            phi[i]=i-1;
            for(int j=i+i; j<=mx; j+=i){
                phi[j]=phi[j]-(phi[j]/i);
                isprime[j]=true;
            }
        }
    }

    for(int i=2; i<=mx; i++){
        phi[i]=phi[i-1]+(phi[i]*phi[i]);
    }
}
int main()
{
    totientPhi();

    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ll ans=phi[b]-phi[a-1];
        printf("Case %d: %llu\n",kase,ans);
    }

    return 0;
}

/*
8
6 6
8 8
2 20
2 5000000
5000000 5000000
4000000 5000000
4999999 5000000
4999999 4999999
*/
