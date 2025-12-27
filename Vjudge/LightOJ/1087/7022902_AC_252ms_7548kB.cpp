#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 150010

ll tree[mx*4];
ll a[mx],ans;
int st,ed;

void init(int node,int b,int e,int n)
{
    if(b==e)
    {
        if(b<=n)
        {
            tree[node]=1;
        }
        else
        {
            tree[node]=0;
        }
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    init(left,b,mid,n);
    init(right,mid+1,e,n);

    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int x)
{
    if(e<x||b>x)
        return;
    if(b==e&&x==b)
    {
        tree[node]=1;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    update(left,b,mid,x);
    update(right,mid+1,e,x);

    tree[node]=tree[left]+tree[right];
}
void query(int node,int b,int e,int x)
{
    if(b==e&&tree[node]==1)
    {
        ans=a[b];
        a[b]=-1;
        tree[node]=0;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    //printf("node=%d left=%d right=%d b=%d mid=%d e=%d\n",node,left,right,b,mid,e);
    //printf("node=%d left=%d right=%d x=%d\n\n",node,left,right,x);
    //printf("tree-%d=%d tree-%d=%d tree-%d=%d x=%d\n\n",node,tree[node],left,tree[left],right,tree[right],x);

    if(tree[left]>=x)
    {
        query(left,b,mid,x);
    }
    else
    {
        query(right,mid+1,e,x-tree[left]);
    }
    //printf("partha\n");
    tree[node]=tree[left]+tree[right];
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

        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
        }

        init(1,1,mx-10,n);
        st=1;
        ed=n;

        /*for(int i=1; i<=3*mx; i++){
                if(tree[i]>0)
                printf("tree[%d]=%lld\n",i,tree[i]);
        }*/

        for(int i=0; i<q; i++)
        {
            char ch;
            ll v;
            //cin >> ch >> v;
            getchar();
            scanf("%c %lld",&ch,&v);
            //printf("%c %lld\n",ch,v);

            if(ch=='a')
            {
                ed++;
                a[ed]=v;
                update(1,1,mx-10,ed);
            }
            else
            {
                if(tree[1]<v)
                {
                    printf("none\n");
                }
                else
                {
                    ans=0;
                    query(1,1,mx-10,v);
                    printf("%lld\n",ans);
                }
            }
        }
    }

    return 0;
}
