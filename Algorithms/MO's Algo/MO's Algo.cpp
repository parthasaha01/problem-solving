#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int blk_sz,a[mx];
ll sum;
struct dt{
    int lf,rg,id,bl,ans;
}qr[mx];
bool cmp1(dt x,dt y)
{
    if(x.bl==y.bl)return x.rg<y.rg;
    else return x.bl<y.bl;
}
bool cmp2(dt x, dt y)
{
    return x.id < y.id;
}
void Add(int id)
{
    sum+=a[id];
}
void Remove(int id)
{
    sum-=a[id];
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);

        int n,q; scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        blk_sz = sqrt(n);

        for(int i=0; i<q; i++)
        {
            int lf,rg; scanf("%d%d",&lf,&rg);
            qr[i].lf = lf;
            qr[i].rg = rg;
            qr[i].id = i;
            qr[i].bl = lf/blk_sz;
        }

        sort(qr,qr+q,cmp1);

        int lf=0,rg=-1;
        sum = 0;

        for(int i=0; i<q; i++)
        {
            while(lf>qr[i].lf) Add(--lf);
            while(rg<qr[i].rg) Add(++rg);
            while(lf<qr[i].lf) Remove(lf++);
            while(rg>qr[i].rg) Remove(rg--);
            qr[i].ans = sum;
        }

        sort(qr,qr+q,cmp2);

        for(int i=0; i<q; i++)
        {
            printf("%d\n",qr[i].ans);
        }
    }

    return 0;
}
