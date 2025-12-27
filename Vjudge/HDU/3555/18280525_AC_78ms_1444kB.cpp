#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
ll dp[19][2][10];
ll wp[19][2];
string a;
ll way(int pos, int choto) {
	if(pos==19)return 1LL;

	ll &ret = wp[pos][choto];
	if(ret != -1 && choto) return ret;
	ret = 0;

	int lo = 0, hi = 9;
	if(!choto) hi = a[pos]-'0';

	for(int i=lo; i<=hi; i++) {
		ret += way(pos+1, choto | (i<hi));
	}
	return ret;	
}
ll fun(int pos, int choto, int prev) {
	if(pos==19) {
		return 0LL;
	}

	ll &ret = dp[pos][choto][prev];
	if(ret != -1 && choto) return ret;
	ret = 0;

	int lo = 0, hi = 9;
	if(!choto) hi = a[pos]-'0';

	for(int i=lo; i<=hi; i++) {
		if(prev==4 && i==9) {
			ll temp = way(pos+1, choto|(i<hi));
			ret += temp + fun(19, choto|(i<hi), i);
		}else {
			ret += fun(pos+1, choto|(i<hi), i);
		}

	}
	return ret;	
}
int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	memset(wp, -1, sizeof(wp));

	int tt; cin>>tt;
	while(tt--) {
		cin>>a;
		while(a.size()<19) a = "0"+a;
		ll ret = way(0,0);
		ll ans = fun(0, 0, 0);
		cout<<ans<<endl;
	}
	return 0;
}