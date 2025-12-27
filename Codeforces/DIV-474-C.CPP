#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vv;
vector<ll>ans;
void fun(ll x)
{
    ll p = log2(x)+1;
    vv.clear();
    for(ll i=p; i>=0; i--)
    {
        ll v = (1LL<<i);
        if(v<=x)
        {
            if(i!=0)vv.push_back(i);
            vv.push_back(1);
            x-=v;
        }
    }
}
int main()
{
    ll x,d;
    while(scanf("%I64d %I64d",&x,&d)==2)
    {
        fun(x);

//        for(int i=0; i<vv.size(); i++){
//            printf("%lld ",vv[i]);
//        }
//        printf("\n");
        ans.clear();
        ll cur = 1;
        for(int i=0; i<vv.size(); i++)
        {
            for(int k=1; k<=vv[i]; k++)
            {
                ans.push_back(cur);
            }
            cur += (d+25);
        }

        ll n = ans.size();
        printf("%I64d\n",n);
        for(int i=0; i<n; i++){
            if(i==n-1)printf("%I64d\n",ans[i]);
            else printf("%I64d ",ans[i]);
        }
    }

    return 0;
}
