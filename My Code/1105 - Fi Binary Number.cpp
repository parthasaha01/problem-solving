#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int MAXN = 55;
LL dp[60][2];
string s;
LL fun(int pos,int pre)
{
    if(pos==MAXN)return 1LL;
    if(dp[pos][pre]!=-1)return dp[pos][pre];
    LL ret = 0;
    ret += fun(pos+1,0);
    if(pre==0)ret += fun(pos+1,1);
    return dp[pos][pre] = ret;
}
void path(int pos,int pre,LL nth)
{
    if(pos==MAXN)return;
    LL ret = fun(pos+1,0);
    if(nth<=ret){
        s += '0';
        path(pos+1,0,nth);
    }
    else{
        s += '1';
        path(pos+1,0,nth-ret);
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    fun(0,0);

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        LL n; scanf("%lld",&n);
        s = "";
        path(0,0,n+1);
        printf("Case %d: ",ks);

        int flag = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1' || flag==1){
                printf("%c",s[i]);
                flag = 1;
            }
        }
        printf("\n");
    }
    return 0;
}
