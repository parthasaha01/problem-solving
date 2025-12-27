#include<bits/stdc++.h>
using namespace std;
string a,b;
int sz1,sz2,dp[105][105];
int fun(int i,int j)
{
    if(i==sz1 || j == sz2) return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int ret1=0,ret2=0,ret3=0;

    if(a[i]==b[j]){
        ret1 = 1+fun(i+1,j+1);
    }
    else{
        ret2 = fun(i,j+1);
        ret3 = fun(i+1,j);
    }

    int ret = max(ret1,max(ret2,ret3));
    return dp[i][j]=ret;
}
int main()
{
    int ks=0;
    while(getline(cin,a))
    {
        if(a=="#")break;

        getline(cin,b);

        sz1 = a.size();
        sz2 = b.size();

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0);
        printf("Case #%d: you can visit at most %d cities.\n",++ks,ans);
    }
    return 0;
}

