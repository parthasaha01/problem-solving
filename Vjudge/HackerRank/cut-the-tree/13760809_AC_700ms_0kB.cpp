#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int dp[mx+5],a[mx+5];
vector<int>ed[mx];
void dfs(int u,int pr)
{
    dp[u] = a[u];

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v!=pr){
            dfs(v,u);
            dp[u]+=dp[v];
        }
    }
}
int main()
{
    int n; scanf("%d",&n);
    int sum = 0;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    for(int i=1; i<n; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    dfs(1,0);

    int ret = 1000000000;

    for(int i=2; i<=n; i++){
        int p = sum-dp[i];
        int d = abs(p-dp[i]);
        ret = min(ret,d);
    }

    printf("%d\n",ret);

    return 0;
}
