#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define INF 1000000000
struct dt
{
    int maxx,minn;
}tree[mx*4];
int a[mx];

void init(int node,int b,int e)
{
    if(b==e){
        tree[node].maxx=a[b];
        tree[node].minn=a[b];
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].maxx=max(tree[left].maxx,tree[right].maxx);
    tree[node].minn=min(tree[left].minn,tree[right].minn);
}
dt query(int node,int b,int e,int x,int y)
{
    if(b>y||e<x){
        dt p;
        p.maxx=0;
        p.minn=INF;
        return p;
    }
    if(b>=x&&e<=y){
        return tree[node];
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    dt m1=query(left,b,mid,x,y);
    dt m2=query(right,mid+1,e,x,y);
    dt m;
    m.maxx=max(m1.maxx,m2.maxx);
    m.minn=min(m1.minn,m2.minn);

    return m;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n,d;
        scanf("%d%d",&n,&d);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        init(1,1,n);

        int ans=0;
        for(int i=0; i<=n-d; i++)
        {
            dt cnt=query(1,1,n,i+1,i+d);
            ans=max(ans,cnt.maxx-cnt.minn);
        }

        printf("Case %d: %d\n",kase,ans);
    }

    return 0;
}
