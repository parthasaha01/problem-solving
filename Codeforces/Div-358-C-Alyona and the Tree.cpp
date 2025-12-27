#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
int a[mx];
vector<int>ed[mx];
vector<int>cost[mx];
bool vis[mx];
int cnt;
void dfs(int u, ll need)
{
    if(a[u]<need)
        return;
    else
        ++cnt;

    int sz=ed[u].size();

    vis[u]=true;

    for(int i=0; i<sz; i++)
    {
        int v = ed[u][i];

        if(vis[v]==false)
        {
            if(need<=0)
                dfs(v,cost[u][i]);
            else
                dfs(v,need+cost[u][i]);
        }
    }

    return;
}
int main()
{
    int n,p,c,res;

    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    for(int i=2; i<=n; i++)
    {
        scanf("%d %d",&p,&c);
        ed[i].push_back(p);
        ed[p].push_back(i);
        cost[i].push_back(c);
        cost[p].push_back(c);
    }

    dfs(1,0);

    printf("%d\n",n-cnt);

    return 0;
}
