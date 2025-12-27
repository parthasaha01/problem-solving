#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll n,a[mx],cnt;
vector<ll>ed[mx];
vector<ll>cs[mx];
void DFS(ll u,ll pr,ll wg)
{
    if(wg>a[u])return;
    cnt++;
    for(ll i=0; i<ed[u].size(); i++)
    {
        ll v = ed[u][i];
        ll w = cs[u][i];
        if(pr==v)continue;
        DFS(v,u,max(w,wg+w));
    }
}
int main()
{
    scanf("%I64d",&n);
    for(ll i=1; i<=n; i++)scanf("%I64d",&a[i]);
    for(ll u=2; u<=n; u++){
        ll v,w; scanf("%I64d %I64d",&v,&w);
        ed[u].push_back(v);
        ed[v].push_back(u);
        cs[u].push_back(w);
        cs[v].push_back(w);
    }

    DFS(1,0,0);

    ll ans = n-cnt;

    printf("%I64d\n",ans);
    return 0;
}
