#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define ll long long
ll n,par[mx];
struct dt{ ll u,v,w; };
vector<dt>vv;
bool cmp(dt x, dt y)
{
    return x.w<y.w;
}
ll findparent(ll x)
{
    if(par[x]==x) return x;
    return par[x]=findparent(par[x]);
}
void Unionparent(ll x,ll y)
{
    par[findparent(y)] = findparent(x);
}

int kruskal()
{
    for(int i=1; i<=n; i++) par[i]=i;
    ll sum=0;

    sort(vv.begin(),vv.end(),cmp);

    for(int i=0; i<vv.size(); i++)
    {
        dt top = vv[i];
        int parU = findparent(top.u);
        int parV = findparent(top.v);

        if(parU!=parV){
            Unionparent(parU,parV);
            sum += top.w;
        }
    }

    return sum;
}
int main()
{
    int ks=0;

    while(scanf("%lld",&n)==1)
    {
        if(ks)printf("\n");
        ks++;
        ll res=0; vv.clear();

        for(int i=1; i<n; i++)
        {
            ll u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
            dt nd; nd.u=u; nd.v=v; nd.w=w;
            vv.push_back(nd);
            res+=w;
        }

        int k; scanf("%d",&k);

        for(int i=1; i<=k; i++)
        {
            ll u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
            dt nd; nd.u=u; nd.v=v; nd.w=w;
            vv.push_back(nd);
        }

        int m; scanf("%d",&m);

        for(int i=1; i<=m; i++)
        {
            ll u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
        }

        ll ans = kruskal();

        printf("%lld\n",res);
        printf("%lld\n",ans);
    }
    return 0;
}
