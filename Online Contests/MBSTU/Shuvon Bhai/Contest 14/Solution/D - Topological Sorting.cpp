#include <bits/stdc++.h>
using namespace std;
int outdeg[1002];
int indeg[1002];
int adj[1002][10002];
int ans[1002];

int main()
{
    long n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u][outdeg[u]++] = v;
        indeg[v]++;
    }
    for(int i=0;i<n;i++)
        cin>>ans[i];

    int flag=1;
    for(int i=0;i<n;i++)
    {
        u=ans[i];
        if (indeg[u]>0)
        {
            flag=0;
            break;
        }
        for(int j=0; j<outdeg[u]; j++)
        {
            v=adj[u][j];
            indeg[v]--;
        }
    }

    if(flag)
        cout <<"YES";
    else
        cout << "NO";

    return 0;
}
