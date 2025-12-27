#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n,ans[MAXN],parent[MAXN],szz[MAXN];
bool mark[MAXN];
struct dt{
    int v,i;
}a[MAXN];
bool cmp(dt x, dt y){
    if(x.v==y.v)return x.i<y.i;
    return x.v>y.v;
}
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
void solve()
{
    memset(ans,-1,sizeof(ans));
    memset(mark,false,sizeof(mark));
    for(int i=1; i<=n; i++)make_set(i);
    int idx = 0;

    for(int i=1; i<=n; i++){
        int id = a[i].i;
        if(mark[id-1]){
            union_set(id,id-1);
            mark[id-1] = true;
        }
        if(mark[id+1]){
            union_set(id,id+1);
            mark[id+1] = true;
        }
        mark[id] = true;
        int par = find_set(id);
        for(int k=idx+1; k<=szz[par]; k++){
            ans[k] = a[i].v;
            idx++;
        }
    }

    for(int i=1; i<=n; i++){
        if(i<n)cout<<ans[i]<<" ";
        else cout<<ans[i]<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i].v;
        a[i].i = i;
    }
    sort(a+1,a+n+1,cmp);
    solve();
    return 0;
}

