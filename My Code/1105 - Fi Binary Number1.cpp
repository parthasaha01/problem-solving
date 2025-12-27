#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int MAXN = 55;
LL dp[60][2][2];
string s;
LL fun(int pos,int pre,int suru)
{
    if(pos==MAXN){
        if(suru)return 1LL;
        return 0LL;
    }
    if(dp[pos][pre][suru]!=-1)return dp[pos][pre][suru];
    LL ret = 0;
    ret += fun(pos+1,0,suru);
    if(pre==0)ret += fun(pos+1,1,1);
    return dp[pos][pre][suru] = ret;
}
void path(int pos,int pre,int suru,LL nth)
{
    if(pos==MAXN)return;
    LL ret = fun(pos+1,0,suru);
    if(nth<=ret){
        s += '0';
        path(pos+1,0,suru,nth);
    }
    else{
        s += '1';
        path(pos+1,0,1,nth-ret);
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    fun(0,0,0);

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        LL n; scanf("%lld",&n);
        s = "";
        path(0,0,0,n);
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

