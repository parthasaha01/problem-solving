#include<bits/stdc++.h>
using namespace std;
#define mx 500005
int a[500005];
int tree[4*mx];
int cnt;
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd]=a[b];
        return;
    }

    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);

    tree[nd] = __gcd(tree[lf],tree[rg]);
}
void update(int nd,int b,int e,int x,int y)
{
    if(b==x && e==x){
        tree[nd]=y;
        return;
    }

    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;

    if(x<=md)update(lf,b,md,x,y);
    else update(rg,md+1,e,x,y);

    tree[nd] = __gcd(tree[lf],tree[rg]);
}
int query(int nd,int b,int e,int x,int y)
{
    if(b>y || e<x)return 0;
    if(b>=x && e<=y){
        return tree[nd];
    }

    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;

    int p1 = query(lf,b,md,x,y);
    int p2 = query(rg,md+1,e,x,y);
    int p = __gcd(p1,p2);

    return p;
}
void change(int nd,int b,int e,int x,int y,int g)
{
    if(b>y || e<x)return;

    if(b>=x && e<=y){
        int gd = tree[nd];
        if(gd%g!=0){
                cnt++;
        }
        return;
    }

    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;

    change(lf,b,md,x,y,g);
    change(rg,md+1,e,x,y,g);
}
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    init(1,1,n);

    int q; scanf("%d",&q);

    while(q--)
    {
        int tp; scanf("%d",&tp);

        if(tp==1)
        {
            int x,y,g;
            if(x>y)swap(x,y);

            scanf("%d%d%d",&x,&y,&g);
            int v = query(1,1,n,x,y);

            if(v==g){
                printf("YES\n");
            }
            else
            {
                cnt = 0;
                change(1,1,n,x,y,g);
                //cout << "cnt=" << cnt << endl;
                if(cnt<=1)printf("YES\n");
                else printf("NO\n");
            }
        }
        else
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
            update(1,1,n,x,y);
        }
    }

    return 0;
}
