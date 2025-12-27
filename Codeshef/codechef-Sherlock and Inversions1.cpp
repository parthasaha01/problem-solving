#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
const int BLOCK_SIZE = 320;
int n,q,aa[mx],bb[mx],mp[mx],tree[4*mx];
ll ans[mx],sum;
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
        //printf("update x=%d tree=%d\n",x,tree[nd]);
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
    if(b>=x && e<=y){
            //printf("b=%d e=%d s=%d\n",b,e,tree[nd]);
        return tree[nd];
    }

    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;

    int p1 = query(lf,b,md,x,y);
    int p2 = query(rg,md+1,e,x,y);
    return p1+p2;
}
void Add(int x)
{
    //printf("add x=%d a[x]=%d mp[x]=%d ",x,aa[x],mp[x]);
    int v = query(1,1,n,mp[x]+1,n);
    sum += v;
   // printf("add x=%d a[x]=%d mp[x]=%d v=%d mp[x]=%d\n",x,aa[x],mp[x],v,sum);
   // printf("v=%d sum=%lld\n",v,sum);
    update(1,1,n,mp[x],1);
}
void Remove(int x)
{
    //printf("rem x=%d a[x]=%d mp[x]=%d ",x,aa[x],mp[x]);
    int v = query(1,1,n,1,mp[x]-1);
    sum -= v;
    //printf("v=%d sum=%lld\n",v,sum);
    update(1,1,n,mp[x],-1);
    //printf("rem x=%d a[x]=%d mp[x]=%d v=%d mp[x]=%d\n",x,aa[x],mp[x],v,sum);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&aa[i]);
        bb[i]=aa[i];
    }

    sort(bb+1,bb+n+1);

    for(int i=1; i<=n; i++){
        mp[i] = (int)(lower_bound(bb+1,bb+n+1,aa[i])-(bb+1))+1;
    }

//    for(int i=1; i<=n; i++){
//        printf("%d ",mp[i]);
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

    int l=1,r=1;
    update(1,1,n,mp[1],1);

    for(int i=1; i<=q; i++)
    {
        //printf("l=%d r=%d ql=%d qr=%d\n",l,r,qr[i].l,qr[i].r);
        while(r<qr[i].r) Add(++r);
        while(r>qr[i].r) Remove(r--);
        while(l<qr[i].l) Remove(l++);
        while(l>qr[i].l) Add(--l);
        ans[qr[i].x] = sum;
    }

    for(int i=1; i<=q; i++){
        printf("%lld\n",ans[i]);
    }

    return 0;
}

