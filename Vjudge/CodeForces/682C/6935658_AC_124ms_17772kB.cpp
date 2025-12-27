#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
vector<ll>ed[mx],cost[mx];
ll n,cnt,a[mx];
bool vis[mx];
void reset()
{
    for(int i=0; i<=n; i++){
        vis[i]=false;
        ed[i].clear();
        cost[i].clear();
    }
}
void DFS(ll u, ll need)
{
    vis[u]=true;
    if(need>a[u]) return;
    cnt++;

    for(int i=0; i<ed[u].size(); i++){
        if(vis[ed[u][i]]==false){
            if(need<=0)
                DFS(ed[u][i],cost[u][i]);
            else
                DFS(ed[u][i],need+cost[u][i]);
        }
    }
}
int main()
{
    while(scanf("%I64d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            scanf("%I64d",&a[i]);
        }

        for(int u=2; u<=n; u++){
            ll v,c;
            scanf("%I64d%I64d",&v,&c);
            ed[u].push_back(v);
            ed[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }

        cnt=0;
        DFS(1,0);
        ll res=n-cnt;
        printf("%I64d\n",res);

        reset();
    }

    return 0;
}
