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
int queryMaxx(int node,int b,int e,int x,int y)
{
    if(b>y||e<x){
        return 0;
    }
    if(b>=x&&e<=y){
        return tree[node].maxx;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int m1=queryMaxx(left,b,mid,x,y);
    int m2=queryMaxx(right,mid+1,e,x,y);

    return max(m1,m2);
}
int queryMinn(int node,int b,int e,int x,int y)
{
    if(b>y||e<x){
        return INF;
    }
    if(b>=x&&e<=y){
        return tree[node].minn;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int m1=queryMinn(left,b,mid,x,y);
    int m2=queryMinn(right,mid+1,e,x,y);

    return min(m1,m2);
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
            int cnt1=queryMaxx(1,1,n,i+1,i+d);
            int cnt2=queryMinn(1,1,n,i+1,i+d);
            ans=max(ans,cnt1-cnt2);
        }

        printf("Case %d: %d\n",kase,ans);
    }

    return 0;
}
