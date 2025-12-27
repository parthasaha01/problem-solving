#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[]={2,9};
int main()
{
    ll n;
    while(scanf("%lld",&n)==1)
    {
        int k=0;
        ll p=9;
        while(p<n)
        {
            p*=a[k];
            k=1-k;
        }

        if(k==0){
            printf("Stan wins.\n");
        }
        else{
            printf("Ollie wins.\n");
        }
    }

    return 0;
}

