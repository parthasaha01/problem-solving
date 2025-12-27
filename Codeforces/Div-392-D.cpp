#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000005LL
string k;
ll n,sz;
ll dp[65][65];
ll calc(int pos,int ln,int pw)
{
    ll v = 0;

}
ll fun(int pos,int pw,ll v)
{
    if(pos==sz)return 0;
    if(dp[pos][sz]!=-1)return dp[pos][sz];

    int lo=1,hi=sz-pos+1;

    ll ans = inf;
    for(int i=lo; i<=hi; i++){
        ll uu = calc(pos,i,pw);
        fun(pos+i,pw+1,)
    }

    return dp[pos][pw] = ans;
}
int main()
{
    while(cin>>n>>k)
    {
        sz = k.size();
        reverse(k.begin(),k.end());
        ll ans = fun(0,0,0);
    }

    return 0;
}
