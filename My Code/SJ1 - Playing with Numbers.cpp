#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pil pair<int,ll>
#define mx 100005
ll a[mx], m[mx];
vector<pil>ans;
vector<int>adj[mx];
bool cmp(pil x, pil y){
    return x.first < y.first;
}
void dfs(int u, int p, ll g){
    g = __gcd(a[u],g);
    bool IsLeaf = 1;
    for(int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if(v==p)continue;
        IsLeaf = 0;
        dfs(v,u,g);
    }

    if(IsLeaf){
        ll gg = __gcd(g, m[u]);
        ll val = m[u]-gg;
        ans.push_back(make_pair(u,val));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++) {
        int n; cin>>n;
        for(int i=1; i<n; i++) {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1; i<=n; i++) cin>>a[i];
        for(int i=1; i<=n; i++) cin>>m[i];

        dfs(1,0,0);

        sort(ans.begin(), ans.end(), cmp);

        for(int i=0; i<ans.size(); i++) {
            if(i==ans.size()-1){
                cout<<ans[i].second<<endl;
            }else{
                cout<<ans[i].second<<" ";
            }
        }

        for(int i=0; i<=n; i++)adj[i].clear();
        ans.clear();
    }

    return 0;
}
