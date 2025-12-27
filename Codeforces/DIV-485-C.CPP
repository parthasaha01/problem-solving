#include<bits/stdc++.h>
using namespace std;
#define ll int
ll inf = 1000000000;
int n,flag=0;
ll dp[3001][3001][4];
ll a[3005],s[3005];
int fun(int pos,int v,int k)
{
    if(k==3){
        //flag = 1;
        return 0;
    }
    if(pos>n){
        if(k==3){
           // flag = 1;
            return 0;
        }
        else return 1000000000;
    }

    if(dp[pos][v][k]!=-1)return dp[pos][v][k];

    ll ret1 = inf, ret2 = inf;

    if(a[pos]>a[v])ret1 = s[pos]+fun(pos+1,pos,k+1);
    ret2 = fun(pos+1,v,k);

    return dp[pos][v][k] = min(ret1,ret2);

}
int main()
{
    scanf("%d",&n);
    a[0] = 0;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d",&s[i]);
    }

    memset(dp,-1,sizeof(dp));
    //flag = 0;
    ll ans = fun(1,0,0);

    if(ans>=inf)printf("-1\n");
    else printf("%d\n",ans);

    return 0;
}
