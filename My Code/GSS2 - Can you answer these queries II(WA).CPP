#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 10000000000000000LL
#define MAXN 100005
#define lf nd<<1
#define rg (nd<<1)+1
#define m (int)((b+e)>>1)
#define N tree[nd]
#define L tree[lf]
#define R tree[rg]

struct qry{
    int x,y,i;
}qr[MAXN];
bool cmp(qry A, qry B){
    if(A.y==B.y)return A.x > B.x;
    return A.y < B.y;
}

int n,a[MAXN],pre[2*MAXN],cnt[MAXN];
ll ans[MAXN];
struct data{
    ll prefix,suffix,infixx,sum;
}tree[4*MAXN];

data maxData(data x, data y){
    data z;
    z.prefix = max(x.prefix, x.sum + y.prefix);
    z.suffix = max(y.suffix, y.sum + x.suffix);
    z.infixx = max(max(x.infixx, y.infixx), x.suffix + y.prefix);
    z.sum    = x.sum + y.sum;
    return z;
}
void update(int nd,int b,int e,int x,int v){
    if(b==e && b==x){
        N.prefix = N.suffix = N.infixx = N.sum = v;
        return;
    }
    if(x<=m)update(lf,b,m,x,v);
    else update(rg,m+1,e,x,v);
    N = maxData(L,R);
}
data query(int nd,int b,int e,int x,int y){
    if(b==x && e==y) return tree[nd];
    if(y<=m) return query(lf,b,m,x,y);
    else if(x>m) return query(rg,m+1,e,x,y);
    else{
        data f1 = query(lf,b,m,x,m);
        data f2 = query(rg,m+1,e,m+1,y);
        return maxData(f1,f2);
    }
}

ll solve(int x,int y){
    data ret = query(1,1,n,x,y);
    ll res = max(ret.prefix, max(ret.suffix, ret.infixx));
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    int q; scanf("%d",&q);
    for(int i=1; i<=q; i++){
        int x,y; scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        qr[i].x = x;
        qr[i].y = y;
        qr[i].i = i;
        cnt[y]++;
    }

    sort(qr+1,qr+q+1,cmp);

    int cur = 1;
    for(int i=1; i<=n; i++){
        int v = a[i];
        int vv = a[i];
        if(vv<0)vv = abs(vv)+100000;

        if(pre[vv]!=0){
            update(1,1,n,pre[vv],0);
        }

        update(1,1,n,i,v);
        pre[vv] = i;

        for(int j=1; j<=cnt[i]; j++){
            int x = qr[cur].x;
            int y = qr[cur].y;
            ll res = solve(x,y);
            ans[qr[cur].i] = res;
            cur++;
        }
    }

    for(int i=1; i<=q; i++){
        printf("%lld\n",ans[i]);
    }

    return 0;
}

/*

8
1 2 -1 3 2 -1 2 -1
2
1 8
2 8

*/

