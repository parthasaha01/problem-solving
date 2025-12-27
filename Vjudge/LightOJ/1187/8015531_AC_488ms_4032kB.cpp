#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int ar[mx],tree[4*mx],ans[mx];
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd]=1;return;
    }

    int lf=2*nd,rg=2*nd+1,md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);
    tree[nd] = tree[lf]+tree[rg];
}
void update(int nd,int b,int e,int x)
{
    if(b==x&&e==x){
        tree[nd]=0; return;
    }
    if(x<b||x>e)return;

    int lf=2*nd,rg=2*nd+1,md=(b+e)/2;

    update(lf,b,md,x);
    update(rg,md+1,e,x);
    tree[nd] = tree[lf]+tree[rg];
}
int query(int nd,int b,int e,int v)
{
    if(b==e) return b;

    int lf=2*nd,rg=2*nd+1,md=(b+e)/2;

    if(v<=tree[lf]) return query(lf,b,md,v);
    else return query(rg,md+1,e,v-tree[lf]);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);


        for(int i=1; i<=n; i++)
            scanf("%d",&ar[i]);

        init(1,1,n);

        //for(int i=1; i<=5; i++)printf("node-%d: %d\n",i,tree[i]);

        for(int i=n; i>=1; i--){
            int v = ar[i]+1;
            int p = query(1,1,n,v);
            ans[i] = n-p+1;
            update(1,1,n,p);
            //printf("ans[%d]=%d\n",i,ans[i]);
            //for(int i=1; i<=5; i++)printf("node-%d: %d\n",i,tree[i]);
        }
        printf("Case %d: %d\n",ks,ans[1]);
    }

    return 0;
}
