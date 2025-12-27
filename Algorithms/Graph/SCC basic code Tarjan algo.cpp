#include<bits/stdc++.h>
using namespace std;
int dis[100005],low[100005],par[100005],vis[100005];
vector<int>ed[100005],scc[100005];
int tim,root,gr;
stack<int>st;

void dfs(int u)
{
    vis[u]=1;
    dis[u]=++tim;
    low[u]=tim;

    st.push(u);

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];

        if(vis[v]==0)
        {
            par[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]==1)
        {
            low[u]=min(low[u],dis[v]);
        }
    }

    vis[u]=2;

    if(dis[u]==low[u])
    {
        gr++;
        while(st.top()!=u)
        {
            int w = st.top();
            st.pop();
            scc[gr].push_back(w);
        }
        int w = st.top();
        st.pop();
        scc[gr].push_back(w);
        sort(scc[gr].begin(),scc[gr].end());
    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,m; scanf("%d%d",&n,&m);

        for(int i=1; i<=m; i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
        }

        memset(vis,0,sizeof(vis));
        tim=0;gr=0;
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                dfs(i);
            }
        }

        for(int i=1; i<=gr; i++)
        {
            printf("Group %d:",i);
            for(int j=0; j<scc[i].size(); j++){
                int u = scc[i][j];
                printf(" %d",u);
            }
            printf("\n");
        }

        for(int i=1; i<=n; i++)ed[i].clear();
        for(int i=1; i<=gr; i++)scc[i].clear();
        while(!st.empty())st.pop();
    }
    return 0;
}
/*
8
8 9
1 2
1 3
2 3
3 4
4 5
5 6
5 7
6 7
6 8

20 27
1 2
2 3
3 4
4 5
5 6
6 8
6 7
8 7
7 5
5 16
3 16
4 9
3 9
9 10
10 11
11 13
13 15
13 14
14 11
11 12
12 9
12 17
17 18
18 19
19 20
18 20
1 3

*/
