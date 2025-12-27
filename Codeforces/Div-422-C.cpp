#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 200005
ll n,x,st[mx+5][20];
vector<ll>vv[mx+5];
struct dt
{
    ll li,ri,ci,di;
}ss[mx+5];
bool cmp(dt a, dt b)
{
    if(a.li==b.li) return a.ri < b.ri;
    return a.li < b.li;
}
void createSparsetable(ll n)
{
    for(ll i=1; i<=n; i++)
    {
        st[i][0]=i;
    }

    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i+(1<<j)-1<=n; i++)
        {
            int x,y;

            x=st[i][j-1];
            y=st[i+(1<<(j-1))][j-1];

            if(ss[x].ci<=ss[y].ci) st[i][j]=x;
            else st[i][j]=y;
        }
    }
}
ll solve(ll b,ll e)
{
    ll x,y,k;
    k=(ll)log2(e-b+1);

    x=st[b][k];
    y=st[e-(1<<k)+1][k];

    if(ss[x].ci <= ss[y].ci)return x;
    else return y;
}

int main()
{
    scanf("%I64d %I64d",&n,&x);

    for(ll i=1; i<=n; i++)
    {
        ll l,r,c,d;
        scanf("%I64d %I64d %I64d",&l,&r,&c);
        d = r-l+1;
        ss[i].li = l;
        ss[i].ri = r;
        ss[i].ci = c;
        ss[i].di = d;
    }

    sort(ss+1,ss+n+1,cmp);

    createSparsetable(n);

    ll ans = 1000000000000;

    for(ll i=1; i<=n; i++)
    {
        ll lx,rx,cx,dx;
        lx = ss[i].li;
        rx = ss[i].ri;
        cx = ss[i].ci;
        dx = ss[i].di;

        ll lo = BinarySearch(rx+1);
        ll hi = n;

        if(lo>hi || lo<1)continue;

        ll j = solve(lo,hi);

        ll cnt = ss[i].ci + ss[j].ci;

        ans = min(ans,cnt);
    }

    if(ans<1000000000000){
        printf("%I64d\n",ans);
    }
    else{
        printf("-1\n");
    }

    return 0;
}
