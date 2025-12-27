#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll n,b,k,x[18],dp[(1<<17)+2][22];
ll fun(ll mask,ll sum)
{
    if(mask==((1<<n)-1)){
        if(sum==0)return 1LL;
        else return 0LL;
    }

    ll& ret = dp[mask][sum];
    if(ret!=-1)return ret;
    ret = 0;

    for(int i=0; i<n; i++){
        if((mask&(1<<i))==0){
            ret += fun(mask|(1<<i), (sum*b+x[i])%k);
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cin>>b>>k;
        cin>>s;
        n = s.size();

        for(int i=0; i<n; i++){
            if(s[i]>='A'&&s[i]<='F')x[i] = s[i]-'A'+10;
            else x[i] = s[i]-'0';
        }

        memset(dp,-1,sizeof(dp));
        ll ans = fun(0,0);
        cout<<"Case "<<ks<<": "<<ans<<endl;
    }
    return 0;
}
/*
2
16 12
F853AD64B1EC7290
16 18
8192BEFA70CD3564

Case 1: 5230697472000
Case 2: 3486618432000
*/
