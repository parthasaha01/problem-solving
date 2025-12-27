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
    int n,u,v;
    long m;
    bool flag;

    //while(cin >> n >> m)
    //{

    cin >> n >> m;

        for(long i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            indeg[v]++;
        }
        int a[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }

        if(m==0){
           cout << "YES";
           //continue;
        }

        //if(m!=0)
        else
        {

            flag=topSort(n);

        if(flag)
        {
            for(int i=0; i<n; i++)
            {
                if(a[i]!=res[i]){
                    flag=false;
                    break;
                }
            }

            if(flag)
                cout << "YES";
            else
                cout << "NO";
        }
        else
        {
            cout << "NO";
        }
    }

        memset(indeg,0,sizeof(indeg));
        res.clear();
        for(int i=0; i<Mx; i++)
            adj[i].clear();
    //}

    return 0;
}
