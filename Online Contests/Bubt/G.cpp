#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
struct dt
{
    int AND,OR,XOR,prop;
} tree[mx*4];
int a[100005];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].AND=a[b];
        tree[node].OR=a[b];
        tree[node].XOR=a[b];
        tree[node].prop=0;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].AND=(tree[left].AND & tree[right].AND);
    tree[node].OR=(tree[left].OR | tree[right].OR);
    tree[node].XOR=(tree[left].XOR ^ tree[right].XOR);
}
void update(int node,int b,int e,int x, int y, int v)
{
    if(b>y||e<x)
    {
        return;
    }

    if(b>=x&&e<=y)
    {
        tree[node].AND=(tree[node].AND ^ v);
        tree[node].OR=(tree[node].OR ^ v);
        tree[node].XOR=(tree[node].XOR ^ v);
        tree[node].prop=(tree[node].prop ^ v);
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    update(left,b,mid,x,y,v);
    update(right,mid+1,e,x,y,v);

    tree[node].AND=(tree[left].AND & tree[right].AND)^tree[node].prop;
    tree[node].OR=(tree[left].OR | tree[right].OR)^tree[node].prop;
    tree[node].XOR=(tree[left].XOR ^ tree[right].XOR)^tree[node].prop;
}
dt query(int node,int b,int e,int x,int y,int carry)
{
    if(b>y||e<x)
    {
        dt p;
        p.AND=7;
        p.OR=0;
        p.XOR=0;
        return p;
    }

    if(b>=x&&e<=y)
    {
        dt p;
        p.AND=tree[node].AND^carry;
        p.OR=tree[node].OR^carry;
        p.XOR=tree[node].XOR^carry;
        return p;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    dt m1=query(left,b,mid,x,y,carry^tree[node].prop);
    dt m2=query(right,mid+1,e,x,y,carry^tree[node].prop);

    dt m;
    m.AND=(m1.AND & m2.AND);
    m.OR=(m1.OR | m2.OR);
    m.XOR=(m1.XOR ^ m2.XOR);
    return m;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        printf("Case %d:\n",ks);

        int n,m;
        scanf("%d%d",&n,&m);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }

        init(1,1,n);

        for(int k=0; k<m; k++)
        {

            int type;
            scanf("%d",&type);

            if(type==1)
            {
                int l,r,v;
                scanf("%d%d%d",&l,&r,&v);
                update(1,1,n,l,r,v);
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                dt ans=query(1,1,n,l,r,0);

                printf("%d %d %d\n",ans.AND,ans.OR,ans.XOR);
            }

        }
    }

    return 0;
}
