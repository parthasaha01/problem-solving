#include<bits/stdc++.h>
using namespace std;
string s1,s2,ss;
int n,dp[1005][1005];
int fun(int pos1,int pos2,int red,int black)
{
    if(abs(red-black)>1)return 0;
    if(pos1==n && pos2==n) return 1;

    if(dp[pos1][pos2]!=-1)return dp[pos1][pos2];

    int ret1=0,ret2=0;
    if(pos1<n){
        if(s1[pos1]=='1') ret1 = fun(pos1+1,pos2,red+1,black);
        else ret1 = fun(pos1+1,pos2,red,black+1);
    }
    if(pos2<n){
        if(s2[pos2]=='1') ret2 = fun(pos1,pos2+1,red+1,black);
        else ret2 = fun(pos1,pos2+1,red,black+1);
    }

    return dp[pos1][pos2] = ret1 | ret2;
}
void path(int pos1,int pos2,int red,int black)
{
    if(abs(red-black)>1)return;
    if(pos1==n && pos2==n) return;

    int ret1=0,ret2=0;
    if(pos1<n){
        if(s1[pos1]=='1') ret1 = fun(pos1+1,pos2,red+1,black);
        else ret1 = fun(pos1+1,pos2,red,black+1);
    }
    if(pos2<n){
        if(s2[pos2]=='1') ret2 = fun(pos1,pos2+1,red+1,black);
        else ret2 = fun(pos1,pos2+1,red,black+1);
    }

    if(ret1==1){
        if(s1[pos1]=='1') path(pos1+1,pos2,red+1,black);
        else path(pos1+1,pos2,red,black+1);
        ss+='1';
    }
    else{
        if(s2[pos2]=='1') path(pos1,pos2+1,red+1,black);
        else path(pos1,pos2+1,red,black+1);
        ss+='2';
    }
}
int main()
{
    while(cin>>n)
    {
        cin>>s1;
        cin>>s2;

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0,0,0);

        if(!ans){
            printf("Impossible\n");
            continue;
        }

        ss="";
        path(0,0,0,0);
        reverse(ss.begin(),ss.end());
        cout << ss << endl;
    }

    return 0;
}
