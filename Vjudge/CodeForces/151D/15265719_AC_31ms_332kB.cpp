#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007LL
vector<int>ed[2005];
int parent[2005],szz[2005];
void make_set(int v){
    parent[v] = v;
    szz[v] = 1;
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
    }
}
ll solve(ll n,ll m,ll k)
{
    for(int i=1; i<=n; i++)make_set(i);
    for(int i=1; i<=(n-k+1); i++){
        for(int u=i,v=i+k-1; u<=v; u++,v--){
            union_set(u,v);
        }
    }
    int component = 0;
    for(int i=1; i<=n; i++){
        if(i==find_set(i))component++;
    }
    ll ans = 1LL;
    for(int i=1; i<=component; i++){
        ans = (ans*m)%MOD;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n,m,k; cin>>n>>m>>k;
    cout<<solve(n,m,k)<<endl;
    return 0;
}

