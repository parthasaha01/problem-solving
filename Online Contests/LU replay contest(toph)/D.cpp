#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 10000001
bool flag[mxx+5];
int tree[400005];
int a[100005];
void sieve()
{
    flag[0]=true;
    flag[1]=true;
    for(int i=4; i<=mxx; i+=2)flag[i]=true;
    ll sq = sqrt(mxx);
    for(ll i=3; i<=sq; i+=2){
        if(flag[i]==false){
            for(ll j=i*i; j<=mxx; j+=(i+i)){
                flag[j]=true;
            }
        }
    }
}
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
    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int i,int x)
{
    if(b>i || e<i) return;
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
    tree[node]=tree[left]+tree[right];
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
    return p1+p2;
}
int main()
{
    sieve();

    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            int x; scanf("%d",&x);

            if(flag[x]==false){
                a[i]=1;
            }
            else{
                a[i]=0;
            }
        }

        init(1,1,n);

        int Q; scanf("%d",&Q);
        for(int q=1; q<=Q; q++)
        {
            int tp; scanf("%d",&tp);

            if(tp==1)
            {
                int u,v;
                scanf("%d%d",&u,&v);
                if(u>v)swap(u,v);

                int ans = query(1,1,n,u,v);
                printf("%d\n",ans);
            }
            else
            {
                int u,x,v;
                scanf("%d%d",&u,&x);

                if(flag[x]==false)v=1;
                else v=0;

                a[u]=v;

                update(1,1,n,u,v);
            }
        }

    }
    return 0;
}

