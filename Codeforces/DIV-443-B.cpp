#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[10005];
int main()
{
    scanf("%I64d %I64d",&n,&k);
    ll maxx = 0;
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        maxx = max(maxx,a[i]);
    }

    ll ans = 0;
    ll x = a[1];
    int flag = 0;
    ll cnt = 0;
    for(int i=2; i<=n; i++)
    {
        ll y = a[i];

        if(x>y)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
            x = y;
        }

        if(cnt==k)
        {
            ans = x;
            flag = 1;
            break;
        }
    }

    if(flag==0)
    {
        ans = maxx;
    }

    printf("%I64d\n",ans);

    return 0;
}
