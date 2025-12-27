#include<bits/stdc++.h>
using namespace std;
#define INF 1000000005
#define mx 100005
int tree[mx*4];
int a[mx];
void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=a[b];
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int b,int e,int x, int y)
{
    if(b>y||e<x){
        return INF;
    }
    if(b>=x&&e<=y){
        return tree[node];
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    int m1=query(left,b,mid,x,y);
    int m2=query(right,mid+1,e,x,y);
    return min(m1,m2);
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        printf("Case %d:\n",kase);

        int n,q;
        scanf("%d%d",&n,&q);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        init(1,1,n);

        for(int i=0; i<q; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            int res=query(1,1,n,x,y);
            printf("%d\n",res);
        }
    }

    return 0;
}
