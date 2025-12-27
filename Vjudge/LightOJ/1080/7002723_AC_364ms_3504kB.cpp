#include<bits/stdc++.h>
using namespace std;
#define INF 1000000005
#define mx 100005
int tree[mx*4];
string a;
void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=a[b]-'0';
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=0;
}
void update(int node,int b,int e,int x,int y)
{
    if(b>y||e<x){
        return;
    }

    if(b>=x&&e<=y){
        tree[node] = tree[node]^1;
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    update(left,b,mid,x,y);
    update(right,mid+1,e,x,y);
}
int query(int node,int b,int e,int x)
{
    if(b>x||e<x){
        return 0;
    }
    if(b==x&&e==x){
        return tree[node];
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    if(x<=mid){
        return query(left,b,mid,x)^tree[node];
    }
    else{
        return query(right,mid+1,e,x)^tree[node];
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        printf("Case %d:\n",kase);

        cin >> a;
        int n=a.size();

        init(1,0,n-1);

        int q;
        scanf("%d",&q);

        for(int i=0; i<q; i++)
        {
            getchar();
            char type;
            scanf("%c",&type);

            if(type=='I'){
                int x,y;
                scanf("%d%d",&x,&y);
                update(1,0,n-1,x-1,y-1);
            }
            else{
                int x;
                scanf("%d",&x);
                int res=query(1,0,n-1,x-1);
                printf("%d\n",res);
            }
        }
    }

    return 0;
}
