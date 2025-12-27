#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int thresh = 250*10;
int dp[251][250*10*2][2][2];
string s;
int fun(int pos, int diff, int choto, int small) {
	if(pos==s.size()) {
		if(small==1 && diff>0) return 1;
		else return 0;
	}

	int &ret = dp[pos][diff+thresh][choto][small];
	if(ret != -1) return ret;
	ret = 0;

	int lo = 0, hi = 9;
	if(choto==0) hi = s[pos]-'0';

	for(int i=lo; i<=hi; i++) {
		for(int j=0; j<10; j++) {
			if(small==0 && j>i) break;
			ret += fun(pos+1, diff+(i-j), choto|(i<hi), small|(j<i))%mod;
			ret %= mod;
		}
	}

	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>s;

	memset(dp, -1, sizeof(dp));
	int ans = fun(0,0,0,0);
	cout<<ans<<endl;

	return 0;
}