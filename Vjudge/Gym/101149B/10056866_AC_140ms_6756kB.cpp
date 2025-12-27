#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dt
{
    ll a,b,d;
}st[200005];
bool cmp(dt x, dt y)
{
    return x.d>y.d;
}
int main()
{
    int n;

    while(cin>>n)
    {
        for(int i=1; i<=n; i++)
        {
            ll a,b,d;
            scanf("%I64d%I64d",&a,&b);
            st[i].a=a;
            st[i].b=b;
            st[i].d=a-b;
        }

        sort(st+1,st+n+1,cmp);

        ll pr = 0;
        ll ans = 0;
        for(int i=1; i<=n; i++)
        {
            int nd = st[i].a;
            if(pr<nd){
                ans += (nd-pr);
                pr = nd;
            }

            pr = pr-st[i].b;
        }

        cout << ans << endl;
    }

    return 0;
}