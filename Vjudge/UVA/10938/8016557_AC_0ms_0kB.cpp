#include<bits/stdc++.h>
using namespace std;
#define mx 5005
int n,T[mx],L[mx],P[mx][15];
vector<int>ed[mx];
void dfs(int u,int fr,int lv)
{
    T[u] = fr;
    L[u] = lv;

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==fr)continue;
        dfs(v,u,lv+1);
    }
}
void lca_init()
{
    memset(P,-1,sizeof(P));
    for(int i=1; i<=n; i++) P[i][0] = T[i];
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i<=n; i++){
            if(P[i][j-1]!=-1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int lca_query(int u,int v)
{
    int log = (int)log2(n);

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && L[u]-(1<<i)>=L[v]){    // L[P[u][i]] = L[u]-(1<<i)
            u = P[u][i];
        }
    }
    if(u==v) return u;

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && P[u][i]!=P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }
    return T[u];
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<=n; i++)ed[i].clear();

        for(int i=1; i<=n-1; i++){
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        dfs(1,0,0);

        lca_init();
        int q; scanf("%d",&q);

        while(q--)
        {
            int u,v; scanf("%d%d",&u,&v);
            if(L[u]<L[v]){
               swap(u,v);
            }
            int lca = lca_query(u,v);
            int path = abs(L[lca]-L[u]) + abs(L[lca]-L[v]);
            if(path%2==0){
                if(L[u]==L[v]) printf("The fleas meet at %d.\n",lca);
                else{
                    int d = path/2;
                    int x = (int)log2(d);
                    while(x>=0)
                    {
                        u = P[u][x];
                        d -= (1<<x);
                        if(d<=0)break;
                        x = (int)log2(d);
                    }
                    printf("The fleas meet at %d.\n",u);
                }
            }
            else{
                int lv = path/2;
                int d = (int)log2(lv);
                int x = u;
                while(d>=0)
                {
                    x = P[x][d];
                    lv -= (1<<d);
                    if(lv<=0)break;
                    d = (int)log2(lv);
                }

                lv = (path/2)+1;
                d = (int)log2(lv);
                int y = u;
                while(d>=0)
                {
                    y = P[y][d];
                    lv -= (1<<d);
                    if(lv<=0)break;
                    d = (int)log2(lv);
                }

                if(x>y) swap(x,y);
                printf("The fleas jump forever between %d and %d.\n",x,y);
            }
        }
    }

    return 0;
}
