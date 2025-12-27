#include<bits/stdc++.h>
#define MAXN 1000005
#define LL long long
using namespace std;

struct data
{
    vector<LL> left;		//  left[i]	-> [M-1-i, M-1]
    vector<LL> right;		// right[i] -> [M, M+i]
};

LL n, P, Q;
LL A[MAXN];
LL B[MAXN];
data ST[4*MAXN];


void build(int node, int l, int r)
{
    if(l == r)
    {
        ST[node].left.assign(1,A[l]);
        return;
    }

    int lf = 2*node, rg = 2*node+1;
    int m = (l+r)/2;
    ST[node].left.resize(m-l+1);
    ST[node].right.resize(r-m);

    ST[node].left[0] = A[m];
    for(int i=m-1,j=1; i>=l; i--,j++)
    {
        ST[node].left[j] =  (ST[node].left[j-1] * A[i])%P;
    }

    if(r>m)
    {
        ST[node].right[0] = A[m+1];
        for(int i=m+2,j=1; i<=r; i++,j++)
        {
            ST[node].right[j] =  (ST[node].right[j-1] * A[i])%P;
        }
    }

    build(lf, l, m);
    build(rg, m+1, r);
}

LL query(int x, int y, int node, int l, int r)
{
    int lf = 2*node, rg = 2*node+1;
    int m = (l+r)/2;
    if(x <= m && m <= y)
    {
        LL ans = 1LL;
        ans = ST[node].left[m-x];
        if(y>m)
        {
            ans *= ST[node].right[y-m-1];
            ans %= P;
        }
        return ans%P;
    }

    if(l <= x && y <= m)
        return query(x, y, lf, l, m);
    else
        return query(x, y, rg, m+1, r);
}

int main()
{
    //FAST_IO;
    int tt;
    scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%lld %lld %lld",&n,&P,&Q);
        for(int i=0; i<n; i++)
            scanf("%lld",&A[i]);
        for(int i=0, x = (Q/64) + 2; i<x; i++)
            scanf("%lld",&B[i]);

        build(1,0,n-1);

        LL x = 0, l=0, r=0;
        for(int i=0; i<Q; i++)
        {
            if(i%64 == 0)
            {
                l = (B[i/64] + x) % n;
                r = (B[(i/64) + 1] + x) % n;
            }
            else
            {
                l = (l + x) % n;
                r = (r + x) % n;
            }
            if(l > r)
                swap(l, r);

            x = (query(l, r,1,0,n-1) + 1) % P;
        }

        printf("%lld\n",x);
    }
    return 0;
}
