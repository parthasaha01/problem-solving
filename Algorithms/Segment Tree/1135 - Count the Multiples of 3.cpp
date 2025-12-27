#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct dt
{
    int zero,one,two,prop;
} tree[mx*4];
void nodeSum(int nd)
{
    int lf=nd*2, rg=nd*2+1;

    tree[nd].zero = tree[lf].zero + tree[rg].zero;
    tree[nd].one = tree[lf].one + tree[rg].one;
    tree[nd].two = tree[lf].two + tree[rg].two;
}
void swapValue(int nd,int sz)
{
    for(int i=1; i<=sz; i++)
    {
        int zero=tree[nd].zero;
        tree[nd].zero = tree[nd].two;
        tree[nd].two = tree[nd].one;
        tree[nd].one = zero;
    }
}
void nodeUpdate(int nd)
{
    int lf=nd*2, rg=nd*2+1;
    tree[lf].prop+=tree[nd].prop;
    tree[rg].prop+=tree[nd].prop;

    swapValue(lf,tree[nd].prop%3);
    swapValue(rg,tree[nd].prop%3);

    tree[nd].prop=0;
}
void init(int nd,int b,int e)
{
    if(b==e)
    {
        tree[nd].zero=1;
        tree[nd].one=0;
        tree[nd].two=0;
        tree[nd].prop=0;
        return;
    }

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);
    nodeSum(nd);
    tree[nd].prop=0;
}
void update(int nd,int b,int e,int x,int y)
{
    if(b>=x&&e<=y){
        tree[nd].prop+=1;
    }

    if(tree[nd].prop!=0&&b!=e){
        nodeUpdate(nd);
    }

    if(x>e||y<b) return;
    if(b>=x&&e<=y){
        if(b==e){
            swapValue(nd,tree[nd].prop%3);
            tree[nd].prop=0;
        }
        else{
            nodeSum(nd);
        }
        return;
    }
    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;
    update(lf,b,md,x,y);
    update(rg,md+1,e,x,y);
    nodeSum(nd);
}
int query(int nd,int b,int e,int x,int y)
{
    if(tree[nd].prop!=0&&b!=e){
        nodeUpdate(nd);
    }

    if(x>e||y<b) return 0;
    if(b>=x&&e<=y){
        return tree[nd].zero;
    }

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;
    int p1=query(lf,b,md,x,y);
    int p2=query(rg,md+1,e,x,y);
    return p1+p2;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        printf("Case %d:\n",ks);
        int n,q;
        scanf("%d%d",&n,&q);

        init(1,1,n);

        for(int i=1; i<=q; i++)
        {
            int typ,x,y;
            scanf("%d%d%d",&typ,&x,&y);
            x++,y++;

            if(typ==0){
                update(1,1,n,x,y);
            }
            else{
                int ans=query(1,1,n,x,y);
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}
