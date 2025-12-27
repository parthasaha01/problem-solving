#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100002
vector<ll>graph[mx+5];
ll node[mx+5], depth[mx+5];

ll dfs1(ll u)
{
    if(graph[u].size()==0){
        depth[u]=0LL;
        return 0LL;
    }

    ll ret = 0LL;
    for(ll i=0; i<graph[u].size(); i++) {
        ll v = graph[u][i];
        ret =max(ret, 1+dfs1(v));
    }

    return depth[u] = ret;
}
ll dfs2(ll u)
{
    if(graph[u].size()==0){
        node[u]=0LL;
        return 0LL;
    }

    ll ret = 0LL;
    for(ll i=0; i<graph[u].size(); i++) {
        ll v = graph[u][i];
        ll n1=1+dfs2(v);
        ret +=n1;
    }

    return node[u] = ret;
}
int main()
{
    ll n;

    while(scanf("%lld",&n)==1)
    {
        memset(node,0LL,sizeof(node));
        for(ll i=0; i<=n; i++) graph[i].clear();

        for(ll i=1; i<=n-1; i++)
        {
            ll u,v;
            scanf("%lld%lld",&u,&v);
            graph[u].push_back(v);
        }

        dfs1(1);
        dfs2(1);

        for(ll i=1; i<=n; i++)node[i]++;

        map<pair<ll, ll>, ll>m;

        for(ll i=1; i<=n; i++) {
            m[make_pair(node[i], depth[i])]++;
        }

        map<pair<ll, ll>, ll> :: iterator it;
        ll ans=0;
        for(it= m.begin(); it!=m.end(); it++) {
            ll var = it->second;
            ans+=((var)*(var-1))/2;
        }

        printf("%lld\n",ans);

    }

    return 0;
}
