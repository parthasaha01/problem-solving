#include<bits/stdc++.h>
using namespace std;
string a,b;
int la,lb,dp[2005][2005];
int lcs(int i,int j)
{
    if(i==la)return abs(lb-j);
    if(j==lb)return abs(la-i);

    if(dp[i][j]!=-1)return dp[i][j];

    int ret=100000000,ret1=100000000,ret2=100000000,ret3=100000000;
    if(a[i]==b[j])
    {
        ret = lcs(i+1,j+1);
    }
    else
    {
        ret1 = 1+lcs(i,j+1);
        ret3 = 1+lcs(i+1,j);
        ret2 = 1+lcs(i+1,j+1);

        ret = min(ret1,min(ret2,ret3));
    }

    return dp[i][j] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        cin>>a>>b;
        la = a.size();
        lb=b.size();
        memset(dp,-1,sizeof(dp));
        int ans = lcs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
