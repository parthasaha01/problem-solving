/*** Min Max Roads:
You live in a big country where there are many bi directional roads connecting the cities.
Here cities are denoted by integers and each road has a cost of traveling. Now you are given
the information about the Country. And you are given some queries, each consists of two cities.
You have to find the shortest and longest road in the path from one city to another.

Input starts with an integer T(≤ 5) number of test cases. The next line contains n(2≤n≤10^5) 
denoting the number of cities. Then there will be n-1 lines containing three integers each.
They will be given in the form u v w (1 ≤ u, v ≤ n, 0 < w ≤ 105, u ≠ v) meaning that there is
a road between u and v and the cost of the road is w.
The next line contains an integer q (1 ≤ q ≤ 25000) denoting the number of queries.
Each of the next q lines contains two integers x and y (1 ≤ x, y ≤ n, x ≠ y).

For each case, print the case number in a single line. Then for each query x y,
you should print one line containing the shortest and longest road along the path.
***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define inf 0x7f7f7f7f
#define mod 1000000007
#define mxx 100005
vector<pair<int,int> >g[mxx];
int WMN[mxx][32],WMX[mxx][32];
int P[mxx][32],visited[mxx],level[mxx];
int mn,mx;
void dfs(int u){
    visited[u] = 1;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i].first;
        int w = g[u][i].second;
        if(!visited[v]){
            level[v] = level[u]+1;
            P[v][0] = u;
            WMN[v][0] = w;
            WMX[v][0] = w;
            dfs(v);
        }
    }
}
void SparseTable(int n){
    int lg=log2(n);
    for(int j=1; j<=lg; j++){
        for(int i=1;i<=n;i++){
            if(P[i][j-1]==-1){
                P[i][j] = P[i][j-1];
                WMN[i][j] = WMN[i][j-1];
                WMX[i][j] = WMX[i][j-1];
            }else{
                int p = P[i][j-1];
                P[i][j] = P[p][j-1];
                WMN[i][j] = min(WMN[i][j-1],WMN[p][j-1]);
                WMX[i][j] = max(WMX[i][j-1],WMX[p][j-1]);
            }
        }
    }
}
void lca(int n, int u, int v){
    if(level[u]<level[v]) swap(u,v);
    int lg=log2(n);
    for(int i=lg;i>=0;i--){
        if(P[u][i]!=-1 && level[u]-(1<<i) >= level[v]){
            mn = min(mn,WMN[u][i]);
            mx = max(mx,WMX[u][i]);
            u = P[u][i];
        }
    }
    if(u==v) return;
    for(int i=lg; i>=0; i--){
        if(P[u][i]!=-1 && P[u][i]!=P[v][i]){
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
int main(){
    int test,cs=1;
    scanf("%d",&test);
    while(test--){
        printf("Case %d:\n",cs++);
        int n; scanf("%d",&n);
        for(int i=0; i<=n; i++) g[i].clear();

        for(int i=1; i<n; i++){
            int u,v,w; scanf("%d%d%d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        for(int i=0; i<=n; i++) visited[i]=0;
        level[1] = 0;
        P[1][0] = -1;
        WMN[1][0] = inf;
        WMX[1][0] = 0;

        dfs(1);

        SparseTable(n);

        int q; scanf("%d",&q);
        while(q--){
            int x,y; scanf("%d%d",&x,&y);
            mn = inf;
            mx = 0;
            lca(n,x,y);
            if(mn==inf) mn=0;
            printf("%d %d\n",mn,mx);
        }
    }
    return 0;
}


