#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>ed[mx+5],re[mx+5],L[mx+5],R[mx+5];
bool vis[mx+5];
int vs[mx+5];
void dfs1(int u,int id)
{
    vis[u]=true;
    vs[u] = id;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(!vis[v]){
           dfs1(v,id);
        }
    }
    L[id].push_back(u);
}
void dfs2(int u,int gr,int id)
{
    vis[u]=true;
    for(int i=0; i<re[u].size(); i++)
    {
        int v = re[u][i];
        if(!vis[v] && vs[v]==id){
           dfs2(v,gr,id);
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
        int id=0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                id++;
                dfs1(i,id);
                reverse(L[id].begin(),L[id].end());
            }
        }

        memset(vis,false,sizeof(vis));
        int gr=0;
        for(int i=1; i<=id; i++)
        {
            for(int j=0; j<L[i].size(); j++){
                int u = L[i][j];
                if(!vis[u]){
                    gr++;
                    dfs2(u,gr,i);
                    sort(R[gr].begin(),R[gr].end());
                }
            }
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


        for(int i=1; i<=id; i++)L[i].clear();
        for(int i=1; i<=gr; i++)R[i].clear();
        for(int i=1; i<=n; i++)ed[i].clear();
        for(int i=1; i<=n; i++)re[i].clear();
    }
    return 0;
}
/*
8
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

11 13
1 2
2 3
3 1
2 4
4 5
5 6
6 4
7 6
7 8
8 9
9 10
10 7
10 11


*/
