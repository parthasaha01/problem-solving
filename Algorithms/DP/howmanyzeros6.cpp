#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
char s[15];
ll sz,dp[20][2][2],dw[20][2][2];

ll funway(int pos,int choto,int suru)
{
    if(pos==sz){
        if(suru) return 1;
        else return 0;
    }

    if(dw[pos][choto][suru]!=-1) return dw[pos][choto][suru];

    int lo=0,hi=9;
    if(!choto)hi=s[pos]-'0';

    ll ret = 0;

    for(int i=lo; i<=hi; i++){
        ret += funway(pos+1,choto|(i<hi),suru|(i>0))%mod;
    }

    return dw[pos][choto][suru] = ret;
}

ll fun(int pos,int choto,int suru)
{
    if(pos==sz) return 0;

    if(dp[pos][choto][suru]!=-1)
        return dp[pos][choto][suru];


    int lo=0,hi=9;
    if(!choto)hi=s[pos]-'0';

    ll ret = 0;

    for(int i=lo; i<=hi; i++){
        ll way = 0;
        if(i==0 && suru) way = funway(pos+1,choto|(i<hi),suru|(i>0));

        ret += way + fun(pos+1,choto|(i<hi),suru|(i>0));
    }
    return dp[pos][choto][suru] = ret;
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
        ll cntm,cntn,p;

        if(m<0) cntm = 0;
        else{
            sprintf(s,"%lld",m);
            sz = strlen(s);

            memset(dw,-1,sizeof(dw));
            funway(0,0,0);

            memset(dp,-1,sizeof(dp));
            cntm = fun(0,0,0)+1;
        }
            sprintf(s,"%lld",n);
            sz = strlen(s);

            memset(dw,-1,sizeof(dw));
            funway(0,0,0);


            memset(dp,-1,sizeof(dp));
            cntn = fun(0,0,0)+1;

        ll ans = cntn-cntm;
        printf("Case %d: %lld\n",++ks,ans);
    }

    return 0;
}

