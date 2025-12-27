#include<bits/stdc++.h>
using namespace std;
string s;
int n,dp[101][101];
int fun(int i,int j)
{
//    if(i==j)return 0;
//    if(j==i+1){
//        if(s[i]==s[j])return 0;
//        return 1;
//    }
    if(i>j)return 0;
    int& ret = dp[i][j];
    if(ret!=-1)return ret;
    ret = 100000;
    if(s[i]==s[j])ret = min(ret,fun(i+1,j-1));
    else {
        ret = min(ret,1+fun(i+1,j));
        ret = min(ret,1+fun(i,j-1));
    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cin>>s;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        int ans = fun(0,n-1);
        cout<<"Case "<<ks<<": "<<ans<<endl;
    }
    return 0;
}
