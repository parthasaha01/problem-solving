#include<bits/stdc++.h>
using namespace std;
#define mx 10005
#define mp make_pair
#define pii pair<int,int>
#define ff first
#define sc second
vector<pii>ed[mx];
int n,T[mx],L[mx],W[mx],P[mx][20];

void dfs(int u,int fr,int lv,int wt)
{
    T[u] = fr;
    L[u] = lv;
    W[u] = wt;

    for(int i=0; i<ed[u].size(); i++){
        pii p = ed[u][i];
        int v = p.ff;
        if(v==fr)continue;
        dfs(v,u,lv+1,wt+p.sc);
    }
}
void lca_init()
{
    memset(P,-1,sizeof(P));

    for(int i=1; i<=n; i++)P[i][0] = T[i];

    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i<=n; i++){
            if(P[i][j-1]!=-1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int lca_query(int u,int v)
{
    if(L[u]<L[v])swap(u,v);

    int log = (int)log2(n);

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && L[u]-(1<<i)>=L[v]){
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
int findKth(int u,int k)
{
    int log = (int)log2(k);
    while(log>=0){
        u = P[u][log];
        k -= (1<<log);
        if(k<=0)break;
        log = (int)log2(k);
    }
    return u;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n-1; i++){
            int u,v,w; scanf("%d%d%d",&u,&v,&w);
            pii p = mp(v,w);
            ed[u].push_back(p);
            p = mp(u,w);
            ed[v].push_back(p);
        }

        dfs(1,0,0,0);
        lca_init();

        char s[20];
        while(scanf("%s",s))
        {
            if(strcmp(s,"DONE")==0) break;
            if(strcmp(s,"DIST")==0){
                int u,v; scanf("%d%d",&u,&v);
                if(u==v){
                    printf("0\n"); continue;
                }
                int lca = lca_query(u,v);
                int dist = W[u]+W[v]-2*W[lca];
                printf("%d\n",dist);
            }
            else{
                int u,v,k; scanf("%d%d%d",&u,&v,&k);
                if(k==1){
                    printf("%d\n",u); continue;
                }

                k--;
                int lc = lca_query(u,v);

                int du = abs(L[u]-L[lc]);
                int dv = abs(L[v]-L[lc]);

                int kth=0;
                if(du>=k) kth = findKth(u,k);
                else kth = findKth(v,dv+du-k);

                printf("%d\n",kth);
            }
        }
        for(int i=0; i<=n; i++)ed[i].clear();
    }

    return 0;
}
