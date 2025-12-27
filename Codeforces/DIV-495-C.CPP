#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int n,a[mx],cnt[mx],sum,vis[mx];
ll ans[mx];
struct dt{
    int x,y,id,block;
}qr[mx];
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
void precalc()
{
    int block = sqrt(n);

    for(int i=1; i<n; i++){
        qr[i].x = i+1;
        qr[i].y = n;
        qr[i].id = i;
        qr[i].block = qr[i].x/block;
    }

    sort(qr+1,qr+n,cmp);

    sum= 0;
    int x=1,y=0;
    for(int i=1; i<n; i++)
    {
        while(x<qr[i].x) Remove(x++);
        while(x>qr[i].x) Add(--x);
        while(y<qr[i].y) Add(++y);
        while(y>qr[i].y) Remove(y--);

        ans[qr[i].id] = sum;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    precalc();

    ll ret = 0;
    for(int i=1; i<n; i++)
    {
        if(vis[a[i]]==0){
            ret += ans[i];
            vis[a[i]]=1;
        }
    }

    printf("%I64d\n",ret);

    return 0;
}
