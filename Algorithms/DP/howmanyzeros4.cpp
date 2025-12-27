#include<bits/stdc++.h>
using namespace std;
#define ll long long
string sm,sn;
int sz,dp[20][2][2][2];
int fun(int pos,int choto,int boro,int suru,int pre)
{
    if(pos==sz){
        if(pre==0 && suru) return 1;
        else return 0;
    }

   // if(dp[pos][choto][boro][suru]!=-1&& choto==1&&boro==1) return dp[pos][choto][boro][suru];

    int ret = 0;
    int lo=0,hi=9;
    if(!boro)lo = sm[pos]-'0';
    if(!choto)hi = sn[pos]-'0';

    for(int i=lo; i<=hi; i++){
        if(pre==0&&suru==1){
            ret +=1+fun(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0),i);
        }
        else{
            ret += fun(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0),i);
        }
    }
    return dp[pos][choto][boro][suru] = ret;
}
int funway(int pos,int choto,)
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

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0,0,0,1)+(m==0);

        printf("Case %d: %lld\n",++ks,ans);
    }

    return 0;
}

