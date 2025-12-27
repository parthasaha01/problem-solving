#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx+2];
int tree[mx*4];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=max(tree[left],tree[right]);
}
void update(int node,int b,int e,int i,int x)
{
    if(b>i || e<i)
        return;
    if(b==e)
    {
        tree[node]=x;
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    tree[node]=max(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
        return tree[node];

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return max(p1,p2);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        init(1,1,n);

        for(int i=1; i<=n; i++)
        {
            int p;
            scanf("%d",&p);
            update(1,1,n,p,0);
            int ans=query(1,1,n,1,n);
            printf("%d\n",ans);
        }
    }

    return 0;
}
