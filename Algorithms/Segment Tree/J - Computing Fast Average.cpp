#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct dt
{
    int sm,pr;
}tree[mx*8];

void init(int n)
{
    for(int i=0; i<=8*n; i++){
        tree[i].sm=0;
        tree[i].pr=-1;
    }
}
void update(int nd,int b,int e,int x,int y,int v)
{
    int lf=nd*2,rg=nd*2+1,md=(b+e)/2;
    if(tree[nd].pr!=-1){
        tree[lf].pr=tree[nd].pr;
        tree[rg].pr=tree[nd].pr;
        tree[nd].sm=(e-b+1)*tree[nd].pr;
        tree[nd].pr=-1;
    }

    if(x>e||y<b)return;
    if(b>=x&&e<=y){
        tree[nd].sm=(e-b+1)*v;
        tree[lf].pr=v;
        tree[rg].pr=v;
        tree[nd].pr=-1;
        return;
    }

    update(lf,b,md,x,y,v);
    update(rg,md+1,e,x,y,v);
    tree[nd].sm=tree[lf].sm+tree[rg].sm;
}
int query(int nd,int b,int e,int x,int y)
{
    int lf=nd*2,rg=nd*2+1,md=(b+e)/2;
    if(tree[nd].pr!=-1){
        tree[lf].pr=tree[nd].pr;
        tree[rg].pr=tree[nd].pr;
        tree[nd].sm=(e-b+1)*tree[nd].pr;
        tree[nd].pr=-1;
    }

    if(x>e||y<b) return 0;
    if(b>=x&&e<=y){
            return tree[nd].sm;
    }
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

        init(n);

        for(int i=1; i<=q; i++)
        {
            int typ;
            scanf("%d",&typ);

            if(typ==1)
            {
                int x,y,v;
                scanf("%d%d%d",&x,&y,&v);
                x++,y++;
                update(1,1,n,x,y,v);
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                x++,y++;
                int sum=query(1,1,n,x,y);
                int cnt=y-x+1;
                int gcd=__gcd(sum,cnt);
                //printf("sum=%d cnt=%d gcd=%d\n",sum,cnt,gcd);
                if(sum%cnt==0) printf("%d\n",sum/cnt);
                else printf("%d/%d\n",sum/gcd,cnt/gcd);
            }
        }
    }

    return 0;
}
