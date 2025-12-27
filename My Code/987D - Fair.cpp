#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define MAXN 100005
#define INF 10000000
int n,m,s,k;
int ans[MAXN],dp[MAXN][105];
vector<int>ed[MAXN];
vector<int>vv[105];
void BFS(int c)
{
    for(int i=1; i<=n; i++)dp[i][c] = INF;

    queue<pii>Q;
    for(int i=0;i<vv[c].size(); i++){
        Q.push(mp(vv[c][i],0));
        dp[vv[c][i]][c] = 0;
    }

    while(!Q.empty())
    {
        pii nd = Q.front();
        Q.pop();

        int u = nd.first;
        int w = nd.second;

        for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
            if(dp[v][c]>dp[u][c]+1){
                dp[v][c] = dp[u][c]+1;
                Q.push(mp(v,dp[v][c]));
            }
        }
    }

}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>n>>m>>k>>s;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        vv[x].push_back(i);
    }

    for(int i=1; i<=m; i++){
        int u,v; cin>>u>>v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    for(int i=1; i<=k; i++) BFS(i);

    for(int i=1; i<=n; i++)sort(dp[i]+1,dp[i]+k+1);

    for(int i=1; i<=n; i++){
        ans[i] = 0;
        for(int j=1; j<=s; j++){
            ans[i]+=dp[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        if(i<n)cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }

    return 0;
}
