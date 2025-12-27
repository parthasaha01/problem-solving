#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
struct road{
    int v,w,i;
};
int n,m;
vector<road>adj[100005];
map<pii, int>mp;
struct dt{
    int u,v,w,id;
}st[100005];
bool cmp(dt x, dt y){
    return x.w < y.w;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int u,v,w; cin>>u>>v>>w;
        st[i].u = u, st[i].v = v, st[i].w = w, st[i].id = i;
    }

    sort(st+1,st+m+1,cmp);

    for(int i=1; i<=m; i++){
        int u = st[i].u;
        int v = st[i].v;
        int w = st[i].w;
        int id = st[i].id;
        pii uv = make_pair(u,v);
        if(mp.find(uv)==mp.end()){
            adj[u].push_back({v,w,id});
        }
        mp[uv] = 1;
    }


    return 0;
}
