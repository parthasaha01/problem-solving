#include<bits/stdc++.h>
using namespace std;
#define mx 10005
#define ll int
int a[100005];
struct dt
{
    ll sum,prop;
} tree[mx*4];
void update(ll node,ll b,ll e,ll x,ll y,ll v)
{
    if(b>y||e<x)return;
    if(b>=x&&e<=y)
    {
        tree[node].sum+=(e-b+1)*v;
        tree[node].prop+=v;
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    update(left,b,mid,x,y,v);
    update(right,mid+1,e,x,y,v);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
ll query(ll node,ll b,ll e,ll x,ll y,ll carry)
{
    if(b>y||e<x) return 0;
    if(b>=x&&e<=y) return tree[node].sum+(e-b+1)*carry;
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,x,y,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,x,y,carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    int tt;
    scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        memset(tree,0,sizeof(tree));

        int n; scanf("%d",&n);

        int A,B; scanf("%d%d",&A,&B);
        if(A>B)swap(A,B);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        long long int ans = 0;

        for(int i=1; i<=n; i++)
        {
            int v = a[i];
            if(a[i]>=B)continue;
            int x = A-a[i];
            int y = B-a[i];
            if(x<=0)x=1;
            if(y>10000)y=10000;
            if(x>10000)continue;
            if(x>y)continue;

            int cnt = query(1,1,10000,x,y,0);
            ans += cnt;
            //printf("x=%d y=%d v=%d cnt=%d ans=%d\n",x,y,a[i],cnt,ans);
            update(1,1,10000,a[i],a[i],1);
        }

        printf("Case %d: %lld\n",ks,ans);

    }

    return 0;
}
