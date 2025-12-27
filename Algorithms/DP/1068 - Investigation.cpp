#include<bits/stdc++.h>
using namespace std;
char s[15];
int k,sz,dp[15][2][100][100];
int fun(int pos,int choto,int sum,int num)
{
    if(pos==sz){
        if(sum%k==0 && num%k==0) return 1;
        else return 0;
    }

    if(dp[pos][choto][sum][num]!=-1) return dp[pos][choto][sum][num];

    int lo=0,hi=9;
    if(!choto)hi = s[pos]-'0';
    int ret = 0;

    for(int i=lo; i<=hi; i++){
        ret += fun(pos+1,choto|(i<hi),sum+i,((num*10)+i)%k);
    }

    return dp[pos][choto][sum][num] = ret;
}
int main()
{
    int T;scanf("%d",&T);

    for(int ks=1; ks<=T; ks++)
    {
        int A,B; scanf("%d%d%d",&A,&B,&k);

        if(k>100){
            printf("Case %d: 0\n",ks);
            continue;
        }

        sprintf(s,"%d",B);
        sz = strlen(s);
        memset(dp,-1,sizeof(dp));
        int cntB = fun(0,0,0,0);

        sprintf(s,"%d",A-1);
        sz = strlen(s);
        memset(dp,-1,sizeof(dp));
        int cntA = fun(0,0,0,0);

        int ans = cntB - cntA;
        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
