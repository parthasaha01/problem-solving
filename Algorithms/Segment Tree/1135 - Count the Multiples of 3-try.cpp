#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct dt
{
    int zero,one,two,sum,prop;
} tree[mx*4];
void nodeSum(int nd,int lf,int rg)
{
    tree[nd].zero = tree[lf].zero + tree[rg].zero;
    tree[nd].one = tree[lf].one + tree[rg].one;
    tree[nd].two = tree[lf].two + tree[rg].two;
    tree[nd].sum = tree[lf].sum + tree[rg].sum;
}
void swapValue(int nd,int sz)
{
    for(int i=1; i<=sz; i++)
    {
        tree[nd].sum = tree[nd].two;
        tree[nd].two = tree[nd].one;
        tree[nd].one = tree[nd].zero;
        tree[nd].zero = tree[nd].sum;
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
        tree[nd].sum=0;
        tree[nd].prop=0;
        return;
    }

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);
    nodeSum(nd,lf,rg);
    tree[nd].prop=0;
}
void update(int nd,int b,int e,int x,int y)
{
     /*printf("%d - zero=%d one=%d two=%d sum=%d prop=%d\n",nd,tree[nd].zero,tree[nd].one,
                           tree[nd].two,tree[nd].sum,tree[nd].prop);
    getchar();
    /*if(b==x&&e==y)
    {
        tree[nd].prop = tree[nd].prop+1;
        nodeUpdate(nd,1);
        return;
    }*/

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;
    if(tree[nd].prop!=0 && b!=e)
    {
        nodeUpdate(nd);
    }

    if(x>e||y<b) return;
    if(b>=x&&e<=y)
    {
        //tree[lf].prop+=1;
        //tree[rg].prop+=1;
        tree[nd].prop += 1;
        swapValue(nd,tree[nd].prop%3);
        return;

        /*if(b==e)
        {
            tree[nd].prop = (tree[nd].prop+1)%3;
            nodeUpdate(nd,tree[nd].prop);
            tree[nd].prop=0;
        }
        else
        {
            tree[lf].prop = (tree[lf].prop+1)%3;
            nodeUpdate(lf,tree[lf].prop);
            tree[rg].prop = (tree[rg].prop+1)%3;
            nodeUpdate(rg,tree[rg].prop);
            nodeSum(nd,lf,rg);
            tree[nd].prop=0;

            printf("e-%d - zero=%d one=%d two=%d sum=%d prop=%d\n",nd,tree[nd].zero,tree[nd].one,
                           tree[nd].two,tree[nd].sum,tree[nd].prop);
                           getchar();
        }*/
    }
    update(lf,b,md,x,y);
    update(rg,md+1,e,x,y);
    nodeSum(nd,lf,rg);
    /*printf("%d - zero=%d one=%d two=%d sum=%d prop=%d\n",nd,tree[nd].zero,tree[nd].one,
                           tree[nd].two,tree[nd].sum,tree[nd].prop);
                           getchar();*/
}
int query(int nd,int b,int e,int x,int y)
{
    //cout << "nd="<< nd << endl;


    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;
    if(tree[nd].prop!=0 && b!=e)
    {
        printf("nd=%d lf=%d rg=%d\n",nd,lf,rg);
        nodeUpdate(nd);
    }

    if(x>e||y<b) return 0;
    if(b>=x&&e<=y)
    {
        return tree[nd].sum;
        //tree[nd].prop = (tree[nd].prop);

        //nodeUpdate(nd,tree[nd].prop%3);
        //tree[nd].prop=0;

    }

    int p1=query(lf,b,md,x,y);
    int p2=query(rg,md+1,e,x,y);
    printf("nd=%d p1+p2=%d lf=%d p1=%d rg=%d p2=%d\n",nd,p1+p2,lf,p1,rg,p2);
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

        /*for(int i=1; i<=17; i++)
        {
            printf("%d - zero=%d one=%d two=%d sum=%d prop=%d\n",i,tree[i].zero,tree[i].one,
                   tree[i].two,tree[i].sum,tree[i].prop);
        }
        printf("24 - zero=%d one=%d two=%d sum=%d prop=%d\n",tree[24].zero,tree[24].one,
                   tree[24].two,tree[24].sum,tree[24].prop);
        printf("25 - zero=%d one=%d two=%d sum=%d prop=%d\n",tree[25].zero,tree[25].one,
                   tree[25].two,tree[25].sum,tree[25].prop);*/

        for(int i=1; i<=q; i++)
        {
            int typ,x,y;
            scanf("%d%d%d",&typ,&x,&y);
            //getchar();
            //x++,y++;

            if(typ==0)
            {
                update(1,1,n,x,y);

                for(int i=1; i<=17; i++)
                {
                    printf("%d - zero=%d one=%d two=%d sum=%d prop=%d\n",i,tree[i].zero,tree[i].one,
                           tree[i].two,tree[i].sum,tree[i].prop);
                }
                printf("24 - zero=%d one=%d two=%d sum=%d prop=%d\n",tree[24].zero,tree[24].one,
                       tree[24].two,tree[24].sum,tree[24].prop);
                printf("25 - zero=%d one=%d two=%d sum=%d prop=%d\n",tree[25].zero,tree[25].one,
                       tree[25].two,tree[25].sum,tree[25].prop);
            }
            else
            {
                int ans=query(1,1,n,x,y);
                printf("%d\n",ans);

                for(int i=1; i<=17; i++)
                {
                    printf("%d - zero=%d one=%d two=%d sum=%d prop=%d\n",i,tree[i].zero,tree[i].one,
                           tree[i].two,tree[i].sum,tree[i].prop);
                }
                printf("24 - zero=%d one=%d two=%d sum=%d prop=%d\n",tree[24].zero,tree[24].one,
                       tree[24].two,tree[24].sum,tree[24].prop);
                printf("25 - zero=%d one=%d two=%d sum=%d prop=%d\n",tree[25].zero,tree[25].one,
                       tree[25].two,tree[25].sum,tree[25].prop);
            }
        }
    }

    return 0;
}
