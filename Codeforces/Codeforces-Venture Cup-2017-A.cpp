#include<bits/stdc++.h>
using namespace std;
#define mx 1000010
int a[mx+5];
void sieve()
{
    a[1]=1;
    for(int i=2; i<=mx; i++){
        if(a[i]==0){
            for(int j=i+i; j<=mx; j+=i){
                a[j]=1;
            }
        }
    }
}
int main()
{
    sieve();
    int n;
    while(scanf("%d",&n)==1)
    {
        int v=-1;
        for(int i=1; i<=1000; i++){
            int p = (n*i)+1;
            if(a[p]==1){
                v=i;
                break;
            }
        }

        printf("%d\n",v);
    }

    return 0;
}
