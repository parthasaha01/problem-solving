#include<bits/stdc++.h>
using namespace std;
int dp[51][2][2][17][17][17];
const int mod = 1000000007;
string a,b;
int fun(int pos, int boro, int choto, int three, int six, int nine) {
	if(three>16 || six>16 || nine>16) return 0;
	if(pos<0) {
		if(three>0 && three==six && six==nine) return 1;
		return 0;
	}
	
	int &ret = dp[pos][boro][choto][three][six][nine];
	if(ret != -1 && boro && choto) return ret;
	ret = 0;
	
	int lo = (boro) ? 0 : a[pos]-'0';
	int hi = (choto) ? 9 : b[pos]-'0';
	
	for(int i=lo; i<=hi; i++) {
		ret += fun(pos-1, boro|(i>lo), choto|(i<hi), three+(i==3), six+(i==6), nine+(i==9))%mod;
		ret %= mod;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int tt; cin>>tt;
	while(tt--) {
		cin>>a>>b;
		string temp;
		int d = b.size() - a.size();
		while(d--) temp+='0';
		a = temp+a;
		
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		
		int ans = fun(b.size(), 0, 0, 0, 0, 0);
		cout<<ans<<endl;
	}
	return 0;
}
