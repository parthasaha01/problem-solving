#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[31][2][2][2];
ll dpA[31][2], dpB[31][2];
string a,b,k;
ll funA(int pos, int chotoA) {
	if(pos==31) return 1LL;
	ll &ret = dpA[pos][chotoA];
	if(ret != -1) return ret;
	ret = 0LL;
	int lo = 0, hi = 1;
	if(!chotoA) hi = a[pos]-'0';
	for(int i=lo; i<=hi; i++) {
		ret += funA(pos+1,chotoA|(i<hi));
	}
	return ret;
}
ll funB(int pos, int chotoB) {
	if(pos==31) return 1LL;	
	ll &ret = dpB[pos][chotoB];
	if(ret != -1) return ret;
	ret = 0LL;
	int lo = 0, hi = 1;
	if(!chotoB) hi = b[pos]-'0';
	for(int i=lo; i<=hi; i++) {
		ret += funB(pos+1,chotoB|(i<hi));
	}
	return ret;
}
ll fun(int pos, int chotoA, int chotoB, int chotoK) {
	if(pos==31) return 1LL;
	ll &ret = dp[pos][chotoA][chotoB][chotoK];
	if(ret != -1) return ret;
	ret = 0LL;

	int loA = 0, hiA = 1;
	if(!chotoA) hiA = a[pos]-'0';
	int loB = 0, hiB = 1;
	if(!chotoB) hiB = b[pos]-'0';

	for(int i=loA; i<=hiA; i++) {
		for(int j=loB; j<=hiB; j++) {
			char kk = (i&j)+'0';
			if(chotoK==0 && kk>k[pos]) continue;
			ret += fun(pos+1, chotoA|(i<hiA), chotoB|(j<hiB), chotoK|(kk<k[pos]));
		}
	}
	return ret;
}
void MakeBinaryString(int A,int B,int K) {
	a.clear(); b.clear(); k.clear();
	while(A!=0) {
		a += (A%2)+'0';
		A /= 2;
	}
	while(B!=0) {
		b += (B%2)+'0';
		B /= 2;
	}
	while(K!=0) {
		k += (K%2)+'0';
		K /= 2;
	}

	while(a.size()<31) a += '0';
	while(b.size()<31) b += '0';
	while(k.size()<31) k += '0';

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(k.begin(), k.end());
}
int main() {
  	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tt,ks=0; cin>>tt;
  	while(tt--) {
		int A,B,K; cin>>A>>B>>K;
		MakeBinaryString(A-1,B-1,K-1);

		memset(dpA,-1,sizeof(dpA));
		ll retA = funA(0,0);

		memset(dpB,-1,sizeof(dpB));
		ll retB = funB(0,0);

		memset(dp,-1,sizeof(dp));
		ll ans = fun(0,0,0,0);
		
		cout<<"Case #"<<++ks<<": "<<ans<<endl;
	}
	return 0;
}