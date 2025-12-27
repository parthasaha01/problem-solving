#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll dp[90][2],ans;
bool vis[90][2];
string s;
ll fun(int pos,int prev) {
	if(pos==90) return 1LL;

	if(vis[pos][prev]) return dp[pos][prev];
	vis[pos][prev] = true;

	ll ret = 0;
	ret += fun(pos+1,0);
	if(prev != 1) ret += fun(pos+1,1);

	return dp[pos][prev] = ret;
}
void path(int pos,int prev) {
	if(pos==90){
		ans += 1;
		return;
	}

	if(s[pos]=='0') {
		path(pos+1,0);
	}else {
		ans += fun(pos+1,0);
		path(pos+1,1);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(vis,false,sizeof(vis));
	ll ret = fun(0,0);
	//cout << ret << endl;

	int tt; cin>>tt;
	for(int ks=1; ks<=tt; ks++) {
		cin>>s;
		while(s.size()<90) s = "0"+s;

		ans = 0;
		path(0,0);
		ans--; //for zero
		cout<<"Case "<<ks<<": "<<ans<<endl;
	}
	return 0;
}