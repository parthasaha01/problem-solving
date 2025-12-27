#pragma comment(linker,"/STACK:2000000")
#pragma comment(linker,"/HEAP:2000000")

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10000005
bool prime[mx];
ll n,sz,cnt,mm,sn;
vector<ll>vv;
void sieve()
{
    vv.push_back(4);
    for(ll i=3; i<=10000000; i+=2){
        if(prime[i]==false){
            vv.push_back(i*i);
            for(ll j=i*i; j<=10000000; j+=i+i){
                prime[j]=true;
            }
        }
    }

    sz = vv.size();
}
void fun(ll pos, ll k, ll val)
{
    if(pos==sz){
        if(k==0)return;
        if(k%2==1)cnt += (n/val);
        else cnt -= (n/val);
        return;
    }

    ll can = (n/val);

    if(vv[pos]<=can){
        fun(pos+1,k+1,val*vv[pos]);
        fun(pos+1,k,val);
    }
    else{
        fun(sz,k,val);
    }

    return;
}
ll solve()
{
    cnt=0;
    fun(0,0,1);
    return n-cnt;
}
int main()
{
    sieve();
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%lld",&n);
        sn = sqrt(n);
        ll ans = solve();
        printf("%lld\n",ans);
    }
    return 0;
}
