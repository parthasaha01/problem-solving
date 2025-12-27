#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int sz;
ll dp[40][2][2][50];
ll fun(int pos,int choto,int pre,int cnt)
{
    if(pos==sz){
        return cnt;
    }

    if(dp[pos][choto][pre][cnt] != -1) return dp[pos][choto][pre][cnt];

    int lo=0,hi=1;
    if(!choto)hi=s[pos]-'0';
    ll ret = 0;

    for(int i=lo; i<=hi; i++){
        ret += fun(pos+1,choto|(i<hi),i,(pre==1&&i==1)+cnt);
    }
    return dp[pos][choto][pre][cnt]=ret;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n; scanf("%lld",&n);
        s="";
        if(n==0) s+='0';
        while(n!=0){
            int r = n%2;
            s+=r+'0';
            n/=2;
        }
        reverse(s.begin(),s.end());
        sz = s.size();

        memset(dp,-1,sizeof(dp));
        ll ans = fun(0,0,0,0);
        printf("Case %d: %lld\n",ks,ans);
    }
    return 0;
}

