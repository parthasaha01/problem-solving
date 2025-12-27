#include<bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define ll long long
string s;
int n,dp[MAXN][10][2][2],dw[MAXN][10][2][2];
ll funway(int pos,int digit,int choto,int suru)
{
    if(pos==n){
        if(suru)return 1LL;
        else return 0LL;
    }

    if(dw[pos][digit][choto][suru]!=-1)return dw[pos][digit][choto][suru];

    int lo = 0, hi = 9;
    if(!choto)hi = s[pos]-'0';
    ll ret = 0;
    for(int i=lo; i<=hi; i++){
        ret += funway(pos+1,digit,choto|(i<hi),suru|(i>0));
    }
    return dw[pos][digit][choto][suru] = ret;
}
ll fun(int pos,int digit,int choto,int suru)
{
    if(pos==n)return 0LL;

    if(dp[pos][digit][choto][suru]!=-1)return dp[pos][digit][choto][suru];

    int lo = 0, hi = 9;
    if(!choto)hi = s[pos]-'0';
    ll ret = 0;
    for(int i=lo; i<=hi; i++){
        ll way = 0;
        if(i==digit && (suru | i>0))
        way = funway(pos+1,digit,choto|(i<hi),suru|(i>0));

        ret += way + fun(pos+1,digit,choto|(i<hi),suru|(i>0));
    }
    return dp[pos][digit][choto][suru] = ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    n = s.size();

    memset(dp,-1,sizeof(dp));
    memset(dw,-1,sizeof(dw));
    ll maxx = 0,ans=0;
    for(int i=0; i<=9; i++){
        funway(0,i,0,0);
        ll ret = fun(0,i,0,0);
        if(i==0)ret++;
        if(ret>=maxx){
            maxx = ret;
            ans = i;
        }
    }

    cout << ans << endl;

    main();

    return 0;
}
