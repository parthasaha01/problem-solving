#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
int minn,maxx,a[505*505];
struct data{
    int mn,mx;
}tree[4*505*505];
void build(int nd, int b, int e)
{
    if(b==e){
        tree[nd].mn=a[b]; tree[nd].mx=a[b];
        return;
    }
    int md=(b+e)>>1, L=nd<<1, R=L+1;
    build(L,b,md);
    build(R,md+1,e);

    tree[nd].mx=max(tree[L].mx,tree[R].mx);
    tree[nd].mn=min(tree[L].mn,tree[R].mn);
}

void update(int nd, int b,int e,int x,int v)
{
    if(b==x && e==x){
        tree[nd].mx=v; tree[nd].mn=v;
        return;
    }
    int md=(b+e)>>1, L=nd<<1, R=L+1;
    if(x<=md) update(L,b,md,x,v);
    else update(R,md+1,e,x,v);

    tree[nd].mx=max(tree[L].mx,tree[R].mx);
    tree[nd].mn=min(tree[L].mn,tree[R].mn);
}

void query(int nd,int b,int e,int x,int y)
{
    if(b>y || e<x) return;
    if(b>=x && e<=y){
        maxx=max(maxx,tree[nd].mx);
        minn=min(minn,tree[nd].mn);
        return;
    }
    int md=(b+e)>>1, L=nd<<1, R=L+1;
    query(L,b,md,x,y);
    query(R,md+1,e,x,y);
}


int main()
{
    int n; scanf("%d",&n);
    for(int i=1;i<=n*n;i++) scanf("%d",&a[i]);

    build(1,1,n*n);

    int q; scanf("%d",&q); getchar();
    for(int i=1; i<=q; i++)
    {
        char ch; scanf("%c",&ch);
        if(ch=='q'){
            int x,y,x1,y1;
            scanf("%d%d%d%d",&x,&y,&x1,&y1); getchar();

            minn=inf; maxx=-inf;
            while(x<=x1){
                int st=((x-1)*n)+y;
                int ed=((x-1)*n)+y1;
                query(1,1,n*n,st,ed);
                x++;
            }
            printf("%d %d\n",maxx,minn);
        }
        else{
            int x,y,v;
            scanf("%d %d %d",&x,&y,&v); getchar();
            x=((x-1)*n)+y;
            update(1,1,n*n,x,v);
        }
    }
}
