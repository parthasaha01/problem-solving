#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[5005];
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        priority_queue<ll>pp;

        for(int i=1; i<=n; i++)
        {
            ll v = a[i];
            v = -v;
            pp.push(v);
        }

        ll ans=0;

        while(!pp.empty())
        {
            ll x = pp.top();
            pp.pop();

            if(pp.empty()==true)
            {
                break;
            }

            ll y = pp.top();
            pp.pop();

            x = -x;
            y = -y;

            ll v = (x+y);
            ans += v;
            v = -v;
            pp.push(v);
        }

        printf("%lld\n",ans);
    }
    return 0;
}

