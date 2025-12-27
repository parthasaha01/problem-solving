#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
int tree[8*mx];
bool flag[mx];
struct dt{
    int xx,yy;
}st[mx];
void update(int nd,int b,int e,int x,int y,int v)
{
    if(b>y || e<x)return;

    int lf = 2*nd, rg = 2*nd+1, md = (b+e)/2;
    if(tree[nd]!=0&&b!=e){
        tree[lf] = tree[nd];
        tree[rg] = tree[nd];
        tree[nd] = 0;
    }

    if(b>=x&&e<=y){
        tree[nd] = v;
        return;
    }

    update(lf,b,md,x,y,v);
    update(rg,md+1,e,x,y,v);

    tree[nd] = tree[lf]+tree[rg];
}
int query(int nd,int b,int e,int x,int y,int pr)
{
    if()
    if(b==x&&e==x){
        if(pr==0)return tree[nd];
        return pr;
    }

    int lf = 2*nd, rg = 2*nd+1, md = (b+e)/2;

    if(pr==0)pr = tree[nd];

    if(x<=md) return query(lf,b,md,x,pr);
    else return query(rg,md+1,e,x,pr);
}
int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);

    for(int i=1; i<=n; i++)
    {
        int x; scanf("%d",&x);
        a[i]=x;
        update(1,1,1000000,x,x,1);
    }

    sort(a+1,a+n+1);

    for(int i=1; i<=n; i++)
    {
        int x = a[i];
        int y = x+m-1;
        if(y>1000000)y=1000000;
        int v = query(1,1,1000000,x,y,0);
        if()
    }
}
