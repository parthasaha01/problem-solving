#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
const int BLOCK_SIZE = 320;
int N,aa[mx],bb[mx],tree[4*mx];
ll ans[mx],sum;
map<int,int>mp;
struct dt{
    int l,r,x,b;
}qr[mx];
bool cmp(dt p,dt q)
{
    if(p.b==q.b)return p.r<q.r;
    return p.b<q.b;
}
void update(int nd,int b,int e,int x,int v)
{
    if(b==x&&e==x){
        tree[nd]+=v;
        return;
    }

    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;

    if(x<=md)update(lf,b,md,x,v);
    else update(rg,md+1,e,x,v);

    tree[nd] = tree[lf]+tree[rg];
}
int query(int nd,int b,int e,int x,int y)
{
    if(b>y || e<x || y<x)return 0;
    if(b>=x && e<=y) return tree[nd];

    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;

    int p1 = query(lf,b,md,x,y);
    int p2 = query(rg,md+1,e,x,y);
    return p1+p2;
}

void Addright(int x)
{
    int v = query(1,1,N,aa[x]+1,N);
    sum += v;
   // printf("add x=%d a[x]=%d mp[x]=%d v=%d mp[x]=%d\n",x,aa[x],mp[x],v,sum);
   // printf("v=%d sum=%lld\n",v,sum);
    update(1,1,N,aa[x],1);
}
void Removeright(int x)
{
    //printf("rem x=%d a[x]=%d mp[x]=%d ",x,aa[x],mp[x]);
    int v = query(1,1,N,aa[x]+1,N);
    sum -= v;
    //printf("v=%d sum=%lld\n",v,sum);
    update(1,1,N,aa[x],-1);
    //printf("rem x=%d a[x]=%d mp[x]=%d v=%d mp[x]=%d\n",x,aa[x],mp[x],v,sum);
}
void Addleft(int x)
{
    //printf("add x=%d a[x]=%d mp[x]=%d ",x,aa[x],mp[x]);
    int v = query(1,1,N,1,aa[x]-1);
    sum += v;
   // printf("add x=%d a[x]=%d mp[x]=%d v=%d mp[x]=%d\n",x,aa[x],mp[x],v,sum);
   // printf("v=%d sum=%lld\n",v,sum);
    update(1,1,N,aa[x],1);
}
void Removeleft(int x)
{
    //printf("rem x=%d a[x]=%d mp[x]=%d ",x,aa[x],mp[x]);
    int v = query(1,1,N,1,aa[x]-1);
    sum -= v;
    //printf("v=%d sum=%lld\n",v,sum);
    update(1,1,N,aa[x],-1);
    //printf("rem x=%d a[x]=%d mp[x]=%d v=%d mp[x]=%d\n",x,aa[x],mp[x],v,sum);
}
int main()
{
    int n,q; scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&aa[i]);
        bb[i]=aa[i];
    }

    sort(bb+1,bb+n+1);

    int k=0;
    for(int i=1; i<=n; i++){
        if(mp[bb[i]]==0)mp[bb[i]]=++k;
    }

    N = k;

    for(int i=1; i<=n; i++){
        aa[i] = mp[aa[i]];
    }

//    for(int i=1; i<=n; i++){
//        printf("%d ",mp[aa[i]]);
//    }
//    printf("\n");

    for(int i=1; i<=q; i++)
    {
        int l,r; scanf("%d%d",&l,&r);
        qr[i].l = l;
        qr[i].r = r;
        qr[i].x = i;
        qr[i].b = (l/BLOCK_SIZE)+1;
    }

    sort(qr+1,qr+q+1,cmp);

    int l=1,r=0;
    //update(1,1,n,mp[1],1);

    for(int i=1; i<=q; i++)
    {
        //printf("l=%d r=%d ql=%d qr=%d\n",l,r,qr[i].l,qr[i].r);
        while(r<qr[i].r) Addright(++r);
        while(r>qr[i].r) Removeright(r--);
        while(l<qr[i].l) Removeleft(l++);
        while(l>qr[i].l) Addleft(--l);
        ans[qr[i].x] = sum;
    }

    for(int i=1; i<=q; i++){
        printf("%lld\n",ans[i]);
    }

    return 0;
}

