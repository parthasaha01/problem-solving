#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int n,k,dp[55][55][35];
string s;
int fun(int pos,int cnt,int pre)
{
    if(cnt>k)return 100000;
    if(pos==n){
        //cout << cnt << endl;
        //getchar();
        if(cnt==k)return 0;
        return 10000000;
    }

    if(dp[pos][cnt][pre]!=-1)return dp[pos][cnt][pre];

    int id = s[pos]-'a'+4;
    int w = s[pos]-'a'+1;
    int ret = 10000000;
    if(id>(pre+1))ret=min(ret,w+fun(pos+1,cnt+1,id));
    ret = min(ret,fun(pos+1,cnt,pre));

    return dp[pos][cnt][pre] = ret;
}
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    //memset(dp,-1,sizeof(dp));

    cin>>n>>k;
    cin>>s;
    sort(s.begin(),s.end());
    memset(dp,-1,sizeof(dp));

    int ans = fun(0,0,0);
    if(ans>=100000)ans=-1;
    cout<<ans<<endl;
    return 0;
}
