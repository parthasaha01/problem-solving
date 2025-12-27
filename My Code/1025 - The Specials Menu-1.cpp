#include <bits/stdc++.h>
using namespace std;
int dp[70][70];
string str;

int func(int i, int j)
{
    if(i==j) return 1;
    if(i>j) return 0;

    int &ret=dp[i][j];
    if(ret!=-1) return ret;

    int ans=0;

    if(str[i]==str[j]) ans=1+func(i+1,j)+func(i,j-1);
    else ans=func(i+1,j)+func(i,j-1)-func(i+1,j-1);

    return ret=ans;
}

int main()
{
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cin>>str;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<ks<<": "<<func(0,str.size()-1)<<endl;
    }
    return 0;
}
