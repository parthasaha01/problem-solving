#include<bits/stdc++.h>
using namespace std;
vector<int>vv;
string s;
int sz,n,dp[5005][5][3];
int fun(int pos,int k,int pre)
{
    if(pos==n || k==4)return 0;

    if(dp[pos][k][pre]!=-1)return dp[pos][k][pre];

    int ret = 0;


    if(pos%2==1){
        if(k==0){
            ret = max(ret, fun(pos+1,k,pre));
        }
        else{
            int nk=k+1;
            if(pre==1)nk=k;

            if( k<3 || (k==3 && pre==1)){
                ret = max(ret, vv[pos]+fun(pos+1,nk,1));
            }
            ret = max(ret, fun(pos+1,k,pre));
        }
    }
    else{
        int nk=k+1;
        if(pre==0)nk=k;

        if( k<3 || (k==3 && pre==0)){
            ret = max(ret, vv[pos]+fun(pos+1,nk,0));
        }

        ret = max(ret, fun(pos+1,k,pre));
    }

    return dp[pos][k][pre] = ret;
}
int main()
{
    cin>>s;

    sz = s.size();

    if(s[0]=='b')vv.push_back(0);

    int cnt = 1;
    for(int i=1; i<sz; i++)
    {
        if(s[i]==s[i-1]){
            cnt++;
        }
        else{
            vv.push_back(cnt);
            cnt = 1;
        }
    }

    vv.push_back(cnt);

    if(s[sz-1]=='b')vv.push_back(0);

    n = vv.size();

    memset(dp,-1,sizeof(dp));
    int maxx = fun(0,0,1);

    printf("%d\n",maxx);

    return 0;
}

