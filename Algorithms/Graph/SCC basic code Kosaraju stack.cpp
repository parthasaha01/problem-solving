#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>ed[mx+5],re[mx+5],R[mx+5];
bool vis[mx+5];
stack<int>st;
void dfs1(int u)
{
    vis[u]=true;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(!vis[v]){
           dfs1(v);
        }
    }
    st.push(u);
}
void dfs2(int u,int gr)
{
    vis[u]=true;
    for(int i=0; i<re[u].size(); i++)
    {
        int v = re[u][i];
        if(!vis[v]){
           dfs2(v,gr);
        }
    }
    R[gr].push_back(u);
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
            re[v].push_back(u);
        }

        memset(vis,false,sizeof(vis));
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                dfs1(i);
            }
        }

        memset(vis,false,sizeof(vis));
        int gr=0;
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            if(vis[u])continue;

            gr++;
            dfs2(u,gr);
            sort(R[gr].begin(),R[gr].end());
        }

        for(int i=1; i<=gr; i++)
        {
            printf("Group %d:",i);
            for(int j=0; j<R[i].size(); j++){
                int u = R[i][j];
                printf(" %d",u);
            }
            printf("\n");
        }

        for(int i=1; i<=gr; i++)R[i].clear();
        for(int i=1; i<=n; i++)ed[i].clear();
        for(int i=1; i<=n; i++)re[i].clear();
    }
    return 0;
}
/*
8

5 7
1 2
2 3
2 4
3 1
4 5
5 1
5 3

5 6
1 2
3 2
2 4
4 5
5 1
5 3

3 3
1 2
2 3
3 2

3 3
1 2
2 3
3 1

3 2
1 2
3 2

3 4
1 2
2 1
3 1
3 2

7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5





*/

