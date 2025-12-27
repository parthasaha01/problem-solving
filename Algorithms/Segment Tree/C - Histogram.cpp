#include<bits/stdc++.h>
using namespace std;
#define mx 30000
int tree[4*mx+5],a[mx+5];
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
int CalculateMaxArea(int b,int e,int n)
{
    if(b<1||e<1||e<b) return 0;

    int maxx=0;
    int id=query(1,1,n,b,e);
    int area=(e-b+1)*a[id];
    int area2=CalculateMaxArea(b,id-1,n);
    int area3=CalculateMaxArea(id+1,e,n);
    return maxx=max(maxx,max(area,max(area2,area3)));
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        init(1,1,n);

        int ans=CalculateMaxArea(1,n,n);
        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}

