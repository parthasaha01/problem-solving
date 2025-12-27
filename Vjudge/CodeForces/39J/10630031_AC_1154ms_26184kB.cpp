#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007LL
ll n,m,sum[1000005],st[1000005];
ll base=313;
string s,t;
vector<int>vv;
void fun()
{
    sum[0]=1;
    for(int i=1; i<=1000002; i++){
        sum[i] = ((sum[i-1]%MOD)*(base%MOD))%MOD;
    }
}
ll Hash()
{
    ll h=0;
    for(int i=0; i<m; i++)
    {
        h += s[i]*sum[i];
    }
    return h;
}
ll modInv(ll n)
{
    //Extended Euclidean Algorithm
    ll r2=n, r1=MOD;
    ll x2=1, y2=0;
    ll x1=0, y1=1;

    while(r1!=0)
    {
        ll q = r2/r1;
        ll r = r2%r1;
        ll x = x2-(q*x1);
        ll y = y2-(q*y1);

        r2=r1, r1=r;
        x2=x1, y2=y1;
        x1=x, y1=y;
    }

    ll x=x2%MOD;
    if (x<0) x+= MOD;
    return x;
}

int main()
{
    fun();

    cin>>s;
    cin>>t;

    n = s.size();
    m = t.size();

    ll ht=0;
    for(int i=0; i<t.size(); i++)
    {
        ht += ((t[i]%MOD)*(sum[i]%MOD))%MOD;
        ht %= MOD;
    }

    st[0] = (s[0]*sum[0])%MOD;
    for(int i=1; i<s.size(); i++)
    {
        st[i] = st[i-1]+((s[i]%MOD)*(sum[i]%MOD))%MOD;
        st[i]%=MOD;
    }

    //cout << "ht=" << ht << endl;

    ll baseinv = modInv(base);

    for(int i=0; i<s.size(); i++)
    {
        ll u;
        if(i==0)u=0;
        else u = st[i-1];

        u %= MOD;

        ll v = st[n-1]-st[i];

        if(v<0){
            v = (-1)*v;
            v %= MOD;
            if(v!=0)v=MOD-v;
        }
        else{
            v %= MOD;
        }

        v = ((v%MOD)*(baseinv%MOD))%MOD;

        u += v;

        u %= MOD;

        //cout <<"i=" << i+1 << " u="<<u << " v="<<v << endl;

        if(u==ht){
            vv.push_back(i+1);
        }

    }

    int res = vv.size();

    printf("%d\n",res);

    for(int i=0; i<res; i++)
    {
        if(i==res-1)printf("%d\n",vv[i]);
        else printf("%d ",vv[i]);
    }

    return 0;
}
