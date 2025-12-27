#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000LL
ll a[200005];
struct dt{
    ll f,s;
}vv[200005];
//vector< pair<ll,ll> >vv[2];
int main()
{
    ll n; scanf("%I64d",&n);
    ll maxx = 0;

    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        maxx = max(maxx,a[i]);
    }

    if(n==1){
        printf("YES\n");
        printf("%I64d %I64d\n",1LL,a[1]);
        return 0;
    }

    bool flag = true;
    ll d = 1;
    ll k = 0;

    for(int i=1; i<n; i++)
    {
        ll x = a[i];
        ll y = a[i+1];
        if(x>y)swap(x,y);

        if(x==y){
            flag = false;
            break;
        }

        dt p;
        p.f = x;
        p.s = y;
        if(y==x+1){
            vv[++k] = p;
        }
        else{

            if(d!=1){
                ll temp = y-x;
                if(temp!=d){
                    flag = false;
                    break;
                }
            }

            if(d==1) d = y-x;

            //vv[1].push_back(p);
        }
    }

    if(flag==false){
        printf("NO\n");
        return 0;
    }

    ll y = d;
    ll x;

    if(d==1){
        printf("YES\n");
        printf("%I64d %I64d\n",1LL,maxx);
        return 0;
    }

    for(int i=1; i<=k; i++)
    {
        ll u,v;
        u = vv[i].f;
        v = vv[i].s;

        if(u%y==0){
            flag = false;
            break;
        }
    }

    if(flag==false){
        printf("NO\n");
        return 0;
    }

    if(maxx%y==0){
        x = (maxx/y);
    }
    else{
        x = (maxx/y)+1;
    }

    if(x>inf || y>inf){
        printf("NO\n");
        return 0;
    }
    else{
        printf("YES\n");
        printf("%I64d %I64d\n",x,y);
        return 0;
    }

    return 0;
}
