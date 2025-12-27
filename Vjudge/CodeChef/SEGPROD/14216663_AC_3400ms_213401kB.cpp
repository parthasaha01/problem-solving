#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(0)
#define MAXN 1000000
#define LL long long
using namespace std;

struct data{
	vector<LL> left;		//  left[i]	-> [M-1-i, M-1]
	vector<LL> right;		// right[i] -> [M, M+i]
};

LL n, P, Q;
LL A[MAXN];
LL B[312502];
data ST[4*MAXN];


void build(int node=1, int l=0, int r=n-1)
{
	if(l == r){
		ST[node].left.assign(1, A[l]);
	}
	else
	{
		int m = (l+r)/2;
		ST[node].left.resize(m-l+1);
		ST[node].right.resize(r-m);

		ST[node].left[0] = A[m];
		for(int i=m-1,j=1;i>=l;i--,j++){
			ST[node].left[j] =  (ST[node].left[j-1] * A[i])%P;
		}

        if(r>m){
            ST[node].right[0] = A[m+1];
            for(int i=m+2,j=1;i<=r;i++,j++){
                ST[node].right[j] =  (ST[node].right[j-1] * A[i])%P;
            }
        }

		build(2*node, l, m);
		build(2*node+1, m+1, r);
	}
}

LL query(int x, int y, int node=1, int l=0, int r=n-1)
{
	int m = (l+r)/2;
	if(x <= m && m <= y)
	{
		LL ans = ST[node].left[m-x];
		if(y>m)
		{
			ans *= ST[node].right[y-m-1];
			ans %= P;
		}
		return ans;
	}
	else if(l <= x && y <= m)
		return query(x, y, 2*node, l, m);
	else
		return query(x, y, 2*node+1, m+1, r);
}

int main()
{
	FAST_IO;
	int t; cin>>t;
	while(t--)
	{
		cin>>n>>P>>Q;
		for(int i=0;i<n;i++) cin>>A[i];
		for(int i=0, x = (Q>>6) + 2;i<x;i++) cin>>B[i];

		build();

		LL x = 0, l, r;
		for(int i=0;i<Q;i++)
		{
			if(i%64 == 0){
				l = (B[i>>6] + x) % n;
				r = (B[(i>>6) + 1] + x) % n;
			}
			else{
				l = (l + x) % n;
				r = (r + x) % n;
			}
			if(l > r) swap(l, r);

			x = (query(l, r) + 1) % P;
		}

		cout<<x<<'\n';
	}
	return 0;
}
