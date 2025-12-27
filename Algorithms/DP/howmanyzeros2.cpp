#include<bits/stdc++.h>
using namespace std;
#define ll long long
string sm,sn;
int sz,dp[20][2][2][2][30];
int fun(int pos,int choto,int boro,int suru,int cnt)
{
    if(pos==sz) return cnt;

    if(dp[pos][choto][boro][suru][cnt]!=-1) return dp[pos][choto][boro][suru][cnt];

    int ret = 0;
    int lo=0,hi=9;
    if(!boro)lo = sm[pos]-'0';
    if(!choto)hi = sn[pos]-'0';

    for(int i=lo; i<=hi; i++){

        int n_choto = choto;
        if(i<hi)n_choto = 1;

        int n_boro = boro;
        if(i>lo)n_boro = 1;

        int n_suru = suru;
        if(i>0)n_suru = 1;

        int n_cnt = cnt;
        if(n_suru&&i==0) n_cnt = cnt+1;

        ret += fun(pos+1,n_choto,n_boro,n_suru,n_cnt);
    }
    return dp[pos][choto][boro][suru][cnt] = ret;
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

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0,0,0,0)+(m==0);

        printf("Case %d: %lld\n",++ks,ans);
    }

    return 0;
}

