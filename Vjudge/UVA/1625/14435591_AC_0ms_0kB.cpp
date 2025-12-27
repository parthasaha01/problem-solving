#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,m,lf[26][2],rg[26][2],dp[5005][5005];
void preprocess()
{
    for(int i=0; i<26; i++)lf[i][0]=n,rg[i][0]=-1;
    for(int i=0; i<26; i++)lf[i][1]=m,rg[i][1]=-1;
    for(int i=0; i<n; i++){
        lf[s[i]-'A'][0] = min(lf[s[i]-'A'][0], i);
        rg[s[i]-'A'][0] = max(rg[s[i]-'A'][0], i);
    }
    for(int i=0; i<m; i++){
        lf[t[i]-'A'][1] = min(lf[t[i]-'A'][1], i);
        rg[t[i]-'A'][1] = max(rg[t[i]-'A'][1], i);
    }
}
int checkfirst(int i,int j,int c)
{
    if(lf[c][0]<i || lf[c][1]<j)return 0;
    return 1;
}
int checklast(int i,int j,int c)
{
    if(rg[c][0]==i && rg[c][1]<j)return 1;
    if(rg[c][1]==j && rg[c][0]<i)return 1;
    return 0;
}
int fun(int i,int j)
{
    if(i==n&&j==m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int ret = 10000000;

    if(i<n){
        int cs = s[i]-'A';
        int f = checkfirst(i,j,cs);
        int l = checklast(i,j,cs);
        if(f&&l){
            ret = min(ret, fun(i+1,j));
        }
        else if(f){
            ret = min(ret, -(i+j+1) + fun(i+1,j));
        }
        else if(l){
            ret = min(ret, (i+j+1) + fun(i+1,j));
        }
        else{
            ret = min(ret, fun(i+1,j));
        }
    }
    if(j<m){
        int ct = t[j]-'A';
        int f = checkfirst(i,j,ct);
        int l = checklast(i,j,ct);
        if(f&&l){
            ret = min(ret, fun(i,j+1));
        }
        else if(f){
            ret = min(ret, -(i+j+1) + fun(i,j+1));
        }
        else if(l){
            ret = min(ret, (i+j+1) + fun(i,j+1));
        }
        else{
            ret = min(ret, fun(i,j+1));
        }
    }
    return dp[i][j] = ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int tt; cin>>tt;
    while(tt--)
    {
        cin>>s>>t;
        n = s.size(); m = t.size();
        preprocess();
        //memset(dp,-1,sizeof(dp));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j]=-1;
            }
        }
        int ans = fun(0,0);
        cout << ans << endl;
    }
    return 0;
}
