#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[15];
int sz,dp[20][2][2][30];
int fun(int pos,int choto,int suru,int cnt)
{
    if(pos==sz) return cnt;
    if(dp[pos][choto][suru][cnt]!=-1) return dp[pos][choto][suru][cnt];

    int ret = 0;
    int lo=0,hi=9;
    if(!choto)hi=s[pos]-'0';

    for(int i=lo; i<=hi; i++){
        ret += fun(pos+1,choto|(i<hi),suru|(i>0),(i==0&&suru)+cnt);
    }

    return dp[pos][choto][suru][cnt] = ret;
}
int main()
{
    ll m,n;
    int t,ks=0; scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&m,&n);
        if(m==0&&n==0){
            printf("Case %d: 1\n",++ks); continue;
        }

        m--;
        ll cntm,cntn;

        if(m<0) cntm = 0;
        else{
            sprintf(s,"%lld",m);
            sz = strlen(s);
            memset(dp,-1,sizeof(dp));
            cntm = fun(0,0,0,0)+1;
        }
            sprintf(s,"%lld",n);
            sz = strlen(s);
            memset(dp,-1,sizeof(dp));
            cntn = fun(0,0,0,0)+1;

        int ans = cntn-cntm;
        printf("Case %d: %lld\n",++ks,ans);
    }

    return 0;
}
