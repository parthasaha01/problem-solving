#include<bits/stdc++.h>
using namespace std;
string sa,sb;
int k,sz,dp[12][2][2][90][90];
int fun(int pos,int choto,int boro,int sum,int num)
{
    if(pos==sz){
        if(sum%k==0 && num%k==0) return 1;
        else return 0;
    }

    if(dp[pos][choto][boro][sum][num]!=-1) return dp[pos][choto][boro][sum][num];

    int lo=0,hi=9;
    if(!boro)lo = sa[pos]-'0';
    if(!choto)hi = sb[pos]-'0';
    int ret = 0;

    for(int i=lo; i<=hi; i++){
        ret += fun(pos+1,choto|(i<hi),boro|(i>lo),sum+i,((num*10)+i)%k);
    }

    return dp[pos][choto][boro][sum][num] = ret;
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

        char s[15];
        sprintf(s,"%d",B);
        sb = s;
        sz = sb.size();
        sprintf(s,"%d",A);
        int d = sz - strlen(s);
        sa = "";
        for(int i=1; i<=d; i++) sa+='0';
        sa += s;

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0,0,0,0);

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}

