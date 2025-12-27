#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<int>ed[105];
vector<int>rnk[105];
bool vis[105];
int cnt;
void dfs(int u)
{
    vis[u]=true;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v=ed[u][i];
        if(vis[v]==false)
        {
            cnt++;
            dfs(v);
        }
    }
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;

        ed[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        cnt=0;
        for(int k=0; k<104; k++)
        {
            vis[i]=false;
        }

        dfs(i);
        rnk[cnt+1].push_back(i);
    }

    int sum=0;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int sz=rnk[i].size();

        sum+=sz;
        if(sz!=0)
        {
            if(i==sum)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
