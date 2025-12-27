#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
const int BLOCK_SIZE = 320;
int N,aa[mx],bb[mx],tree[4*mx];
ll ans[mx],sum;
unordered_map<int,int>mp;
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
        tree[nd]+=v; return;
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
int main()
{
    int n; scanf("%d",&n);
    int q; scanf("%d",&q);

    for(int i=1; i<=n; i++){
        scanf("%d",&aa[i]);
        bb[i]=aa[i];
    }

    sort(bb+1,bb+n+1);

    int k=0;
    for(int i=1; i<=n; i++){
        if(mp.find(bb[i])==mp.end())mp[bb[i]]=++k;
    }

    N = k;

    for(int i=1; i<=n; i++){
        aa[i] = mp[aa[i]];
    }

//    for(int i=1; i<=n; i++){
//        printf("%d ",mp[aa[i]]);
//    }
//    printf("\n");
    //int q; scanf("%d",&q);
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

    for(int i=1; i<=q; i++)
    {
        while(l<qr[i].l){
            sum -= query(1,1,N,1,aa[l]-1);;
            update(1,1,N,aa[l],-1);
            l++;
        }
        while(l>qr[i].l){
            --l;
            sum += query(1,1,N,1,aa[l]-1);;
            update(1,1,N,aa[l],1);
        }
        while(r<qr[i].r){
            ++r;
            sum += query(1,1,N,aa[r]+1,N);;
            update(1,1,N,aa[r],1);
        }
        while(r>qr[i].r){
            sum -= query(1,1,N,aa[r]+1,N);;
            update(1,1,N,aa[r],-1);
            r--;
        }

        ans[qr[i].x] = sum;
    }

    for(int i=1; i<=q; i++){
        printf("%lld\n",ans[i]);
    }

    return 0;
}

