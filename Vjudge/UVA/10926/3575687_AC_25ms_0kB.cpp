#include<bits/stdc++.h>
using namespace std;
#define mx 101
vector<int>adj[mx];
int visited[mx];
int cnt;
void CLEAR()
{
    for(int i=0; i<=mx; i++)
        adj[i].clear();

}
void DFS(int u)
{
    visited[u]=1;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];

        if(visited[v]==0)
        {
            DFS(v);
            ++cnt;
        }
    }

    return ;
}
int main()
{
    int N,T,u,v,MAX,node;

    while(cin >> N && N)
    {
        for(u=1; u<=N; u++)
        {
            cin >> T;
            for(int i=0; i<T; i++)
            {
                cin >> v;
                adj[u].push_back(v);
            }
        }

        MAX=-1;

        for(int i=1; i<=N; i++)
        {
            memset(visited,0,sizeof(visited));
            cnt=0;
            DFS(i);
            if(cnt>MAX){
                MAX=cnt;
                node=i;
            }
        }

        cout << node << endl;

        CLEAR();
    }

    return 0;
}
