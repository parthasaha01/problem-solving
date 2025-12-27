#include<bits/stdc++.h>
using namespace std;
#define mx 30005
#define inf 1000000000
int n,a[mx],tree[4*mx];
void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=b;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    if(a[tree[left]]<=a[tree[right]]){
        tree[node]=tree[left];
    }
    else{
        tree[node]=tree[right];
    }
}
int query(int node,int b, int e, int x, int y)
{
    if(e<x||b>y){
        return 0;
    }

    if(b>=x&&e<=y){
        return tree[node];
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int idx1=query(left,b,mid,x,y);
    int idx2=query(right,mid+1,e,x,y);

    if(idx1==0)
        return idx2;
    if(idx2==0)
        return idx1;
    if(a[idx1]<=a[idx2])
        return idx1;
    else
        return idx2;
}
int getMaxArea(int b,int e)
{
    if(b>e){
        return 0;
    }
    if(b==e){
        return a[b];
    }
    int maxx=0;
    int mnidx=query(1,1,n,b,e);

    int area=max(getMaxArea(b,mnidx-1),getMaxArea(mnidx+1,e));
    return area=max(area,(e-b+1)*a[mnidx]);
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%d",&n);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        init(1,1,n);

        int ans=getMaxArea(1,n);
        printf("Case %d: %d\n",kase,ans);
    }

    return 0;
}
