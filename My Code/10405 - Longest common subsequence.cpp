#include<bits/stdc++.h>
using namespace std;
int lb,la;
int dp[1005][1005];
string a,b;
int lcs(int i, int j)
{
    if(i==la)return 0;
    if(j==lb)return 0;

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
    while(getline(cin,a))
    {
        getline(cin,b);

        la = a.size();
        lb = b.size();

        memset(dp,-1,sizeof(dp));
        int ans = lcs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}

