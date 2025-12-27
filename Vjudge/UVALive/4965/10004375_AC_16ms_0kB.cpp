#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll>pp,qq,ss;
vector<ll>vv,uu;
ll fun(ll n)
{
    ll ans = 0;
    while(n!=0)
    {
        ll r = n%10;
        ans += (r*r);
        n /= 10;
    }
    return ans;
}
ll calc(ll a,ll b)
{
    pp.clear();
    qq.clear();
    ss.clear();
    vv.clear();
    uu.clear();

    ll u;
    u=a;
    ll k=0;

    while(pp[u]==0)
    {
        vv.push_back(u);
        pp[u] = ++k;
        u = fun(u);
    }

    ll d = 0;
//

//        for(ll i=0; i<vv.size(); i++)
//        {
//            if(vv[i]==u){
//                d = vv.size()-i;
//                for(int j=i; j<vv.size(); j++){
//                    ss[vv[i]]=1;
//                }
//                break;
//            }
//        }

    bool flag=false;
    ll dd=0;
    ll v;
    v = b;
    ll x=0;

    while(qq[v]==0)
    {
        uu.push_back(v);
        qq[v] = ++x;
        if(pp[v]!=0)
        {
            flag=true;
            d = pp[v];
            dd = uu.size();
            break;
        }
        v = fun(v);
    }

    if(flag==false)return 0;
    return d+dd;
}
int main()
{
    ll a,b;
    while(scanf("%lld%lld",&a,&b))
    {
        if(a==0&&b==0)break;

        ll res1=calc(a,b);
        ll res2=calc(b,a);
        ll res = min(res1,res2);

        printf("%lld %lld %lld\n",a,b,res);
    }
    return 0;
}

