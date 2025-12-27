/// Given a rooted tree. The root of the tree is vertex 1 and
/// every vertex has color. Query is how many vertices
/// in subtree of vertex v are colored with color c?

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int cnt[MAXN],col[MAXN],ans[MAXN];
vector<int>adj[MAXN];
vector< pair<int,int> >qry[MAXN],qqq;
void add(int u,int p,int x)
{
    cnt[col[u]] += x;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p)continue;
        add(v,u,x);
    }
}
void dfs(int u,int p)
{
    add(u,p,1);
    /// now cnt[c] is the number of vettices in subtree of vertex v that has color c.
    /// we can answer the queries easily
    for(int i=0; i<qry[u].size(); i++){
        int c  = qry[u][i].first;
        int id = qry[u][i].second;
        ans[id] = cnt[c];
    }

    add(u,p,-1);

    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p)continue;
        dfs(v,u);
    }
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&col[i]);
    }
    for(int i=1; i<n; i++){
        int u,v; scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q; scanf("%d",&q);
    for(int i=1; i<=q; i++){
        int v,c; scanf("%d%d",&v,&c);
        qry[v].push_back(make_pair(c,i));
        qqq.push_back(make_pair(v,c));
    }

    dfs(1,-1);

    for(int i=1; i<=q; i++){
        int v = qqq[i-1].first;
        int c = qqq[i-1].second;
        printf("%d %d: %d\n",v,c,ans[i]);
    }

    return 0;
}

/*

15
1 2 3 1 2 3 3 1 1 3 2 2 1 2 3
1 2
1 3
1 4
1 14
1 15
2 5
2 6
2 7
3 8
3 9
3 10
4 11
4 12
4 13

45
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2
3 3
4 1
4 2
4 3
5 1
5 2
5 3
6 1
6 2
6 3
7 1
7 2
7 3
8 1
8 2
8 3
9 1
9 2
9 3
10 1
10 2
10 3
11 1
11 2
11 3
12 1
12 2
12 3
13 1
13 2
13 3
14 1
14 2
14 3
15 1
15 2
15 3

*/
