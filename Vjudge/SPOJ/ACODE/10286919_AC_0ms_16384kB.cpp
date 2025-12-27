#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll dp[5005];
int ls;
ll fun(int pos)
{
    if(pos>=ls)return 1LL;
    if(s[pos]=='0')return 0LL;

    if(dp[pos]!=-1)return dp[pos];

    ll ret = 0;

    if(pos==ls-1)
    {
        ret += fun(pos+1);
    }
    else
    {
        ret += fun(pos+1);
        int v = ((s[pos]-'0')*10)+(s[pos+1]-'0');
        if(v<=26){
            ret += fun(pos+2);
        }
    }

    return dp[pos] = ret;
}
int main()
{
    while(cin>>s)
    {
        if(s=="0")break;

        ls = s.size();

        memset(dp,-1,sizeof(dp));

        ll ans = fun(0);

        cout << ans << endl;
    }

    return 0;
}
