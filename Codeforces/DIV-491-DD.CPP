#include<bits/stdc++.h>
using namespace std;
string s[2];
int n,a[2][105],dp[105][8][8];
int check1(int mask0,int mask1){
    if((mask0&(1<<1)) || (mask0&(1<<0)) || (mask1&(1<<1))) return 0;
    return 1;
}
int check2(int mask0,int mask1){
    if((mask0&(1<<1)) || (mask1&(1<<0)) || (mask1&(1<<1))) return 0;
    return 1;
}
int check3(int mask0,int mask1){
    if((mask0&(1<<1)) || (mask1&(1<<1)) || (mask1&(1<<2))) return 0;
    return 1;
}
int check4(int mask0,int mask1){
    if((mask0&(1<<1)) || (mask0&(1<<2)) || (mask1&(1<<1))) return 0;
    return 1;
}
int reset0(int pos,int mask,int i)
{
    if(i==0){
        int mask0 = 0;
        if(mask&(1<<1)) mask0 = (mask0|(1<<0));
        if(mask&(1<<2)) mask0 = (mask0|(1<<1));
        if(a[0][pos+2]) mask0 = (mask0|(1<<2));
    }
    else{
        int mask1 = 0;
        if(mask&(1<<1)) mask1 = (mask1|(1<<0));
        if(mask&(1<<2)) mask1 = (mask1|(1<<1));
        if(a[1][pos+2]) mask1 = (mask1|(1<<2));
    }
}
int reset1(int pos,int mask,int i)
{
    if(i==0){
        int mask0 = 0;
        mask0 = (mask0|(1<<0));
        if(mask&(1<<2)) mask0 = (mask0|(1<<1));
        if(a[0][pos+1]) mask0 = (mask0|(1<<2));
    }
    else{
        int mask1 = 0;
        mask1 = (mask1|(1<<0));
        if(mask&(1<<2)) mask1 = (mask1|(1<<1));
        if(a[1][pos+2]) mask1 = (mask1|(1<<2));
    }
}
int reset2(int pos,int mask,int i)
{
    if(i==0){
        int mask0 = 0;
        mask0 = (mask0|(1<<0));
        if(mask&(1<<2)) mask0 = (mask0|(1<<1));
        if(a[0][pos+1]) mask0 = (mask0|(1<<2));

    }
    else{
        int mask1 = 0;
        mask1 = (mask1|(1<<0));
        if(mask&(1<<2)) mask1 = (mask1|(1<<1));
        if(a[1][pos+2]) mask1 = (mask1|(1<<2));
    }
}
int reset3(int pos, int mask,int i)
{
    if(i==0){
        int mask0 = 0;
        mask0 = (mask0|(1<<0));
        if(mask&(1<<2)) mask0 = (mask0|(1<<1));
        if(a[0][pos+1]) mask0 = (mask0|(1<<2));
    }
    else{
        int mask1 = 0;
        mask1 = (mask1|(1<<0));
        mask1 = (mask1|(1<<1));
        if(a[1][pos+2]) mask1 = (mask1|(1<<2));
    }
}
int reset4(int pos, int mask,int i)
{
    if(i==0){
        int mask0 = 0;
        mask0 = (mask0|(1<<0));
        mask0 = (mask0|(1<<1));
        if(a[0][pos+1]) mask0 = (mask0|(1<<2));
    }
    else{
        int mask1 = 0;
        if(mask&(1<<1)) mask1 = (mask1|(1<<0));
        mask1 = (mask1|(1<<1));
        if(a[1][pos+2]) mask1 = (mask1|(1<<2));
    }
}
int fun(int pos,int mask0,int mask1)
{
    if(pos>n)return 0;
    if(dp[pos][mask0][mask1]!=-1)return dp[pos][mask0][mask1];

    int ret = 0;
    if(check1(mask0,mask1))ret = max(ret,1+fun(pos+1,reset1(pos,mask0,0),reset1(pos,mask1,1)));
    if(check2(mask0,mask1))ret = max(ret,1+fun(pos+1,reset2(pos,mask0,0),reset2(pos,mask1,1)));
    if(check3(mask0,mask1))ret = max(ret,1+fun(pos+1,reset3(pos,mask0,0),reset3(pos,mask1,1)));
    if(check4(mask0,mask1))ret = max(ret,1+fun(pos+1,reset4(pos,mask0,0),reset4(pos,mask1,1)));
    ret = max(ret,fun(pos+1,reset0(pos,mask0,0),reset0(pos,mask1,1)));

    return dp[pos][mask0][mask1] = ret;
}
int main()
{
    cin>>s[0];
    cin>>s[1];

    n = s[0].size();

    for(int i=0; i<s[0].size(); i++){
        if(s[0][i]=='0')a[0][i+1] = 0;
        else a[0][i+1] = 1;
    }

    for(int i=0; i<s[1].size(); i++){
        if(s[1][i]=='0')a[1][i+1] = 0;
        else a[1][i+1] = 1;
    }

    n++;
    a[0][0] = 1; a[0][n] = 1;
    a[1][0] = 1; a[1][n] = 1;

    int mask0 = 0;
    if(a[0][0]==1) mask0 = (mask0|(1<<0));
    if(a[0][1]==1) mask0 = (mask0|(1<<1));
    if(a[0][2]==1) mask0 = (mask0|(1<<2));

    int mask1 = 0;
    if(a[1][0]==1) mask1 = (mask1|(1<<0));
    if(a[1][1]==1) mask1 = (mask1|(1<<1));
    if(a[1][2]==1) mask1 = (mask1|(1<<2));

    memset(dp,-1,sizeof(dp));
    int ans = fun(1,mask0,mask1);

    cout << ans << endl;
    main();
    return 0;
}

