#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
struct dt
{
    ll k,p,kk,q,qq,id,dd;
}st[mx+5];
bool cmp(dt x, dt y)
{
    return x.dd > y.dd;
}
ll a[mx+5];
bool vis[mx+5];
int main()
{
    ll n,f;
    scanf("%I64d %I64d",&n,&f);

    for(int i=1; i<=n; i++)
    {
        ll u,v; scanf("%I64d %I64d",&u,&v);

        st[i].k=u;
        st[i].p=v;
        st[i].q=min(u,v);
        st[i].kk=2*u;
        st[i].qq=min(2*u,v);
        st[i].dd=st[i].qq-st[i].q;
        st[i].id=i;
    }

    sort(st+1,st+n+1,cmp);
    ll ans=0;
    for(int i=1; i<=f; i++)
    {
        ans+=st[i].qq;
        vis[st[i].id]=true;
    }

    for(int i=1; i<=n; i++)
    {
        if(vis[st[i].id]==false){
            ans+=st[i].q;
            vis[st[i].id]=true;
        }
    }

    printf("%I64d\n",ans);

    return 0;
}
