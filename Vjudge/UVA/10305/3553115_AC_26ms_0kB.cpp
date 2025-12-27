#include<bits/stdc++.h>
using namespace std;
#define Mx 101
vector<int>adj[Mx];
vector<int>res;
int indeg[Mx];
void topSort(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(indeg[i]==0)
        {
            res.push_back(i);
        }
    }

    for(int i=0; i<res.size(); i++)
    {
        int u=res[i];
        for(int j=0; j<adj[u].size(); j++)
        {
            int v=adj[u][j];
            indeg[v]--;
            if(indeg[v]==0){
                res.push_back(v);
            }
        }
    }
}
int main()
{
    int n,m,u,v;

    while(cin >> n >> m)
    {
        if(!n && !m)
            break;

        for(int i=0; i<m; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            indeg[v]++;
        }
        topSort(n);
        for(int i=0; i<n; i++){
            cout << res[i];
            if(i<n-1)
                cout << " ";
        }
        cout << endl;

        memset(indeg,0,sizeof(indeg));
        res.clear();
        for(int i=0;i<Mx;i++)
            adj[i].clear();
    }

    return 0;
}
