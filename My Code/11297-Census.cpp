#include<bits/stdc++.h>
using namespace std;
int tree[505][4*505][3];
int a[505][505];
struct dt{
    int mn,mx;
};
void init(int id,int nd,int b,int e)
{
    if(b==e){
        tree[id][nd][1] = a[id][b];
        tree[id][nd][2] = a[id][b];
        return;
    }

    int lf=2*nd, rg = 2*nd+1, md=(b+e)/2;

    init(id,lf,b,md);
    init(id,rg,md+1,e);
    tree[id][nd][1] = min(tree[id][lf][1], tree[id][rg][1]);
    tree[id][nd][2] = max(tree[id][lf][2], tree[id][rg][2]);
}
void update(int id,int nd,int b,int e,int x,int v)
{
    if(b==x&&e==x){
        tree[id][nd][1] = v;
        tree[id][nd][2] = v;
        return;
    }

    int lf=2*nd, rg = 2*nd+1, md=(b+e)/2;

    if(x<=md)update(id,lf,b,md,x,v);
    else update(id,rg,md+1,e,x,v);
    tree[id][nd][1] = min(tree[id][lf][1], tree[id][rg][1]);
    tree[id][nd][2] = max(tree[id][lf][2], tree[id][rg][2]);
}
dt query(int id,int nd,int b,int e,int x,int y)
{
    if(b>y||e<x){
        dt tm;
        tm.mn=1000000005;
        tm.mx=0;
        return tm;
    }
    if(b>=x&&e<=y){
        dt km;
        km.mn = tree[id][nd][1];
        km.mx = tree[id][nd][2];
        return km;
    }

    int lf=2*nd, rg = 2*nd+1, md=(b+e)/2;

    dt p1 = query(id,lf,b,md,x,y);
    dt p2 = query(id,rg,md+1,e,x,y);

    dt p;
    p.mn = min(p1.mn,p2.mn);
    p.mx = max(p1.mx,p2.mx);
    return p;
}
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        init(i,1,1,n);
    }

    int q;
    scanf("%d",&q); getchar();

    for(int k=1; k<=q; k++)
    {
        char ch; scanf("%c ",&ch);

        if(ch=='q'){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2); getchar();
            int minn = 1000000009;
            int maxx = 0;
            for(int i=x1; i<=x2; i++)
            {
                dt res;
                res = query(i,1,1,n,y1,y2);
                minn = min(minn,res.mn);
                maxx = max(maxx,res.mx);
            }

            printf("%d %d\n",maxx,minn);
        }
        else{
            int x,y,v;
            scanf("%d%d%d",&x,&y,&v); getchar();
            update(x,1,1,n,y,v);
        }
    }

    return 0;
}
