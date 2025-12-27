#include<bits/stdc++.h>
using namespace std;
string s;
int sz,dp[20][2][10000];
int fun(int pos,int state,int cnt)
{
    if(pos==sz) return cnt;
    if(dp[pos][state][cnt]!=-1) return dp[pos][state][cnt];

    int ret = 0;
    int lo=0,hi=9;
    if(state)hi=s[pos]-'0';

    for(int i=lo; i<=hi; i++){

        int n_state = state;
        if(i<hi)n_state = 0;

        int n_cnt = cnt;
        if(i==2) n_cnt = cnt+1;

        ret += fun(pos+1,n_state,n_cnt);
    }

    return dp[pos][state][cnt] = ret;
}
int main()
{
    while(cin>>s)
    {
        sz = s.size();

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,1,0);
        printf("%d\n",ans);
    }

    return 0;
}
