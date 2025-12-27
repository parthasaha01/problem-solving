#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PLL pair<ll,ll>
PLL dp[16][2][2];
string a,b;
PLL fun(int pos, int boro, int choto) {
	if(pos<0) return make_pair(0LL, 1LL);
	
	PLL &ret = dp[pos][boro][choto];
	if(ret.first != -1 && boro && choto) return ret;
	ret = make_pair(0,0);
	
	int lo = 0, hi = 9;
	if(boro==0) lo = a[pos]-'0';
	if(choto==0) hi = b[pos]-'0';
	
	for(int i=lo; i<=hi; i++) {
		PLL temp = fun(pos-1, boro|(i>lo), choto|(i<hi));
		
		ret.first += i*temp.second;
		ret.first += temp.first;
		ret.second += temp.second;
;	}
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
		
		PLL ans = fun(b.size()-1, 0, 0);
		cout<<ans.first<<endl;
		
		a.clear(); b.clear();
	}
	return 0;
}