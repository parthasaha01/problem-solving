#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
vector<int>gp[mx],cost[mx];
int arr[mx];

bool vis[mx]={0};

ll dfs(int u,ll w,int p)
{
    if(w>arr[u])
        return 0;
    vis[u]=1;
    int ans=0;
    for(int i=0;i<gp[u].size();i++)
    {
        int v=gp[u][i];
        if(v!=p)
        {
           ans += dfs(v,max(w+cost[u][i],0LL),u);
        }
    }
    return 1+ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(int i=2;i<=n;i++)
    {
        int u,w;
        scanf("%d%d",&u,&w);
        cost[u].push_back(w);
        cost[i].push_back(w);
        gp[u].push_back(i);
        gp[i].push_back(u);
    }

    printf("%lld\n",n-dfs(1,0,0));



    return 0;
}