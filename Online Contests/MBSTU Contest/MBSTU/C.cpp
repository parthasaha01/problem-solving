#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll u,fu,v,fv,n;
ll x,fx,y,fy,k;
ll fun(ll md)
{
    ll f1,f2,f3;
    f1=fu; f2=md;

    if(v==u+1)return f2;

    for(ll i=u+2; i<=v; i++)
    {
        f3 = f1+f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}
ll getValue(ll u1,ll f1,ll u2,ll f2)
{
    if(u1==n)return f1;
    if(u2==n)return f2;

    if(n>u2)
    {
        ll f3;
        for(ll i=u2+1; i<=n; i++)
        {
            f3 = f1+f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
    else
    {
        ll f3;
        for(ll i=u1-1; i>=n; i--)
        {
            f3 = f2-f1;
            f2 = f1;
            f1 = f3;
        }
        return f3;
    }
}
int main()
{
    cin>>x>>fx>>y>>fy>>k;

    if(x==k){cout<<fx<<endl; return 0;}
    if(y==k){cout<<fy<<endl; return 0;}

    if(x<=y&&x<=k)
    {
        u=1;
        v=u+abs(x-y);
        n=u+abs(x-k);
        fu=fx; fv=fy;
    }
    else if(y<=x&&y<=k)
    {
        u=1;
        v=u+abs(y-x);
        n=u+abs(y-k);
        fu=fy; fv=fx;
    }
    else
    {
        if(x<=y)
        {
            n=1;
            u = n+abs(n-x);
            v = n+abs(n-y);
            fu=fx; fv=fy;
        }
        else
        {
            n=1;
            u = n+abs(n-y);
            v = n+abs(n-x);
            fu=fy; fv=fx;
        }
    }

    ll lo = -2000000000;
    ll hi =  2000000000;
    ll ans;

    //cout<<"u="<<u<<" fu="<<fu<<" v="<<v<<" fv="<<fv<<" n="<<n<<endl;

    while(lo<=hi)
    {

        ll md = (lo+hi)/2;
        ll pp = fun(md);
        //printf("partha md=%lld pp=%lld\n",md,pp);
        if(pp==fv)
        {
            //printf("partha pp=%lld\n",pp);
            ans = getValue(u,fu,u+1,md);
            break;
        }
        else if(pp>fv)
        {
            hi=md-1;
        }
        else
        {
            lo=md+1;
        }

    }

    cout << ans << endl;

    return 0;
}
