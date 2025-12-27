#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 300005
ll dp[mx];
//bool vis[mx];
vector<int>ed[mx];
void DFS(int u,int pr)
{
    dp[u] = 1;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==pr)continue;
        DFS(v,u);
        dp[u] += dp[v];
    }
}
int main()
{
    int n,f,b; scanf("%d%d%d",&n,&f,&b);

    for(int i=1; i<n; i++){
        int u,v;
        scanf("%d %d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    memset(dp,0,sizeof(dp));
    DFS(f,0);
    ll x = dp[b];

    memset(dp,0,sizeof(dp));
    DFS(b,0);
    ll y = dp[f];

    ll total = ((ll)n*n)-n;

    ll ans = total-(x*y);

    if(ans<0)ans = 0;

    printf("%I64d\n",ans);

    return 0;
}
/*
10 1 10
1 2
1 10
1 3
2 8
2 4
2 5
3 6
3 7
3 9

6 2 6
1 2
1 3
1 4
1 5
1 6

6 1 6
1 2
1 3
1 4
1 5
1 6
*/
