#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
indexed_multiset;

indexed_multiset ss[100005];
int parent[100005];

int Find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
void Make(int a, int t){
    int u = Find(a);
    ss[u].insert(t);
}
void Union(int a, int b) {
    int u = Find(a);
    int v = Find(b);
    if(u != v) {
        if(ss[u].size() > ss[v].size()) {
            for(auto x : ss[v]){
                if(x>0 && x<1000000001){
                    ss[u].insert(x);
                }
            }
            parent[v] = u;
            ss[v].clear();
        }else{
            for(auto x : ss[u]){
                if(x>0 && x<1000000001){
                    ss[v].insert(x);
                }
            }
            parent[u] = v;
            ss[u].clear();
        }
    }
}
int Query(int a, int l, int r){
    int u = Find(a);

    auto lb = ss[u].upper_bound(l);
    auto ub = ss[u].lower_bound(r);

    int lp = ss[u].order_of_key(*lb);
    int up = ss[u].order_of_key(*ub);
    up--;

    return up-lp+1;
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++) {
        printf("Case %d:\n",ks);
        int n,q; scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
            ss[i].clear();
            ss[i].insert(0);
            ss[i].insert(1000000001);
        }
        while(q--){
            int type; scanf("%d",&type);
            if(type==0) {
                int u,v; scanf("%d%d",&u,&v);
                Union(u,v);
            }else if(type==1) {
                int u,t; scanf("%d%d",&u,&t);
                Make(u,t);
            }else{
                int u,l,r; scanf("%d%d%d",&u,&l,&r);
                if(l>r)swap(l,r);
                int ans = Query(u,l,r);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

