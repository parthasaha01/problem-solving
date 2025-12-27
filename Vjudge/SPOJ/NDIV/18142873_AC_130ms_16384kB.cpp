#include <bits/stdc++.h>
using namespace std;
bool isPrime[31625];
vector<int>prime;

void sieve() {
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i=2; i<=31624; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j=i+i; j<=31624; j+=i) {
				isPrime[j] = false;
			}
		}
	}
}
int NOD(int x) {
	int ret = 1;
	for(int i=0; i<prime.size() && prime[i]*prime[i]<=x; i++) {
		int k = 0;
		while (x%prime[i]==0) {
			k++;
			x /= prime[i];
		}
		ret *= (k+1);
	}
	if(x>1) ret *= 2;

	return ret;
}
int solve (int a,int b,int n) {
	int cnt = 0;
	for (int x=a; x<=b; x++) {
		if(NOD(x)==n) {
			cnt++;
		}
	}

	return cnt;
}
int main() {
	sieve();

	int a,b,n; scanf("%d%d%d",&a,&b,&n);
	printf("%d\n",solve(a,b,n));

	return 0;
}