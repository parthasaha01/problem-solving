#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define PI acos(-1.0)
#define inf 0x7f7f7f7f
#define mod 1000000007

vector<pair<int,int> >g[100005];
int WMN[100005][32];
int WMX[100005][32];
int P[100005][32];
int visited[100005];
int level[100005];
int mn,mx;

void dfs(int u)
{
    int i;
    int sz = g[u].size();
    visited[u] = 1;
    for(i=0; i<sz; i++)
    {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if(!visited[v])
        {
            level[v] = level[u]+1;
            P[v][0] = u;
            WMN[v][0] = w;
            WMX[v][0] = w;
            dfs(v);
        }
    }
}

void SparseTable(int n)
{
    int i,j,lg=log2(n);
    for(j=1; j<=lg; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(P[i][j-1]==-1)
            {
                P[i][j] = P[i][j-1];
                WMN[i][j] = WMN[i][j-1];
                WMX[i][j] = WMX[i][j-1];
            }
            else
            {
                int p = P[i][j-1];
                P[i][j] = P[p][j-1];
                WMN[i][j] = min(WMN[i][j-1],WMN[p][j-1]);
                WMX[i][j] = max(WMX[i][j-1],WMX[p][j-1]);
            }
        }
    }
}

void lca(int n, int u, int v)
{
    if(level[u]<level[v]) swap(u,v);
    int i,j,lg=log2(n);
    for(i=lg; i>=0; i--)
    {
        if(P[u][i]!=-1 && level[u]-(1<<i) >= level[v])
        {
            mn = min(mn,WMN[u][i]);
            mx = max(mx,WMX[u][i]);
            u = P[u][i];
        }
    }
    if(u==v) return;
    for(i=lg; i>=0; i--)
    {
        if(P[u][i]!=-1 && P[u][i]!=P[v][i])
        {
            mn = min(mn,min(WMN[u][i],WMN[v][i]));
            mx = max(mx,max(WMX[u][i],WMX[v][i]));
            u = P[u][i];
            v = P[v][i];
        }
    }
    mn = min(mn,min(WMN[u][0],WMN[v][0]));
    mx = max(mx,max(WMX[u][0],WMX[v][0]));
    return;
}

int main()
{
    int test,cs=1;
    int n,q,i,j,m;
    scanf("%d",&test);
    while(test--)
    {
        printf("Case %d:\n",cs++);
        scanf("%d",&n);
        for(i=0; i<=n; i++) g[i].clear();
        m=n-1;
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back({v,w});  // only support c++11
            g[v].push_back({u,w});
        }
        for(i=0; i<=n; i++) visited[i]=0;
        level[1] = 0;
        P[1][0] = -1;
        WMN[1][0] = inf;
        WMX[1][0] = 0;
        dfs(1);

        SparseTable(n);

        scanf("%d",&q);
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mn = inf;
            mx = 0;
            lca(n,x,y);
            if(mn==inf) mn=0;
            printf("%d %d\n",mn,mx);
        }
    }
    return 0;
}
