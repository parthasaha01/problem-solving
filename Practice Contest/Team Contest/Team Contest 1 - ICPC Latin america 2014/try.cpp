/*
* Allah is Almighty.......
*
* Mehedi Hasan Angkur <thisisangkur@gmail.com>
* CSE 11th Batch,MBSTU
* uva,cf id mbstu_angkur..
*
* keep coding...
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D double
#define pb push_back
#define mpp make_pair
#define sf scanf
#define pf printf
#define ff first
#define ss second
#define sz 100005
#define sq(x) x*x
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define dist(x1, y1, x2, y2) sqrt(sq(x1-x2)+sq(y1-y2))
#define FastIO ios_base::sync_with_stdio(0)
const int inf = 0x7f7f7f7f;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

string st;
ll dp[5005][5005];
ll a,b;
ll fun(ll pos,ll rem)
{
    if(rem==0)
        return 0;
    if(dp[pos][rem]!=-1)
        return dp[pos][rem];
    ll ret = 1111111111111111;
    if(st[pos]=='B')
        ret = fun(pos+1,rem-1);
    else
    {
        ret = min(fun(pos+1,rem-1)+a,fun(pos+1,rem)+(a-b)*rem);
    }
    dp[pos][rem] = ret;
    return ret;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //FastIO;
    //main();
    while(sf("%lld%lld",&a,&b)==2)
    {
        mem(dp,-1);
        cin>>st;
        ll cnt = 0;
        for(int i=0; i<st.size(); i++)
        {
            if(st[i]=='B')
                cnt++;
        }
        ll res = fun(0,cnt);
        cout<<res<<endl;
    }
}




