/// Given a rooted tree. The root of the tree is vertex 1 and
/// every vertex has color. Query is how many vertices
/// in subtree of vertex v are colored with color c?

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int sz[MAXN],col[MAXN],cnt[MAXN],ans[MAXN];
vector<int> *vec[MAXN];
vector<int> adj[MAXN];
vector< pair<int,int> >qry[MAXN],qqq;

void getsz(int u,int p){
    sz[u]=1;
    for(auto v : adj[u]){
        if(v==p)continue;
        getsz(v,u);
        sz[u] += sz[v];
    }
}

void dfs(int u,int p,bool keep){
    int maxx = -1, bigchild = -1;
    for(auto v : adj[u]){
        if(v==p)continue;
        if(sz[v]>maxx){
            maxx = sz[v];
            bigchild = v;
        }
    }

    for(auto v : adj[u]){
        if(v!=p && v!=bigchild){
            dfs(v,u,0);
        }
    }

    if(bigchild!=-1){
        dfs(bigchild,u,1);
        vec[u] = vec[bigchild];
    }
    else{
        vec[u] = new vector<int> ();
    }

    vec[u]->push_back(u);
    cnt[col[u]]++;

    for(auto v : adj[u]){
        if(v!=p && v!=bigchild){
            for(auto x : *vec[v]){
                cnt[col[x]]++;
                vec[u]->push_back(x);
            }
        }
    }

    /// now (*cnt[v])[c] is the number of vettices in subtree of vertex v that has color c.
    /// we can answer the queries easily
    /// note that in tis step (*vec[u]) contains all the nodes of the subtree of vertex u.

    for(int i=0; i<qry[u].size(); i++){
        int c  = qry[u][i].first;
        int id = qry[u][i].second;
        ans[id] = cnt[c];
    }

    if(keep==0){
        for(auto v : *vec[u]){
            cnt[col[v]]--;
        }
    }
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&col[i]);
    }
    for(int i=1; i<n; i++){
        int u,v; scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    getsz(1,-1);

    int q; scanf("%d",&q);
    for(int i=1; i<=q; i++){
        int v,c; scanf("%d%d",&v,&c);
        qry[v].push_back(make_pair(c,i));
        qqq.push_back(make_pair(v,c));
    }

    dfs(1,-1,0);

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


