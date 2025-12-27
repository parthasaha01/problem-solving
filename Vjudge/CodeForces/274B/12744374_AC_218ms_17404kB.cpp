#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
vector<ll>ed[mx];
ll n,cost[mx],res[mx],pos[mx],neg[mx];
bool vis[mx];
void DFS(ll u)
{
    vis[u]=true;

    for(ll i=0; i<ed[u].size(); i++)
    {
        ll v=ed[u][i];
        if(vis[v]==false)
        {
            DFS(v);

            pos[u]=max(pos[u],pos[v]);
            neg[u]=max(neg[u],neg[v]);
        }
    }

    cost[u]-=pos[u];
    cost[u]+=neg[u];

    res[u] = abs(cost[u])+pos[u]+neg[u];

    if(cost[u]>=0) pos[u]+=cost[u];
    else neg[u]+=abs(cost[u]);
}
int main()
{
    scanf("%I64d",&n);

    for(ll i=1; i<n; i++)
    {
        ll u,v;
        scanf("%I64d%I64d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    for(ll i=1; i<=n; i++)
        scanf("%I64d",&cost[i]);

    DFS(1);

    printf("%I64d\n",res[1]);

    return 0;
}

