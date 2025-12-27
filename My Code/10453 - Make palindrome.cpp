#include<bits/stdc++.h>
using namespace std;
int la,lb,dp[1005][1005];
string a,b,s;
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
void path(int i, int j)
{
    if(i==la){
        for(int k=j; k<lb; k++)s+=b[k];
        return;
    }
    if(j==lb){
        for(int k=i; k<la; k++)s+=a[k];
        return;
    }

    int ret = lcs(i,j);

    if(a[i]==b[j]){
        s+=a[i];
        path(i+1,j+1);
    }
    else{
        int ret1 = lcs(i+1,j);
        int ret2 = lcs(i,j+1);
        if(ret==ret1){
            s+=a[i];
            path(i+1,j);
        }
        else{
            s+=b[j];
            path(i,j+1);
        }
    }
}
int main()
{
    while(cin>>a)
    {
        b=a;
        reverse(b.begin(),b.end());
        la = a.size();
        lb = b.size();

        memset(dp,-1,sizeof(dp));
        int ls = lcs(0,0);
        int ans = la-ls;
        s = "";
        path(0,0);
        cout << ans << " " << s << endl;
    }
    return 0;
}
/*
bceadecb
*/
