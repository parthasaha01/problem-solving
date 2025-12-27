#include<bits/stdc++.h>
using namespace std;

bool vis[120];
long long  arr[120],inf[120],inf1[120];

vector<long long >gp[120];

void dfs(int u,long long x)
{
    for(int i=0; i<gp[u].size(); i++)
    {
        int v=gp[u][i];
        inf1[v]+=x;
    }
}

int main()
{
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);

    for(int i=0; i<=n; i++)
        gp[i].clear();


    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        gp[u].push_back(v);
        gp[v].push_back(u);
    }

    if(t==0)
    {
        cout<<"1"<<endl;
        return 0;
    }

    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    inf[s]=1;
    for(int tt = 1; tt<=t; tt++)
    {
        memset(inf1,0,sizeof(inf1));

        for(int i=0; i<n; i++)
        {
            if(inf[i]>0)
            {
                dfs(i,inf[i]);
            }
        }

        for(int i=0; i<n; i++)
        {
            inf[i]=inf1[i];
        }
    }

    long long  cnt=0;
    for(int i=0; i<n; i++)
        cnt+=inf1[i];
    cout<<cnt<<endl;

    return 0;
}

