#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        priority_queue<ll>pp;

        for(int i=1; i<=n; i++)
        {
            ll v = -i;
            pp.push(v);
        }

        ll ans=0;

//        if(n==1){
//            printf("1\n");
//            continue;
//        }
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
