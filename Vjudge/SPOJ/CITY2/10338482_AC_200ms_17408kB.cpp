#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,tree[4*mx+5],a[mx+5];
int ans=0;
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd]=b;
        return;
    }

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);

    if(a[tree[lf]]<=a[tree[rg]])
        tree[nd]=tree[lf];
    else
        tree[nd]=tree[rg];
}
int query(int nd,int b,int e,int x,int y)
{
    if(x>e||y<b) return 0;
    if(b>=x&&e<=y) return tree[nd];

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    int m1=query(lf,b,md,x,y);
    int m2=query(rg,md+1,e,x,y);

    if(m1==0) return m2;
    if(m2==0) return m1;
    if(a[m1]<=a[m2]) return m1;
    else return m2;
}
void Calculate(int b,int e,int x)
{
    if(b<1||e<1||e<b) return;

    int id=query(1,1,n,b,e);
    if(a[id]>x)ans++;
    int v = max(x,a[id]);
    Calculate(b,id-1,v);
    Calculate(id+1,e,v);
}
int main()
{
    int ks=0;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        init(1,1,n);
        ans=0;
        Calculate(1,n,0);

        printf("Case %d: %d\n",++ks,ans);
    }

    return 0;
}
