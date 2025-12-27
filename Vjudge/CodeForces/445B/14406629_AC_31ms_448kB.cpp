#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,vis[55];
ll cnt;
vector<int>ed[55];
void dfs(int u)
{
    cnt++;
    vis[u] = 1;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
}
int main()
{
    cin>>n>>m;
    ll ans = 1;
    for(int i=1; i<=m; i++){
        int u,v; cin>>u>>v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            cnt = 0;
            dfs(i);
            ans *= (1LL<<(cnt-1));
        }
    }

    cout << ans << endl;

    return 0;
}
