#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PLL pair<ll,ll>
const ll mod = 998244353;
ll l,r,k;
ll power[19];
PLL dp[19][1024][2][2];
bool vis[19][1024][2][2];
string a,b;
int n;
PLL fun(int pos, int mask, int boro, int choto) {
	int cnt = __builtin_popcount(mask);
	if(cnt>k) return make_pair(0LL, 0);
	if(pos==n){
		if(cnt<=k) return make_pair(0LL, 1);
		return make_pair(0LL, 0);
	}
	
	PLL &ret = dp[pos][mask][boro][choto];
	if(vis[pos][mask][boro][choto]) return ret;
	vis[pos][mask][boro][choto] = true;
	ret.first = ret.second = 0;
	
	int lo = 0, hi = 9;
	if(!boro) lo = a[pos]-'0';
	if(!choto) hi = b[pos]-'0';
	
	for(int i=lo; i<=hi; i++) {
		int nmask = mask;
		if((i>0) || (mask>0)) nmask = (mask | (1<<i));
		
		PLL temp = fun(pos+1, nmask, boro|(i>lo), choto|(i<hi));
		if(temp.second>0) {
			ret.first += (((i*power[pos])%mod) * (temp.second%mod))%mod;
			ret.first %= mod;
			ret.first += temp.first;
			ret.first %= mod;
			ret.second += temp.second;
			ret.second %= mod;
		}
	}
	return ret;
}
int main() {
	cin>>l>>r>>k;
	
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
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	n = b.size();
	power[n-1] = 1;
	for(int i=n-2; i>=0; i--) {
		power[i] = power[i+1]*10;
		power[i] %= mod;
	}
	
	memset(vis, false, sizeof(vis));
	PLL ans = fun(0,0,0,0);
	cout<<ans.first<<endl;
	
	return 0;
}
