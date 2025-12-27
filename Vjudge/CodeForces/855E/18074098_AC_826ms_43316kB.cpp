#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[61][1025][11][2][2][2];
string a,b;
ll fun(int pos, int mask, int base, int boro, int choto,int suru) {
	if(pos<0) {
		if(mask==0) return 1LL;
		return 0LL;
	}
	
	ll &ret = dp[pos][mask][base][boro][choto][suru];
	if(ret != -1 && choto && boro) return ret;
	ret = 0;
	
	int lo = 0, hi = base-1;
	if(!boro) lo = a[pos]-'0';
	if(!choto) hi = b[pos]-'0';
	
	for(int i=lo; i<=hi; i++) {
		int nmask = mask;
		if(i>0 || suru) nmask = mask^(1<<i);
		ret += fun(pos-1, nmask, base, boro|(i>lo), choto|(i<hi), suru|(i>0));
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	memset(dp,-1,sizeof(dp));
	int q; cin>>q;
	while(q--) {
		ll base,l,r; cin>>base>>l>>r;
		
		a.clear(); b.clear();
		
		while(r!=0) {
			b += (r%base) + '0';
			r /= base;
		}
		
		while(l!=0) {
			a += (l%base) + '0';
			l /= base;
		}
		
		while(a.size() < b.size()) a += '0';
		
		ll ans = fun(b.size()-1,0,base,0,0,0);
		cout<<ans<<endl;
	}
	
	return 0;
}
	 
