
#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
map<int,string>sp;
vector<string>vv;
int a[105],b[105],la,lb,k;
int dp[105][105];
int lcs(int i, int j)
{
    if(i>la)return 0;
    if(j>lb)return 0;

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
void path(int i,int j)
{
    if(i>la)return;
    if(j>lb)return;

    int ret,ret1,ret2;

    if(a[i]==b[j]){
        vv.push_back(sp[a[i]]);
        path(i+1,j+1);
    }
    else{
        ret1 = lcs(i+1,j);
        ret2 = lcs(i,j+1);
        ret = lcs(i,j);

        if(ret1==ret) path(i+1,j);
        else path(i,j+1);
    }
}
int main()
{
    string s;
    while(cin>>s)
    {
        mp.clear();
        sp.clear();
        vv.clear();

        la=0; k=0;
        mp[s] = ++k;
        a[++la] = k;

        while(cin>>s)
        {
            if(s=="#")break;
            if(mp[s]==0) mp[s] = ++k;
            a[++la] = mp[s];
            sp[mp[s]]=s;
        }

        lb=0;
        while(cin>>s)
        {
            if(s=="#")break;
            if(mp[s]==0) mp[s] = ++k;
            b[++lb] = mp[s];
            sp[mp[s]]=s;
        }

        memset(dp,-1,sizeof(dp));
        int ans = lcs(1,1);
        path(1,1);

        for(int i=0; i<vv.size(); i++){
            if(i==vv.size()-1)cout << vv[i] << endl;
            else cout << vv[i] << " ";
        }
    }
    return 0;
}
