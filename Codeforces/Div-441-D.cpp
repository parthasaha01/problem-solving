#include<bits/stdc++.h>
using namespace std;
#define mx 300005
int tree[mx*4];
int pp[mx+5];
void update(int node,int b,int e,int i,int x)
{
    if(b>i || e<i) return;
    if(b==e && b==i){
        tree[node]=x;
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    tree[node]=tree[left]+tree[right];
}
int query_sum(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)return 0;
    if(b>=i && e<=j)return tree[node];

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    int p1 = query_sum(left,b,mid,i,j);
    int p2 = query_sum(right,mid+1,e,i,j);
    return p1+p2;
}
int query_pos(int n)
{
    int lo=1;
    int hi=n;

    while(lo<=hi)
    {
        //if(lo==hi)return lo;

        int md = (lo+hi)/2;
        int res = query_sum(1,1,n,md+1,hi);
        int cnt = hi-md;

        if(lo==hi && res==0){
            return lo;
        }

        if(res<cnt){
            lo=md+1;
        }
        else{
            hi=md;
        }
    }
}

int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&pp[i]);
    }

    memset(tree,0,sizeof(tree));
    printf("1");

    for(int i=1; i<n; i++)
    {
        update(1,1,n,pp[i],1);
        int pos = query_pos(n);
        //cout << "hdhgg" << endl;
        int cnt = query_sum(1,1,n,1,pos);
        printf(" %d",cnt+1);
    }

    printf(" 1\n");
    return 0;
}
