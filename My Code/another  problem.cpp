#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll MOD = 1000000007;
struct data{
    ll sum, ssum, prop;
    data(){
        sum=0,ssum=0,prop=0;
    }
};
data tree[3*mx];
ll ara[mx];

ll interval_sum(ll b, ll e)
{
    ll x=(e*(e+1))/2;
    ll y=(b*(b-1))/2;
    return (x-y+MOD)%MOD;
}

void push_down(int n, int b, int e)
{
    if(tree[n].prop)
    {
        int l=2*n, r=2*n+1, m=(b+e)/2;
        tree[l].sum+=((m-b+1)*tree[n].prop)%MOD;
        tree[r].sum+=((e-m)*tree[n].prop)%MOD;
        tree[l].ssum+=(interval_sum(b,m)*tree[n].prop)%MOD;
        tree[r].ssum+=(interval_sum(m+1,e)*tree[n].prop)%MOD;
        tree[l].prop+=tree[n].prop%MOD;
        tree[r].prop+=tree[n].prop%MOD;
        tree[l].sum%=MOD;
        tree[l].ssum%=MOD;
        tree[l].prop%=MOD;
        tree[r].sum%=MOD;
        tree[r].ssum%=MOD;
        tree[r].prop%=MOD;
        tree[n].prop=0;
    }
}

void init(int n, int b, int e)
{
    if(b==e)
    {
        tree[n].sum=ara[b]%MOD;
        tree[n].ssum=((ll)b*ara[b])%MOD;
        tree[n].prop=0;
        return;
    }
    int l=2*n, r=2*n+1, m=(b+e)/2;
    init(l,b,m);
    init(r,m+1,e);
    tree[n].sum=(tree[l].sum+tree[r].sum)%MOD;
    tree[n].ssum=(tree[l].ssum+tree[r].ssum)%MOD;
    tree[n].prop=0;
}

void update(int n, int b, int e, int i, int j, ll val)
{
    if(b>j || e<i) return;
    if(b>=i && e<=j)
    {
        tree[n].sum+=((ll)(e-b+1)*val)%MOD;
        tree[n].ssum+=(interval_sum(b,e)*val)%MOD;
        tree[n].prop+=val;
        tree[n].sum%=MOD;
        tree[n].ssum%=MOD;
        tree[n].prop%=MOD;
        return;
    }
    push_down(n,b,e);
    int l=2*n, r=2*n+1, m=(b+e)/2;
    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[n].ssum=(tree[l].ssum+tree[r].ssum)%MOD;
    tree[n].sum=(tree[l].sum+tree[r].sum)%MOD;
}

data query(int n, int b, int e, int i, int j)
{
    if(b>j || e<i) return data();
    if(b>=i && e<=j)
        return tree[n];
    push_down(n,b,e);
    int l=2*n, r=2*n+1, m=(b+e)/2;
    data p=query(l,b,m,i,j);
    data q=query(r,m+1,e,i,j);
    data ret;
    ret.ssum=(p.ssum+q.ssum)%MOD;
    ret.sum=(p.sum+q.sum)%MOD;
    return ret;
}

int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        int n,q; scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)scanf("%lld",&ara[i]);
        init(1,1,n);
        printf("Case %d:\n",ks);
        while(q--)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a==1){
                update(1,1,n,b,c,d);
            }
            else
            {
                data ret=query(1,1,n,b,c);
                ll sum=ret.sum;
                ret=query(1,1,n,b+1,c);
                ll ssum=(ret.ssum-(((ll)(b)*ret.sum)%MOD)+MOD)%MOD;
                ssum*=(ll)d%MOD;
                ssum%=MOD;
                ll ans=(sum+ssum)%MOD;
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
