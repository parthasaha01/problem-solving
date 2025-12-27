#include<bits/stdc++.h>
using namespace std;
#define Mx 10001
vector<int>adj[Mx];
vector<int>res;
int indeg[Mx];
struct cmp
{
    bool operator()(const int& l, const int& r)
    {
        return l>r;
    }
};
bool topSort(int n)
{
    priority_queue<int,vector<int>,cmp>pq;

    for(int i=1; i<=n; i++)
    {
        if(indeg[i]==0)
        {
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        int u=pq.top();
        res.push_back(u);
        pq.pop();
        for(int j=0; j<adj[u].size(); j++)
        {
            int v=adj[u][j];
            indeg[v]--;
            if(indeg[v]==0)
            {
                pq.push(v);
            }
        }
    }

    if(res.size()!=n)
        return false;
    else
        return true;
}
int main()
{
    int n,m,u,v;
    bool flag;

    while(cin >> n >> m)
    {
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            indeg[v]++;
        }
        flag=topSort(n);

        if(flag)
        {
            for(int i=0; i<n; i++)
            {
                if(i==0)
                    printf("%d",res[i]);
                else
                    printf(" %d",res[i]);
            }
            cout << endl;
        }
        else
        {
            cout << "Sandro fails." << endl;
        }

        memset(indeg,0,sizeof(indeg));
        res.clear();
        for(int i=0; i<Mx; i++)
            adj[i].clear();
    }

    return 0;
}
