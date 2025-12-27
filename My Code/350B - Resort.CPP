#include<bits/stdc++.h>
using namespace std;
#define MX 100005
int n,type[MX],a[MX],out[MX],vis[MX],dp[MX];
vector<int>ed[MX],vv;
int dfs(int u)
{
    if(vis[u]==1)return dp[u];
    vis[u]=1;
    if(type[u]==1)return dp[u]=1;
    if(out[u]>1)return dp[u]=-10000;

    int ret = -100000;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(out[v]>1)continue;
        dfs(v);
        ret = max(ret,1+dp[v]);
    }
    return dp[u] = ret;
}
int dfs2(int u)
{
    vis[u]=1;
    vv.push_back(u);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(out[v]>1)continue;
        if(vis[v]==0)dfs2(v);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)cin>>type[i];
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]==0)continue;
        ed[a[i]].push_back(i);
        out[a[i]]++;
    }

    int maxx = 0,node;
    for(int i=1; i<=n; i++){
        int cnt = dfs(i);
        if(cnt>maxx){
            maxx = cnt;
            node = i;
        }
    }

    memset(vis,0,sizeof(vis));
    dfs2(node);
    cout<<maxx<<endl;
    for(int i=0; i<vv.size(); i++){
        cout << vv[i] << " ";
    }

    return 0;
}
