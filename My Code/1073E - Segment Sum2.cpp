#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PLL pair<LL,LL>
const LL MOD = 998244353ll;
PLL dp[1<<10][20][2][2];
LL power[20];
int k,n;
string a,b;

PLL fun(int mask, int pos, int boro, int choto){
    if(pos==n){
        int bit = __builtin_popcount(mask);
        if(bit<=k && bit>0) return make_pair(0,1);
        return make_pair(0,0);
    }
    PLL &ret = dp[mask][pos][boro][choto];
    if(ret.first != -1)return ret;
    ret = make_pair(0,0);
    int lo = 0, hi = 9;
    if(boro==0) lo = a[pos] - '0';
    if(choto==0) hi = b[pos]- '0';
    for(int i=lo; i<=hi; i++){
        int Nmask = mask;
        if((i>0) || mask>0) Nmask = (Nmask|(1<<i));
        PLL temp = fun(Nmask, pos+1, boro|(i>lo), choto|(i<hi));
        ret.first  += temp.first;
        ret.first  += (((i*power[pos])%MOD) * (temp.second%MOD))%MOD;
        ret.first  %= MOD;
        ret.second += temp.second;
        ret.second %= MOD;
    }
    return ret;
}
LL solve(LL l, LL r) {
    a.clear(); b.clear();
	while(r!=0) {
		b += (r%10) + '0';
		r /= 10;
	}	
	while(l!=0) {
		a += (l%10) + '0';
		l /= 10;
	}
	while(a.size() < b.size()) a += '0';
	n = b.size();
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
    power[n-1] = 1LL;
    for(int i=n-2; i>=0; i--){
        power[i] = (power[i+1]*10)%MOD;
    }
    memset(dp,-1,sizeof(dp));
    PLL res = fun(0,0,0,0);
    return res.first;
}
int main(){
    LL l,r; scanf("%lld %lld %d",&l,&r,&k);
    LL ans = solve(l,r);
    ans %= MOD; ans += MOD; ans %= MOD;
    printf("%lld\n",ans);
    return 0;
}
