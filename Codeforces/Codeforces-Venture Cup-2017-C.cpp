#include<bits/stdc++.h>
using namespace std;
#define mx 10005
vector<int>ed[mx];
bool vis[mx+5];
void dfs(int u)
{
    vis[u] = true;

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(vis[v]==false){
            dfs(v);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);

        for(int i=1; i<=n; i++){
            int x;
            scanf("%d",&x);
            ed[i].push_back(x);
            ed[x].push_back(i);
        }

        int cnt = 0;

        for(int i=1; i<=n; i++){
            if(vis[i]==false){
                cnt++;
                dfs(i);
            }
        }

        printf("%d\n",cnt);

    return 0;
}
