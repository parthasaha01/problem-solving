#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inf = (1LL<<62LL)-1LL;
int n,k;
ll a[55],s[55],dp[55][55];
ll fun(int pos,int cnt)
{
    if(cnt>k)return 0LL;
    if(pos>n){
        if(cnt==k)return inf;
        else return 0LL;
    }

    if(dp[pos][cnt]!= -1LL)return dp[pos][cnt];

    ll ret = 0LL;
    for(int i=pos; i<=n; i++){
        ll sum = s[i]-s[pos-1];
        ll vv = (sum & fun(i+1,cnt+1));
        if(vv>ret){
            ret = vv;
        }
    }
    return dp[pos][cnt] = ret;
}
void path(int pos,int cnt)
{
    //if(cnt>k)return 0LL;
    if(pos>n)return;

    //if(dp[pos][cnt]!= -1LL)return dp[pos][cnt];

    ll ret = fun(pos,cnt);;
    for(int i=pos; i<=n; i++){
        ll sum = s[i]-s[pos-1];
        ll vv = (sum & fun(i+1,cnt+1));
        if(vv==ret){
            cout << pos << " " << i << endl;
            path(i+1,cnt+1);
            break;
        }
    }
    //return dp[pos][cnt] = ret;
}
int main()
{
    //cout << inf << endl;
    scanf("%d%d",&n,&k);

    for(int i=1; i<=n; i++){
        scanf("%lld",&a[i]);
    }

    s[0] = 0;
    for(int i=1; i<=n; i++){
        s[i] = s[i-1] + a[i];
    }

    memset(dp,-1LL,sizeof(dp));

    ll ans = fun(1,0);

    printf("%lld\n",ans);

    path(1,0);

    return 0;
}
/*

40 5
6 18 24 5 14 16 31 9 15 5
25 2 18 12 19 27 10 23 23 18
22 14 1 14 6 14 17 28 11 21
8 23 10 30 21 5 17 11 26 16

*/
