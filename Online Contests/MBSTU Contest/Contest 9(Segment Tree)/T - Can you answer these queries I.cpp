#include<bits/stdc++.h>
#define mx 50005
int tree[mx*4];
int a[mx];
using namespace std;
void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=a[b];
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    if(tree[left]>=0&&tree[right]>=0){
        tree[node]=tree[left]+tree[right];
    }
    else if(tree[left]>=0&&tree[right]<0){
        tree[node]=tree[left];
    }
    else if(tree[left]<0&&tree[right]>=0){
        tree[node]=tree[right];
    }
    else{
        tree[node]=max(tree[left],tree[right]);
    }

    //printf("tree[%d]=%d tree[%d]=%d tree[%d]=%d\n",node,tree[node],left,tree[left],right,tree[right]);
}
int query(int node,int b,int e,int x,int y)
{
    if(b>y||e<x){
        return -999999999;
    }
    if(b>=x&&e<=y){
        return tree[node];
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int m1=query(left,b,mid,x,y);
    int m2=query(right,mid+1,e,x,y);
    int m;
    if(m1>=0&&m2>=0){
        m=m1+m2;
    }
    else if(m1>=0&&m2<0){
        m=m1;
    }
    else if(m1<0&&m2>=0){
        m=m2;
    }
    else{
        m=max(m1,m2);
    }

    return m;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        init(1,1,n);

        int m;
        scanf("%d",&m);

        for(int i=0; i<m; i++){
            int x,y;
            scanf("%d%d",&x,&y);

            int res=query(1,1,n,x,y);
            printf("%d\n",res);
        }
    }

    return 0;
}
/*
10
-5 2 -9 5 6 8 -10 -11 12 -8
10
2 3
2 4
2 5
2 6

*/
