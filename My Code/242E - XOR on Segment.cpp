#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int tree[4*MAXN][22],lazy[4*MAXN];
int n,a[MAXN];
long long base[45];
void Merge(int nd,int b,int e)
{
    int m = (b+e)/2;
    int lf = 2*nd, rg = 2*nd+1;
    for(int i=0; i<22; i++){
        tree[nd][i]  = tree[lf][i]+tree[rg][i];
    }
}
void build(int nd,int b,int e)
{
    if(b==e){
        for(int i=0; i<22; i++){
            if(a[b]&(1<<i)){
                tree[nd][i] = 1;
            }
        }
        return;
    }
    int lf=2*nd, rg=2*nd+1, m=(b+e)/2;
    build(lf,b,m);
    build(rg,m+1,e);
    Merge(nd,b,e);
}
void update(int nd,int b,int e,int l,int r,int x)
{
    if(b>r || e<l)return;
    if(b>=l&&e<=r){
        lazy[nd] ^= x;
        for(int i=0; i<22; i++){
            if(x&(1<<i)){
                tree[nd][i] = (e-b+1)-tree[nd][i];
            }
        }
        return;
    }
    if(lazy[nd]!=0){
        int m = (b+e)/2;
        for(int i=0; i<22; i++){
            if(lazy[nd]&(1<<i)){
                tree[nd<<1][i] = (m-b+1)-tree[nd<<1][i];
                tree[(nd<<1)+1][i] = (e-m)-tree[(nd<<1)+1][i];
            }
        }
        lazy[nd<<1] ^= lazy[nd];
        lazy[(nd<<1)+1] ^= lazy[nd];
        lazy[nd] = 0;
    }

    int m = (b+e)/2;
    update(2*nd,b,m,l,r,x);
    update(2*nd+1,m+1,e,l,r,x);
    Merge(nd,b,e);
}
int query(int nd,int b,int e,int i,int l,int r,int x)
{
    if(b>r || e<l)return 0;
    if(b>=l&&e<=r){
        if(x&(1<<i)) return (e-b+1)-tree[nd][i];
        else return tree[nd][i];
    }
    int m = (b+e)/2;
    return query(nd<<1,b,m,i,l,r,lazy[nd]^x) +
           query((nd<<1)+1,m+1,e,i,l,r,lazy[nd]^x);
}
long long solve(int l,int r)
{
    long long ans = 0;
    for(int i=0; i<22; i++){
        int one = query(1,1,n,i,l,r,0);
        ans += one*base[i];
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    build(1,1,n);

    for(long long i=0; i<=40; i++){
        base[i] = 1LL<<i;
    }

    int q; scanf("%d",&q);
    while(q--)
    {
        int t; scanf("%d",&t);
        if(t==1){
            int l,r; scanf("%d%d",&l,&r);
            long long ans = solve(l,r);
            printf("%lld\n",ans);
        }
        else{
            int l,r,x; scanf("%d%d%d",&l,&r,&x);
            update(1,1,n,l,r,x);
        }
    }
    return 0;
}

/*
17
1000000 199999 99999 1097 678736 722866 823736 172363 163783 123 12435 263535 735355 2525 52525 263543 435442
10
1 1 13
2 2 12 19087
1 2 16
2 4 9 101823
1 3 17
2 1 17 108837
1 1 10
2 10 15 152452
1 1 1
1 6 11

*/
