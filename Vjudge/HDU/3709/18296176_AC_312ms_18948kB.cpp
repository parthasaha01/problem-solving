#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[19][2][2][19][1550];
string a,b;
ll fun(int pos, int boro, int choto, int pivot, int sum) {
	if(sum<0) return 0LL; 
	if(pos==b.size()){
		if(sum == 0) return 1LL;
		return 0LL; 
	}

	ll &ret = dp[pos][boro][choto][pivot][sum];
	if(ret != -1) return ret;
	ret = 0;

	int lo = 0, hi = 9;
	if(!boro) lo = a[pos]-'0';
	if(!choto) hi = b[pos]-'0';
	
	for(int i=lo; i<=hi; i++) {
		if(pos<pivot) {
			ret += fun(pos+1, boro|(i>lo), choto|(i<hi), pivot, sum+(i*(pivot-pos)));
		}else if(pos>pivot) {
			ret += fun(pos+1, boro|(i>lo), choto|(i<hi), pivot, sum-(i*(pos-pivot)));
		}else {
			ret += fun(pos+1, boro|(i>lo), choto|(i<hi), pivot, sum);
		}
	}
	return ret;
}
ll solve(ll l, ll r) {
	if(l>r) swap(l,r);

	if(l==0 && r==0) return 1;

	ll ans = 0;
	if(l==0){
		ans += 1;
		l = 1;
	} 

	a.clear(); b.clear();
	while(l != 0) {
		a += (l%10) + '0';
		l /= 10;
	}
	while(r != 0) {
		b += (r%10) + '0';
		r /= 10;
	}

	while(a.size()<b.size()) a += '0';

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	memset(dp, -1, sizeof(dp));

	for(int i=0; i<b.size(); i++) {
		ans += fun(0, 0, 0, i, 0);
	}
	
	return ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tt,ks=0; cin>>tt;
	while(tt--) {
		ll l,r; cin>>l>>r;
		cout << solve(l,r) << endl;
		//cout << "Case " << ++ks << ": "<< solve(l,r) << endl;
	}
	
	return 0;
}