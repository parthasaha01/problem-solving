#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[1005];
int main()
{
    ll n,a,b,c,t;
    scanf("%I64d %I64d %I64d %I64d %I64d",&n,&a,&b,&c,&t);
    for(int i=1; i<=n; i++){
        scanf("%I64d",&ar[i]);
    }

    sort(ar+1,ar+n+1);

    ll ans = 0;

    if(b==c)
    {
        ans = (a*n);
    }
    else if(b<c)
    {
        ll d = c-b;
        for(int i=1; i<=n; i++){
            ans += a+(d*(t-ar[i]));
        }

    }
    else
    {
        ans = (a*n);
    }

    printf("%I64d\n",ans);

    //main();

    return 0;
}
