#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll dp[70][70];
ll fun(int i,int j)
{
    if(i==j)return 1;
    if(i>j)return 0;

    ll &ret = dp[i][j];
    if(ret!=-1)return ret;

    //if(s[i]==s[j]) ret= (1+fun(i+1,j-1)) + fun(i+1,j)+fun(i,j-1)-fun(i+1,j-1);
    if(s[i]==s[j]) ret = 1 + fun(i+1,j) + fun(i,j-1);
    else ret = fun(i+1,j) + fun(i,j-1) - fun(i+1,j-1);

    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cin>>s;
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        ll ans = fun(0,n-1);
        cout<<"Case "<<ks<<": "<<ans<<endl;
    }
    return 0;
}
/*
If there is just one character in the string, it's a palindrome.
If there are more characters left in the string, you can
remove character from left fun(i+1, j) or right fun(i, j-1).
But in both recursions you will count fun(i+1, j-1).
To avoid counting twice, we subtract it from ret.
There is only one case left: when s[i] == s[j],
you can keep both characters (do not remove them) and
then you should call fun(i+1, j-1) to build the middle and
we add one because we never count the palindrome consisting of
just these two characters.
*/
