#include<bits/stdc++.h>
using namespace std;
bitset<10005> node[10005];
vector<int>adj[10005];
int T[10005], L[10005];
int P[10005][15];
void dfs(int u,int p, int lev, bitset<10005> b) {
    b.set(u);
    node[u] = b;
    T[u] = p;
    L[u] = lev;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p)continue;
        dfs(v,u,lev+1,b);
    }
}
void lca_init(int n)
{
    memset(P,-1,sizeof(P));

    for(int i=0; i<n; i++){
        P[i][0] = T[i];
    }
    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; i<n; i++){
            if(P[i][j-1]!=-1){
               P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}
int lca_query(int u,int v, int n){
    if(L[u]<L[v])swap(u,v);
    int log = (int)log2(n);

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && L[u]-(1<<i) >= L[v]){
            u = P[u][i];
        }
    }

    if(u==v)return u;

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && P[u][i] != P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }

    return T[u];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++){
        int n; cin>>n;
        for(int i=1; i<n; i++){
            int u,v; cin>>u>>v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bitset<10005>b;
        dfs(0,-1,0,b);
        lca_init(n);
        cout<<"Case "<<ks<<": "<<endl;
        int q; cin>>q;
        while(q--){
            int k; cin>>k;
            bitset<10005>ans;
            ans.set();
            while(k--){
                int u,v; cin>>u>>v;
                u--, v--;
                bitset<10005> temp = (node[u] | node[v]);
                int lca = lca_query(u,v,n);
                if(T[lca]!=-1){
                    temp = (temp^node[T[lca]]);
                    ans = (ans & temp);
                }else{
                    ans = (ans & temp);
                }
            }

            int ret = ans.count();
            cout<<ret<<endl;
        }

        for(int i=0; i<=n; i++)adj[i].clear();
        for(int i=0; i<=n; i++)node[i].reset();
    }
    return 0;
}
