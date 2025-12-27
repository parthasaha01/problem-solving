#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll wp[17][2][2];
ll dp[17][2][2][10];
string a,b;
ll calc(int pos, int boro, int choto) {
	if(pos<0) return 1LL;

	ll &ret = wp[pos][boro][choto];
	if(ret != -1 && boro && choto) return ret;
	ret = 0;

	int lo = 0, hi=9;
	if(!boro) lo = a[pos]-'0';
	if(!choto) hi = b[pos]-'0';

	for(int i=lo; i<=hi; i++) {
		ret += calc(pos-1, boro|(i>lo), choto|(i<hi));
	}

	return ret;
}
ll fun(int pos, int boro, int choto, int d) {
	if(pos<0) return 0LL;

	ll &ret = dp[pos][boro][choto][d];
	if(ret != -1 && boro && choto) return ret;
	ret = 0;

	int lo = 0, hi=9;
	if(!boro) lo = a[pos]-'0';
	if(!choto) hi = b[pos]-'0';

	for(int i=lo; i<=hi; i++) {
		ll temp = 0;
		if(i==d) temp = calc(pos-1, boro|(i>lo), choto|(i<hi));
		ret += temp + fun(pos-1, boro|(i>lo), choto|(i<hi),d);
	}

	return ret;
}
vector<ll> solve(ll x, ll y) {
	if(x>y)swap(x,y);
	a.clear(); b.clear();
	while(y!=0) {
        int r = y%10;
        y /= 10;
        b += r+'0';
    }
	while(x!=0) {
        int r = x%10;
        x /= 10;
        a += r+'0';
    }
	while(a.size()<b.size()) a += '0';

	calc(b.size()-1, 0, 0);

	vector<ll>ans;
	for(int i=1; i<10; i++) {
		ll ret = fun(b.size(), 0, 0, i);
		ans.push_back(ret);
	}

	return ans;
}
int main() {
	memset(wp,-1,sizeof(wp));
	memset(dp,-1,sizeof(dp));
	ll x,y;
	while (scanf("%lld%lld",&x,&y)) {
		if(x==0 && y==0) break;

		vector<ll>ans = solve(x,y);

		for(int i=0; i<9; i++) {
			if(i==8)printf("%lld\n",ans[i]);
			else printf("%lld ",ans[i]);
		}
	}

	return 0;
}
