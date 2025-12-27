#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll DigitSum(ll n) {
	ll sum = 0;
	while(n!=0){
		sum += (n%10);
		n /= 10;
	}
	return sum;
}
ll solve(ll n) {
	if(n<=0) return 0LL;
	if((n+1)%10==0){
		ll k = (n+1)/10;
		return  10LL* solve(n/10) + (45LL*k);
	}else {
		return solve(n-1) + DigitSum(n);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll a,b;
	while(cin>>a>>b) {
		if(a==-1 && b==-1)break;
		ll ans = solve(b) - solve(a-1);
		cout<<ans<<endl;
	}

	return 0;
}

/*
The idea by Thanh Trung Nguyen is certainly right 
(and also applicable to more difficult problems) 
but I prefer approaching problems like this one from a slightly different angle.
 Or, more precisely, from the opposite end of the number.

Imagine that you listed all the numbers from 0 to 10k-1, for some k.
Look at the last digit. It cycles through 0-9, hence you have  k copies 
of each digit and thus their sum is 45k.

Now erase the last digit of each number and look at what remained. 
You are now counting from 0 to k-1, but each number is listed 10 times. 
How to sum all those digits? Recursively, of course.

And what if your current n isn't of the form 10k-1? 
Just process the last number separately, you'll soon get to such an n.

The resulting code is really really short and simple:

def solve(n): # sum all digits in all numbers in [0,n)
    if n<=0: return 0
    if n%10==0: return 10 * solve(n//10) + 45 * (n//10)
    return solve(n-1) + sum(int(x) for x in str(n-1))
for test in range(int(input())):
    a, b = [ int(x) for x in input().split() ]
    print( solve(b+1) - solve(a) )


P.S.: The question asks about DP but in fact no DP is necessary, 
this program never solves the same thing twice.

*/