#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>ed[mx];
stack<int>st;
bool vis[mx];
void TOPSORT(int u)
{
    vis[u]=true;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==false){
            TOPSORT(v);
        }
    }
    st.push(u);
}
void DFS(int u)
{
    vis[u]=true;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==false){
            DFS(v);
        }
    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,m; scanf("%d%d",&n,&m);

        for(int i=1; i<=m; i++){
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
        }

        memset(vis,false,sizeof(vis));

        for(int i=1; i<=n; i++){
            if(vis[i]==false){
                TOPSORT(i);
            }
        }

        int ans = 0;
        memset(vis,false,sizeof(vis));

        while(!st.empty())
        {
            int u = st.top();
            st.pop();

            if(vis[u]==false){
                ans++;
                DFS(u);
            }
        }

        printf("%d\n",ans);

        for(int i=1; i<=n; i++)ed[i].clear();

    }
    return 0;
}
