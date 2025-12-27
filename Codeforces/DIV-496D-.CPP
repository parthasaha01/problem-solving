#include<bits/stdc++.h>
using namespace std;
int n,dp[200002][3];
string s;
int fun(int pos,int k)
{
   // cout << "pos="<<pos<<" k="<<k << endl;
    //getchar();
    if(pos==n){
        return 0;
    }

    if(dp[pos][k]!=-1)return dp[pos][k];

    int ret = 0;
    int v = s[pos]-'0';
    int x = (k+v)%3;

    if(v==0)ret = max(ret,1+fun(pos+1,0));
    if(x==0)ret = max(ret,1+fun(pos+1,0));
    ret = max(ret,fun(pos+1,x));
    ret = max(ret,fun(pos+1,0));

    return dp[pos][k] = ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    n = s.size();

    //cout << n << endl;
    memset(dp,-1,sizeof(dp));
    int ans = fun(0,0);
    cout << ans << endl;

   // main();
    return 0;
}
