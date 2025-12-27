/*
Author :: Shourov Chowdhury
............SUST_MATH14..........
*/
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>

#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define II() ( { int a ; read(a) ; a; } )
#define LL() ( { Long a ; read(a) ; a; } )
#define DD() ({double a; scanf("%lf", &a); a;})
#define D(x) cout << #x " is " << x << endl
#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

using namespace std;

typedef long long Long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<string> VS;

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
    x*=sgn; return ~c;
}

const int INF = 2000000009;
const int MX = 100005;
const double EPS = 1e-9;
const Long MOD = 1000000009;

/**********************Code starts here*********************************/

char s[MX];

Long bigmod(Long b, Long p)
{
	if (p==0) return 1LL;
	if (p==1) return b%MOD;
	Long x = bigmod(b,p/2LL);
	x = (x*x)%MOD;
	if (p%2) x = (x*b)%MOD;
	return x;
}
int main()
{
	//std::ios_base::sync_with_stdio(false);

	Long n=LL(),a=LL(),b=LL(),k=LL();
	scanf("%s",s);
	Long ans = 0;
	Long x = (n+1)/k;
	//D(x);
	Long r = (bigmod(b,k) * (bigmod(bigmod(a,k),MOD-2)))%MOD;
	//D(r);
	Long sum;
	if (r==0) sum = 0;
	else if (r==1) sum = x%MOD;
	else {
		sum = (((bigmod(r,x)-1+MOD)%MOD)*bigmod(r-1,MOD-2))%MOD;
	}
	//D(sum);
	for (int i = 0;i<k;i++){
		Long temp = (bigmod(a,n-i)*bigmod(b,i))%MOD;
		temp = (temp*sum)%MOD;
		//D(temp);
		if (s[i]=='+'){
			ans = (ans+temp)%MOD;
		}
		else {
			ans =(( (ans - temp)%MOD)+MOD)%MOD;
		}
	}
	printf("%lld\n",ans );
	return 0;
}
