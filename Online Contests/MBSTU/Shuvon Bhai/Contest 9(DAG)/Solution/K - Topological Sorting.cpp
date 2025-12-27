#include<bits/stdc++.h>
using namespace std;
#define Mx 10005
vector<int>adj[Mx];
vector<int>res;
int indeg[Mx];
int main()
{
    int n,m,u,v;

    scanf("%d %d",&n,&m);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        indeg[v]++;
    }

    priority_queue<int>pq;

    for(int i=1; i<=n; i++)
    {
        if(indeg[i]==0)
        {
            pq.push(-i);
        }
    }
    while(!pq.empty())
    {
        int u=-pq.top();
        res.push_back(u);
        pq.pop();
        for(int j=0; j<adj[u].size(); j++)
        {
            int v=adj[u][j];
            indeg[v]--;
            if(indeg[v]==0)
            {
                pq.push(-v);
            }
        }
    }

    if(res.size()!=n)
        printf("Sandro fails.\n");
    else
    {
        for(int i=0; i<n; i++)
        {
            if(i==0)
                printf("%d",res[i]);
            else
                printf(" %d",res[i]);
        }
        printf("\n");
    }

    return 0;
}
