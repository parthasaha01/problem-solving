#include<bits/stdc++.h>
using namespace std;
#define ll long long
string sm,sn;
char s[15];
ll sz,dp[20][2][2][2],dw[20][2][2][2];

ll funway(int pos,int choto,int boro,int suru)
{
    if(pos==sz){
        if(suru) return dw[pos][choto][boro][suru] = 1;
        else return dw[pos][choto][boro][suru] = 0;
    }

    if(dw[pos][choto][boro][suru]!=-1) return dw[pos][choto][boro][suru];

    int lo=0,hi=9;
    if(!boro)lo = sm[pos]-'0';
    if(!choto)hi = sn[pos]-'0';

    ll ret = 0;

    for(int i=lo; i<=hi; i++){
        ret += funway(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0));
    }

    return dw[pos][choto][boro][suru] = ret;
}

ll fun(int pos,int choto,int boro,int suru)
{
    if(pos==sz) return 0;

    if(dp[pos][choto][boro][suru]!=-1)
        return dp[pos][choto][boro][suru];

    int lo=0,hi=9;
    if(!boro)lo = sm[pos]-'0';
    if(!choto)hi = sn[pos]-'0';

    ll ret = 0;

    for(int i=lo; i<=hi; i++){
        ll way = 0;
        if(i==0 && suru) way = dw[pos+1][choto|(i<hi)][boro|(i>lo)][suru|(i>0)];
        ret += way + fun(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0));
    }
    return dp[pos][choto][boro][suru] = ret;
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

        char s[15];
        sprintf(s,"%lld",n);
        sn = s;
        sz = sn.size();
        sprintf(s,"%lld",m);
        int d = sz - strlen(s);
        sm = "";
        for(int i=1; i<=d; i++) sm+='0';
        sm += s;

        memset(dw,-1,sizeof(dw));
        funway(0,0,0,0);

        memset(dp,-1,sizeof(dp));
        ll ans = fun(0,0,0,0)+(m==0);

        printf("Case %d: %lld\n",++ks,ans);
    }

    return 0;
}

