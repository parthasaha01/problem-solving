#include <bits/stdc++.h>
using namespace std;
int dp[9][2][73];
bool isPrime[101];
string s;
void sieve() {
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i=2; i<=100; i++) {
		if(isPrime[i]) {
			for(int j=i+i; j<=100; j+=i) {
				isPrime[j] = false;
			}
		}
	}
}
int fun(int pos, int choto, int sum) {
	if(pos==s.size()) {
		if(isPrime[sum]) return 1;
		else return 0;
	}

	int &ret = dp[pos][choto][sum];
	if(ret != -1) return ret;
	ret = 0;

	int lo = 0, hi = 9;
	if(!choto) hi = s[pos]-'0';

	for(int i=lo; i<=hi; i++) {
		ret += fun(pos+1, choto|(i<hi), sum+i);
	}

	return ret;
}
int solve(int x) {
	if(x<0) return  0;

	s.clear();
    while(x!=0) {
        int r = x%10;
        x /= 10;
        s += r+'0';
    }
    reverse(s.begin(), s.end());

	memset(dp,-1,sizeof(dp));
	int ret = fun(0,0,0);

	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	sieve();

 	int tt; cin>>tt;
  	while(tt--) {
		int a,b; cin>>a>>b;
		if(a>b) swap(a,b);

		int ans = solve(b) - solve(a-1);
		cout<<ans<<endl;
  	}
  	return 0;
}