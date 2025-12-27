#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[1005][1005];
int lcs(int i, int j)
{
    if(i==a.size())return 0;
    if(j==b.size())return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int ret,ret1,ret2;
    if(a[i]==b[j]){
        ret = 1+lcs(i+1,j+1);
    }
    else{
        ret1 = lcs(i+1,j);
        ret2 = lcs(i,j+1);
        ret = max(ret1,ret2);
    }
    return dp[i][j] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);
    getchar();

    for(int ks=1; ks<=tt; ks++)
    {
        getline(cin,a);
        b = a;
        reverse(b.begin(),b.end());
        memset(dp,-1,sizeof(dp));
        int ans = lcs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
