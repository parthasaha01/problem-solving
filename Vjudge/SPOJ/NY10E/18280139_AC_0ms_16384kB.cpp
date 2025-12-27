#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[64][10];
ll fun(int pos, int prev) {
	if(pos<0) return 1LL;
	ll &ret = dp[pos][prev];
	if(ret != -1) return ret;
	ret = 0;
	int lo = prev, hi = 9;
	for(int i=lo; i<=hi; i++) {
		ret += fun(pos-1, i);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));
	int tt; cin>>tt;
	for(int ks=1; ks<=tt; ks++) {
		int t, n; cin>>t>>n;
		ll ans = fun(n-1,0);
		cout<<t<<" "<<ans<<endl;
	}
	return 0;
}