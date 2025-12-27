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
    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int x,int v)
{
    if(b>x||e<x){
        return;
    }

    if(b==e&&b==x){
        tree[node]=v;
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    update(left,b,mid,x,v);
    update(right,mid+1,e,x,v);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int x, int y)
{
    if(b>y||e<x){
        return 0;
    }
    if(b>=x&&e<=y){
        return tree[node];
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    int p1=query(left,b,mid,x,y);
    int p2=query(right,mid+1,e,x,y);
    return p1+p2;
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

        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        init(1,0,n-1);

        for(int i=0; i<q; i++)
        {
            int type;
            scanf("%d",&type);

            if(type==1){
                int x;
                scanf("%d",&x);
                printf("%d\n",a[x]);
                a[x]=0;
                update(1,0,n-1,x,0);
            }
            else if(type==2){
                int x,v;
                scanf("%d%d",&x,&v);
                a[x]+=v;
                update(1,0,n-1,x,a[x]);
            }
            else{
                int x,y;
                scanf("%d%d",&x,&y);
                int res=query(1,0,n-1,x,y);
                printf("%d\n",res);
            }
        }
    }

    return 0;
}

