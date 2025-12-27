#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector<ll>vec;
    ll n,m;
    map<ll,ll>mp;
    mp[1] = 1;
    mp[10] = 2;
    mp[100] = 3;
    mp[1000] = 4;
    mp[10000] = 5;
    vec.push_back(1);
    vec.push_back(10);
    vec.push_back(100);
    vec.push_back(1000);
    vec.push_back(10000);
//    ll n,m;
    while(scanf("%lld%lld",&n,&m)==2)
    {
        ll s = 0;
        ll b,sum=0;
        ll res = 0,val=0,x;
        for(int i=0; i<m; i++)
        {
            scanf("%lld",&b);
            scanf("%lld",&val);
            sum=+val;

            for(int j=0; j<n-1; j++)
            {
                scanf("%lld",&x);
                sum+=x;
            }
            ll mx = 0;
            if(sum<=b)
            {
                s+=val;
                ll pos = mp[val];
                sum-=val;
                for(int k=pos; k<vec.size(); k++)
                {
                    x = vec[k];
                    sum+=x;
                    if(sum>b)
                        break;
                    ll y = x - val;
                    mx = max(y,mx);
                    sum-=x;
                }
            }
            else
            {
                ll pos = mp[val];
                sum-=val;
                for(int k=pos-2; k>=0; k--)
                {
                    x = vec[k];
                    sum+=x;
                    if(sum>b)
                       {
                           sum-=x;
                           continue;
                       }
                    ll y = x ;
                    mx = max(y,mx);
                    sum-=x;
                }
            }
            res+=mx;
        }
        cout<<res<<endl;
    }
    return 0;
}
