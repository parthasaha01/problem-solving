#include<bits/stdc++.h>
using namespace std;
vector<int>ed[50],vv[20];
queue<int>a;
int vis[50],deg[50];
void dfs(int u,int id)
{
    vis[u]=1;
    vv[id].push_back(u);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(vis[v]==0)dfs(v,id);
    }
}
int main()
{
    int n,m; cin>>n>>m;
    for(int i=1; i<=m; i++){
        int u,v; cin>>u>>v;
        ed[u].push_back(v);
        ed[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int id = 0,f=1;
    for(int i=1; i<=n; i++){
        if(deg[i]==0)a.push(i);
        if(deg[i]>0&&vis[i]==0){
            dfs(i,++id);
            if(vv[id].size()>3){
                cout<<-1<<endl; return 0;
            }
        }
    }

    for(int i=1; i<=id; i++){
        if(vv[i].size()==3)continue;
        if(a.size()==0){
            cout<<-1<<endl; return 0;
        }
        vv[i].push_back(a.front());
        a.pop();
    }

    while(!a.empty()){
        int x = a.front(); a.pop();
        int y = a.front(); a.pop();
        int z = a.front(); a.pop();
        vv[++id].push_back(x);
        vv[id].push_back(y);
        vv[id].push_back(z);
    }

    for(int i=1; i<=id; i++){
        cout<<vv[i][0]<<" "<<vv[i][1]<<" "<<vv[i][2]<<endl;
    }

    return 0;
}
