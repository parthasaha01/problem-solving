#include<iostream>
using namespace std;

const int N = 1058576, LOGN = 22;
long long v[N][LOGN];
long long a[N], p, n, q;

void build(int i, int b, int e)
{
	if(b == e) return;
	int m = (b + e)/2;
	v[m][i] = a[m]%p;
	for(int j = m-1; j >= b; j--){
		v[j][i] = (v[j+1][i]*a[j])%p;
	}
	if(m + 1 <= e){
		v[m+1][i] = a[m+1]%p;
		for(int j = m+2; j <= e; j++){
			v[j][i] = (v[j-1][i]*a[j])%p;
		}
	}
	build(i+1, b, m);
	build(i+1, m+1, e);
}

int main()
{
    //cout << (3^12) << endl;
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin>>t;
	while(t--)
    {
		cin>>n>>p>>q;

		for(int i = 0; i < n; i++) cin>>a[i];

		int LEV = __builtin_clz(n);
		int SZ = 1<<(31-LEV);
		if(n != SZ)LEV--, SZ *= 2;

		build(0, 0, SZ-1);

		int bl = q/64 + 2;
		long long b[bl];
		for(int i = 0; i < bl; i++) cin>>b[i];

		long long prev = -1;
		int l, r;

		for(int i = 0; i < q; i++)
        {
			if(i%64 == 0){
				l = (b[i/64] + (prev+1)%p)%n;
				r = (b[i/64 + 1] + (prev+1)%p)%n;
			}
			else{
				l = (l + (prev+1)%p)%n;
				r = (r + (prev+1)%p)%n;
			}
			if(l > r) swap(l, r);
			if(l == r){
				prev = a[l]%p;
				continue;
			}

			//l=3,r=12;
			int cnt = __builtin_clz(l^r);

			int lev = cnt-LEV-1;
			//printf("l=%d r=%d l^r=%d cnt=%u LEV=%d lev=%u\n",l,r,l^r,cnt,LEV,lev);
            //getchar();
			prev = (v[r][lev]*v[l][lev])%p;
		}

		cout<<(prev+1)%p<<endl;

		for(int i = 0; i < SZ; i++)a[i] = 0;
	}
	return 0;
}
