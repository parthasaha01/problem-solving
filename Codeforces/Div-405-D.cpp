#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define ll long long
vector<int>ed[mx+5];
bool vis[mx+5];
void dfs(int u)
{
    vis[u]=true;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==false){
            dfs(v);
        }
    }
}
int main()
{
    int n,k;

    while(scanf("%d%d",&n,&k)==2)
    {
        for(int i=1; i<=n-1; i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        int ans = 0;


        cout << ans << endl;
        for(int i=0; i<=n; i++)ed[i].clear();
    }

    return 0;
}

