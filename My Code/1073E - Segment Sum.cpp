#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PLL pair<LL,LL>
const LL MOD = 998244353ll;
PLL dp[1<<10][20][2][2];
LL power[20];
int k,sz;
char s[20];

PLL fun(int mask, int pos, int choto, int suru){
    if(pos==sz){
        int bit = __builtin_popcount(mask);
        if(bit<=k && suru) return make_pair(0,1);
        return make_pair(0,0);
    }
    PLL &ret = dp[mask][pos][choto][suru];
    if(ret.first != -1)return ret;
    ret = make_pair(0,0);
    int lo = 0, hi = 9;
    if(choto==0) hi = s[pos]-'0';
    for(int i=lo; i<=hi; i++){
        int Nmask = mask;
        if(suru || i>0) Nmask = (Nmask|(1<<i));
        PLL temp = fun(Nmask, pos+1, choto|(i<hi), suru|(i>0));
        ret.first  += temp.first;
        ret.first  += (((i*power[pos])%MOD) * (temp.second%MOD))%MOD;
        ret.first  %= MOD;
        ret.second += temp.second;
        ret.second %= MOD;
    }
    return ret;
}
LL solve(LL n){
    if(n==0) return 0LL;
    sprintf(s,"%lld",n);
    sz = strlen(s);
    power[sz-1] = 1LL;
    for(int i=sz-2; i>=0; i--){
        power[i] = (power[i+1]*10)%MOD;
    }
    memset(dp,-1,sizeof(dp));
    PLL res = fun(0,0,0,0);
    return res.first;
}
int main(){
    LL l,r; scanf("%lld %lld %d",&l,&r,&k);
    LL ans = solve(r) - solve(l-1);
    ans %= MOD; ans += MOD; ans %= MOD;
    printf("%lld\n",ans);
    return 0;
}
