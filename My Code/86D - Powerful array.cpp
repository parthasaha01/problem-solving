#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200005
struct dt{
    int x,y,id,block;
}qr[mx];
int cnt[1000005],a[mx];
ll ans[mx],sum;
bool cmp(dt p,dt q)
{
    if(p.block==q.block)return p.y<q.y;
    return p.block < q.block;
}
void Add(int x)
{
    sum += (cnt[a[x]]+cnt[a[x]]+1LL)*a[x];
    cnt[a[x]]++;
}
void Remove(int x)
{
    sum -= (cnt[a[x]]+cnt[a[x]]-1LL)*a[x];
    cnt[a[x]]--;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);
    int block = sqrt(n);

    for(int i=0; i<q; i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        qr[i].x = x;
        qr[i].y = y;
        qr[i].id = i;
        qr[i].block = x/block;
    }

    sort(qr,qr+q,cmp);

    sum= 0;
    int x=1,y=0;
    for(int i=0; i<q; i++)
    {
        while(x<qr[i].x) Remove(x++);
        while(x>qr[i].x) Add(--x);
        while(y<qr[i].y) Add(++y);
        while(y>qr[i].y) Remove(y--);

        ans[qr[i].id] = sum;
    }

    for(int i=0; i<q; i++){
        printf("%lld\n",ans[i]);
    }

    return 0;
}
