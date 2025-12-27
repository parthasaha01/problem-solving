#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int parent[MAXN],rnk[MAXN];
map<int,int>mp;
void make_set(int v)
{
    parent[v] = v;
    rnk[v] = 0;
}
int find_set(int v)
{
    if(parent[v]==v)return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int u,int v)
{
    int pu = find_set(u);
    int pv = find_set(v);
    if(pu==pv)return;
    if(rnk[pu]<rnk[pv])swap(pu,pv);
    parent[pv] = pu;
    if(rnk[pu]==rnk[pv])rnk[pu]++;
}
int main()
{
    int n,m,k; scanf("%d%d",&n,&m);
    k = 0;
    for(int i=1; i<=m; i++){
        int u,v; scanf("%d%d",&u,&v);
        if(mp.find(u)==mp.end()){
            mp[u] = ++k;
            make_set(mp[u]);
        }
        if(mp.find(v)==mp.end()){
            mp[v] = ++k;
            make_set(mp[v]);
        }
        union_sets(mp[u],mp[v]);
    }
    int ans = 0;
    for(int i=1; i<=k; i++){
        if(parent[i]==i)ans++;
    }
    ans += (n-k);
    printf("%d\n",ans);

    return 0;
}
