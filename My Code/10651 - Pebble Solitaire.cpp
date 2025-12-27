#include<bits/stdc++.h>
using namespace std;
int dp[1<<12];
int possibleLeft(int i,int mask)
{
    if(i<0 || i>11)return 0;
    if((i-1)<0 || (i-1)>11)return 0;
    if((i+1)<0 || (i+1)>11)return 0;

    if((mask&(1<<i))==0) return 0;
    if((mask&(1<<(i-1)))!=0)return 0;
    if((mask&(1<<(i+1)))==0)return 0;
    return 1;
}
int possibleRight(int i,int mask)
{
    if(i<0 || i>11)return 0;
    if((i+1)<0 || (i+1)>11)return 0;
    if((i+2)<0 || (i+2)>11)return 0;

    if((mask&(1<<i))==0) return 0;
    if((mask&(1<<(i+1)))==0)return 0;
    if((mask&(1<<(i+2)))!=0)return 0;
    return 1;
}
int fun(int mask)
{
    if(dp[mask]!=-1)return dp[mask];
    int f = 0;
    int ret = 15;
    for(int i=0; i<12; i++){
        if(possibleLeft(i,mask)){
            int temp = mask;
            f = 1;
            temp = temp^(1<<i);
            temp = temp^(1<<(i-1));
            temp = temp^(1<<(i+1));
            ret = min(ret,fun(temp));
        }
        if(possibleRight(i,mask)){
            int temp = mask;
            f = 1;
            temp = temp^(1<<i);
            temp = temp^(1<<(i+1));
            temp = temp^(1<<(i+2));
            ret = min(ret,fun(temp));
        }
    }

    if(!f){
        int cnt = 0;
        for(int i=0; i<12; i++){
            if(mask&(1<<i))cnt++;
        }
        return cnt;
    }
    return dp[mask] = ret;
}
int main()
{
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        string s; cin>>s;
        int mask = 0;
        for(int i=0; i<12; i++){
            if(s[i]=='o')mask = mask|(1<<i);
        }
        memset(dp,-1,sizeof(dp));
        int ans = fun(mask);
        cout << ans << endl;
    }
    return 0;
}
