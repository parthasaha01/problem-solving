#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[105];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        ll ans=0;
        ll sum=0;
        for(int i=0; i<n; i++){
            scanf("%lld",&a[i]);
            ans^=a[i];
            sum+=a[i];
        }

        if(sum==n){
            if(n%2==0) ans=1;
            else ans=0;
        }

        if(ans>0)
            printf("Case %d: Alice\n",ks);
        else
            printf("Case %d: Bob\n",ks);
    }

    return 0;
}
