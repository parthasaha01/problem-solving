#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll l,r,x,y,k,a,b;
    cin>>l>>r>>x>>y>>k;

    for(ll b=x; b<=y; b++)
    {
        ll a = b*k;

        if(a>=l&&a<=r)
        {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;

}
