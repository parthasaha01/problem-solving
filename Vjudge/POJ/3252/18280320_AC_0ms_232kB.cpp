#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
int dp[32][2][2][2][64];
string a,b;
ll fun(int pos, int suru, int boro, int choto, int cnt) {
	if(pos<0){
		if(cnt<0) return 0;
		return 1;
	}

	int &ret = dp[pos][suru][boro][choto][cnt+32];
	if(ret != -1) return ret;
	ret = 0;

	int lo = 0, hi = 1;
	if(!boro) lo = a[pos]-'0';
	if(!choto) hi = b[pos]-'0';
	
	for(int i=lo; i<=hi; i++) {
		if(suru==0 && i==0){
			ret += fun(pos-1, suru|(i>0), boro|(i>lo), choto|(i<hi), cnt);
		}else {
			if(i==0) {
				ret += fun(pos-1, suru|(i>0), boro|(i>lo), choto|(i<hi), cnt+1);
			}else{
				ret += fun(pos-1, suru|(i>0), boro|(i>lo), choto|(i<hi), cnt-1);
			}
		}
	}
	return ret;
}
int solve(int l, int r) {
	if(l>r) swap(l,r);
	memset(dp, -1, sizeof(dp));

	a.clear(); b.clear();
	while(l != 0) {
		a += (l%2) + '0';
		l /= 2;
	}
	while(r != 0) {
		b += (r%2) + '0';
		r /= 2;
	}

	while(a.size()<b.size()) a += '0';

	int ans = fun(b.size()-1, 0, 0, 0, 0);

	return ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int l,r; cin>>l>>r;
	cout << solve(l,r) << endl;

	return 0;
}