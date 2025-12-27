#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int n,dp[25],wp[25][25];
int fun(int i)
{
    if(i==n)return 1;
    if(dp[i]!=-1)return dp[i];
    int ret = 0;
    for(int j=i; j<n; j++){
        if(wp[i][j]==1)ret |= fun(j+1);
    }
    return dp[i] = ret;
}
void preprocess()
{
    for(int i=0; i<n; i++){
        ll v = 0;
        for(int j=i; j<n; j++){
            v = (v*10LL)+(s[j]-'0');
            ll sq = sqrt(v);
            if(sq*sq==v)wp[i][j]=1;
            else wp[i][j]=0;
        }
    }
}
int main()
{
    cout << 1002302%14 << endl;
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>s;
        n = s.size();
        memset(wp,0,sizeof(wp));
        preprocess();
        memset(dp,-1,sizeof(dp));
        int ans = fun(0);
        if(ans==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
