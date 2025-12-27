#include<bits/stdc++.h>
using namespace std;
#define mx 200005
struct dt{
    int x,y,id,block;
}qr[mx];
int cnt[1000005],a[30005],ans[mx],sum;
bool cmp(dt p,dt q)
{
    if(p.block==q.block)return p.y<q.y;
    return p.block < q.block;
}
void Add(int x)
{
    cnt[a[x]]++;
    if(cnt[a[x]]==1)sum++;
}
void Remove(int x)
{
    cnt[a[x]]--;
    if(cnt[a[x]]==0)sum--;
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    int block = sqrt(n);

    int q; scanf("%d",&q);
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
        printf("%d\n",ans[i]);
    }

    return 0;
}
