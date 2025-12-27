#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1005
ll hh[mx],pp[mx];
bool vis[mx];
int ans[mx],n;
int dfs(int u,ll mxx)
{
    vis[u]=true;
    if(u==n)return ans[u]=1;

    mxx = max(mxx,hh[u]+pp[u]);

    if(mxx<=pp[u+1])
        return ans[u]=1;

    ans[u] = 1 + dfs(u+1,mxx);
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%lld",&hh[i]);
    for(int i=1; i<=n; i++)scanf("%lld",&pp[i]);
    pp[n+1]=10000000000000LL;

    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs(i,0LL);

    int m; scanf("%d",&m);

    for(int i=1; i<=m; i++){
        int x; scanf("%d",&x);
        printf("%d\n",ans[x]);
    }

    return 0;
}

