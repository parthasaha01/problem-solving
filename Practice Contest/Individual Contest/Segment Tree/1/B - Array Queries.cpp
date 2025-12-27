#include<bits/stdc++.h>
using namespace std;
#define mx 100000
int tree[4*mx+5],a[mx+5];
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd]=a[b];
        return;
    }

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);
    tree[nd]=min(tree[lf],tree[rg]);
}
int query(int nd,int b,int e,int x,int y)
{
    if(x>e||y<b) return 99999999;
    if(b>=x&&e<=y) return tree[nd];

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    int m1=query(lf,b,md,x,y);
    int m2=query(rg,md+1,e,x,y);
    return min(m1,m2);
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

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        init(1,1,n);

        for(int i=1; i<=q; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int ans=query(1,1,n,x,y);
            printf("%d\n",ans);
        }
    }

    return 0;
}
