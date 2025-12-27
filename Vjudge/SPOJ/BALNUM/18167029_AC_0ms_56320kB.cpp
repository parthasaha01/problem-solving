#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][2][2][2][32][32][32];
int mp[10];
string a,b;
ll fun(int pos, int suru, int boro, int choto, int odd, int even, int maskEven) {
	if(pos==20) {	
		if(odd==0) {
			for(int i=0; i<5; i++) {
				if(maskEven & (1<<i)) {
					if((even & (1<<i))==0) return 0LL;
				}
			}
			return 1LL;
		} 
		return 0LL;
	}

	ll &ret = dp[pos][suru][boro][choto][odd][even][maskEven];
	if(ret != -1 && boro && choto) return ret;
	ret = 0;

	int lo = 0, hi = 9;
	if(!boro) lo = a[pos]-'0';
	if(!choto) hi = b[pos]-'0';

	for(int i=lo; i<=hi; i++) {
		if(i==0 && suru==0) {
			ret += fun(pos+1,suru|(i>0),boro|(i>lo),choto|(i<hi),even,odd,maskEven);
		}else {
			if(i%2==0){
				ret += fun(pos+1,suru|(i>0),boro|(i>lo),choto|(i<hi),odd,even^(1<<mp[i]),maskEven|(1<<mp[i]));
			}else{
				ret += fun(pos+1,suru|(i>0),boro|(i>lo),choto|(i<hi),odd^(1<<mp[i]),even,maskEven);
			}
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));

	mp[0] = 0, mp[2] = 1, mp[4] = 2, mp[6] = 3, mp[8] = 4;
	mp[1] = 0, mp[3] = 1, mp[5] = 2, mp[7] = 3, mp[9] = 4;

	int tt; cin>>tt;
	while(tt--) {
		cin>>a>>b;
		while(a.size()<20) a = "0"+a;
		while(b.size()<20) b = "0"+b;

		ll ans = fun(0,0,0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}