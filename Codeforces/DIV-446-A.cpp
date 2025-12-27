#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx+5],b[mx+5];
int main()
{
    ll n;
    scanf("%lld",&n);

    ll sum=0;
    for(int i=1; i<=n; i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(int i=1; i<=n; i++){
        scanf("%lld",&b[i]);
    }

    sort(b+1,b+n+1);

    ll cap = b[n]+b[n-1];

    if(sum<=cap){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

   // main();

    return 0;

}
