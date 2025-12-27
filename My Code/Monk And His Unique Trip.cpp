#include<bits/stdc++.h>
using namespace std;
int dis[100005],low[100005],par[100005],vis[100005],pp[100005],gn[100005];
vector<int>ed[100005],scc[100005];
int tim,root,gr,cnt;
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
        else
        {
            cnt += pp[gn[v]];
        }
    }

    vis[u]=2;

    if(dis[u]==low[u])
    {
        gr++;
        cnt++;
        while(st.top()!=u)
        {
            int w = st.top();
            st.pop();
            gn[w]=gr;
            //scc[gr].push_back(w);
        }
        int w = st.top();
        st.pop();
        gn[w]=gr;
        //scc[gr].push_back(w);
        //sort(scc[gr].begin(),scc[gr].end());
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1; i<=m; i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
        }

        memset(vis,0,sizeof(vis));
        memset(pp,0,sizeof(pp));
        memset(gn,0,sizeof(gn));

        tim=0;gr=0;
        int ans=0;
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                cnt=0;
                dfs(i);
                pp[gr]=cnt;
                cnt--;
                ans=max(ans,cnt);
            }
        }

        printf("%d\n",ans);

        for(int i=1; i<=n; i++)ed[i].clear();
        //for(int i=1; i<=gr; i++)scc[i].clear();
        while(!st.empty())st.pop();
    }
    return 0;
}

/*

7 8
1 2
2 3
3 1
1 4
4 6
5 6
6 5
4 7

*/

