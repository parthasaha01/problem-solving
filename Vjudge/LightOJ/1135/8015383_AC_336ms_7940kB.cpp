#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct dt{
    int zero,one,two,prop;
}tree[mx*4];
int nodeSum(int nd, int pr)
{
    int r = pr%3;
    if(r==0)return tree[nd].zero;
    if(r==1)return tree[nd].two;
            return tree[nd].one;
}
dt nodeCalculate(int nd)
{
    int r = tree[nd].prop%3;
    dt tm;

    if(r==1){
        tm.zero = tree[nd].two;
        tm.one  = tree[nd].zero;
        tm.two  = tree[nd].one;
        tm.prop = tree[nd].prop;
        return tm;
    }
    else if(r==2){
        tm.zero = tree[nd].one;
        tm.one  = tree[nd].two;
        tm.two  = tree[nd].zero;
        tm.prop = tree[nd].prop;
        return tm;
    }

    return tree[nd];
}
void nodeUpdate(int nd)
{
    dt lf = nodeCalculate(nd*2);
    dt rg = nodeCalculate(nd*2+1);

    tree[nd].zero = lf.zero + rg.zero;
    tree[nd].one  = lf.one + rg.one;
    tree[nd].two  = lf.two + rg.two;
    tree[nd].prop = 0;
}
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd].zero = 1;
        tree[nd].one  = tree[nd].two = tree[nd].prop = 0;
        return;
    }

    int lf=nd*2,rg=nd*2+1,md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);

    tree[nd].zero = tree[lf].zero + tree[rg].zero;
    tree[nd].one  = tree[lf].one  + tree[rg].one;
    tree[nd].two  = tree[lf].two  + tree[rg].two;
    tree[nd].prop = 0;
}
dt update(int nd,int b,int e,int xx,int yy)
{
    if(b>=xx&&e<=yy){
        tree[nd].prop += 1;
        dt tm = nodeCalculate(nd);
        return tm;
    }

    if(e<xx || b>yy){
        dt tm = nodeCalculate(nd);
        return tm;
    }

    int lf=nd*2,rg=nd*2+1,md=(b+e)/2;

    if(tree[nd].prop!=0){
        tree[lf].prop += tree[nd].prop;
        tree[rg].prop += tree[nd].prop;
    }

    dt s1 = update(lf,b,md,xx,yy);
    dt s2 = update(rg,md+1,e,xx,yy);

    tree[nd].zero = s1.zero + s2.zero;
    tree[nd].one  = s1.one  + s2.one;
    tree[nd].two  = s1.two  + s2.two;
    tree[nd].prop = 0;
    return tree[nd];
}
int query(int nd,int b,int e,int xx,int yy,int pr)
{
    if(e<xx || b>yy)return 0;
    if(b>=xx&&e<=yy){
        return nodeSum(nd,tree[nd].prop+pr);
    }

    int lf=nd*2,rg=nd*2+1,md=(b+e)/2;

    int s1 = query(lf,b,md,xx,yy,tree[nd].prop+pr);
    int s2 = query(rg,md+1,e,xx,yy,tree[nd].prop+pr);
    return s1+s2;
}
void showvalue()
{
    for(int i=1; i<=25; i++){
            if((i>=1 &&i<=15)||i==24||i==25)
                printf("node %2d: %d %d %d %d\n",i,tree[i].zero,tree[i].one,tree[i].two,tree[i].prop);
    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);
        int n,q; scanf("%d%d",&n,&q);
        init(1,1,n);

        //showvalue();

        for(int i=1; i<=q; i++){
            int id,xx,yy;
            scanf("%d%d%d",&id,&xx,&yy);
            xx++,yy++;
            if(id==0){
                dt tm = update(1,1,n,xx,yy);
                //showvalue();
            }
            else{
                int ans = query(1,1,n,xx,yy,0);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

