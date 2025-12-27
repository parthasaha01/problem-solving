#pragma comment(linker,"/STACK:2000000")
#pragma comment(linker,"/HEAP:2000000")

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10000005
bool prime[mx];
ll n,cnt;
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
}
void fun(ll pos, ll k, ll val)
{
    if(pos==vv.size()){
        if(k==0)return;  // this case(k==0) must be consider
        if(k%2==1)cnt += (n/val);
        else cnt -= (n/val);
        return;
    }
    ll can=(n/val); // don’t use if(val*vv[pos]<=n).it may cause overflow.
    if(vv[pos]<=can){
        fun(pos+1,k+1,val*vv[pos]);
        fun(pos+1,k,val);
    }
    else fun(vv.size(),k,val);
    return;
}
ll solve(){
    cnt=0;   // cnt holds how many numbers is not square free
    fun(0,0,1);
    return n-cnt;
}
int main()
{
    sieve();
    int t; scanf("%d",&t);
    for(int ks=1; ks<=t; ks++){
        scanf("%lld",&n);
        ll ans = solve();
        printf("%lld\n",ans);
    }
}


