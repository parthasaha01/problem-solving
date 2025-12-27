#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define MP make_pair
#define INF 10000000000LL
vector< pair<int,int> > edge;
ll a[500005],weight[500005];
int parent[500005],szz[500005];
bool mark[100005];
void make_set(int v){
    parent[v] = v;
    szz[v] = 1;
    weight[v] = a[v];
}
int find_set(int v){
    if(v==parent[v])return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int u,int v){
    int pu = find_set(u);
    int pv = find_set(v);
    if(pu!=pv){
        if(szz[pu]<szz[pv])swap(pu,pv);
        parent[pv] = pu;
        szz[pu] += szz[pv];
        weight[pu]  = min(weight[pu],weight[pv]);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=1; i<=m; i++){
        int u,v; cin>>u>>v;
        if(u>v)swap(u,v);
        edge.PB(MP(u,v));
    }
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]<0)a[i]=INF+5;
    }

    for(int i=1; i<=n; i++)make_set(i);

    for(int i=0; i<edge.size(); i++){
        union_set(edge[i].first,edge[i].second);
    }

    ll minn = 1000000000000000LL;
    int minp = 0;
    for(int i=1; i<=n; i++){
        int p = find_set(i);
        if(weight[p]<minn){
            minn = weight[p];
            minp = p;
        }
    }

    ll ans = 0;
    mark[minp] = true;
    for(int i=1; i<=n; i++){
        int p = find_set(i);
        if(!mark[p]){
            ans += (minn+weight[p]);
            mark[p]=true;
        }
    }

    if(ans>=INF)ans = -1;
    cout<<ans<<endl;

    return 0;
}

