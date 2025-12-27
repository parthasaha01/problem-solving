#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int tree[4*mx],a[mx],cc[mx],cs[mx],id[mx],cz;
void init(int nd,int b,int e)
{
    if(b==e){tree[nd] = cc[b]; return;}
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    init(lf,b,md);
    init(rg,md+1,e);
    tree[nd] = max(tree[lf],tree[rg]);
}
int query(int nd,int b,int e,int x,int y)
{
    if(b>y||e<x)return 0;
    if(b>=x&&e<=y)return tree[nd];
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    int m1 = query(lf,b,md,x,y);
    int m2 = query(rg,md+1,e,x,y);
    return max(m1,m2);
}
int calculate(int x,int y)
{
    int idx = id[x];
    int idy = id[y];
    if(idx==idy)return y-x+1;
    int rsl = cs[idx]-x+1;
    int rsr = y-cs[idy-1];
    int rsm = 0;
    if(idy-idx>1)
        rsm = query(1,1,cz,idx+1,idy-1);

    return max(rsm,max(rsl,rsr));
}
int main()
{
    int n,q;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&q);

        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        int cn = 1;
        int k=0;
        id[0]=0;
        id[1]=1;
        for(int i=2; i<=n; i++){
            if(a[i]!=a[i-1]){
                cc[++k]=cn;
                cn=0;
            }
            id[i] = k+1;
            cn++;
        }
        cc[++k]=cn;
        cz = k;

        init(1,1,cz);

        cs[0] = 0;
        for(int i=1; i<=cz; i++)
            cs[i] = cs[i-1] + cc[i];

        for(int i=1; i<=q; i++){
            int x,y; scanf("%d%d",&x,&y);
            int ans = calculate(x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
