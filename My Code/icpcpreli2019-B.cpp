#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
orderset < pair<int,int> > ss[100005];

int parent[100005];

int Find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
void Make(int a, int t, int c){
    int u = Find(a);
    ss[u].insert(make_pair(t,c));
}
void Union(int a, int b) {
    int u = Find(a);
    int v = Find(b);
    if(u != v) {
        if(ss[u].size() > ss[v].size()) {
            for(auto x : ss[v]){
                ss[u].insert(x);
            }
            parent[v] = u;
            ss[v].clear();
        }else{
            for(auto x : ss[u]){
                ss[v].insert(x);
            }
            parent[u] = v;
            ss[u].clear();
        }
    }
}
int Query(int a, int l, int r){
    int u = Find(a);

    int lp = ss[u].order_of_key(make_pair(l,-1));
    int up = ss[u].order_of_key(make_pair(r,300001));

    return up-lp;
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++) {
        printf("Case %d:\n",ks);
        int n,q; scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
            ss[i].clear();
        }
        for(int i=1; i<=q; i++){
            int type; scanf("%d",&type);
            if(type==0) {
                int u,v; scanf("%d%d",&u,&v);
                Union(u,v);
            }else if(type==1) {
                int u,t; scanf("%d%d",&u,&t);
                Make(u,t,i);
            }else{
                int u,l,r; scanf("%d%d%d",&u,&l,&r);
                int ans = Query(u,l,r);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}


