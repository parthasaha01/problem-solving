#include "iostream"
#include "vector"
#include "math.h"
using namespace std;
#define MAXN 1001

int block_sz,height;          // block size = sqrt(height)
int depth[MAXN];       // stores depth for each node
int parent[MAXN];      // stores first parent for
                       // each node
int jump_parent[MAXN]; // stores first ancestor in
                       // previous block

vector < int > adj[MAXN];

void dfsHeight(int u,int h,int pr)
{
    height = max(height,h);
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v!=pr)dfsHeight(v,h+1,u);
    }
}
int LCANaive(int u,int v)
{
    if (u == v)  return u;
    if (depth[u] > depth[v])
        swap(u,v);
    v = parent[v];
    return LCANaive(u,v);
}

// precalculating the required parameters
// associated with every node
void dfs(int cur, int prev)
{
    // marking depth of cur node
    depth[cur] = depth[prev] + 1;

    // marking parent of cur node
    parent[cur] = prev;

    // making jump_parent of cur node
    if (depth[cur] % block_sz == 0)

        /* if it is first node of the block
           then its jump_parent is its cur parent */
        jump_parent[cur] = parent[cur];

    else

        /* if it is not the first node of this block
           then its jump_parent is jump_parent of
           its parent */
        jump_parent[cur] = jump_parent[prev];


    // propogating the marking down the subtree
    for (int i = 0; i<adj[cur].size(); ++i)
        if (adj[cur][i] != prev)
            dfs(adj[cur][i], cur);
}


// using sqrt decomposition trick
int LCASQRT(int u, int v)
{
    while (jump_parent[u] != jump_parent[v])
    {
        if (depth[u] > depth[v])

            // maintaining depth[v] > depth[u]
            swap(u,v);

        // climb to its jump parent
        v = jump_parent[v];
    }

    // u and v have same jump_parent
    return LCANaive(u,v);
}
void preprocess()
{
   height = 0;
   dfsHeight(1,1,0);
   block_sz = sqrt(height);
   depth[0] = -1;

    // precalclating 1)depth.  2)parent.  3)jump_parent
    // for each node
    dfs(1, 0);
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)break;

        for(int i=1; i<n; i++){
            int u,v; scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        preprocess();

        int q; scanf("%d",&q);
        while(q--)
        {
            int u,v; scanf("%d%d",&u,&v);
            int lca = LCASQRT(u,v);
            printf("%d\n",lca);
        }

        for(int i=0; i<=n; i++)adj[i].clear();
    }
    return 0;
}
