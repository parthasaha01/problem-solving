#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
int dp[35][35],la,lb;
ll wp[35][35][75];
int fun(int i,int j)
{
    if(i==la || j==lb)return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ret=0;
    if(a[i]==b[j]) ret = 1+fun(i+1,j+1);
    else ret = max(fun(i+1,j), fun(i,j+1));

    return dp[i][j] = ret;
}
ll way(int i, int j,int n)
{
    if(i==la && j==lb){
        if(n==0)return 1;
        else return 0;
    }

    if(n<0)return 0;

    if(wp[i][j][n]!=-1)return wp[i][j][n];

    ll ret=0;

    if(a[i]==b[j]){
        ret+=way(i+1,j+1,n-1);
    }
    else{
        if(i<la)ret+=way(i+1,j,n-1);
        if(j<lb)ret+=way(i,j+1,n-1);
    }

    return wp[i][j][n] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        cin >> a >> b;
        la=a.size();
        lb=b.size();

        memset(dp,-1,sizeof(dp));
        int n = fun(0,0);

        n = la + lb - n;

        memset(wp,-1,sizeof(wp));
        ll ans = way(0,0,n);

        printf("Case %d: %d %lld\n",ks,n,ans);
    }
    return 0;
}

/*
3
USA
USSR
LAILI
MAJNU
SHAHJAHAN
MOMTAJ


*/

