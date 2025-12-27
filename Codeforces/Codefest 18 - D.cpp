#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define pii pair<int,int>
int n,a[mx],depth[mx],pos[mx],b[mx],vis[mx];
struct dt{
    int u,x;
}st[mx];
vector<int>adj[mx];
vector< pair<int,int> > ed[mx];
bool cmp(pii x, pii y)
{
    return x.first < y.first;
}
void dfs(int u,int p,int dep)
{
    depth[u] = dep;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p)continue;
        ed[u].push_back(make_pair(pos[v],v));
        dfs(v,u,dep+1);
    }

    if((int)ed[u].size()>0){
        sort(ed[u].begin(), ed[u].end(),cmp);
    }
}
int BFS()
{
    int root = a[1];
    int cur = 0;
    queue<int>qq;
    qq.push(root);
    vis[root]=1;
    b[++cur] = root;

    while(!qq.empty())
    {
        int u = qq.front();
        qq.pop();

        for(int i=0; i<ed[u].size(); i++){
            pii p = ed[u][i];
            int v  = p.second;
            if(vis[v]==1)continue;
            vis[v]=1;
            b[++cur]=v;
            qq.push(v);
        }
    }

    for(int i=1; i<=n; i++){
        if(a[i]!=b[i])return 0;
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        pos[a[i]]=i;
        st[i].u = a[i];
        st[i].x = i;
    }

    if(a[1]!=1){
        printf("No\n");
        return 0;
    }

    dfs(a[1],-1,1);

    int ans = BFS();

    if(ans){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}
