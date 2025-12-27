#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

int parent[100005];

typedef tree<
pair<int,int>,
null_type,
less< pair<int, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
indexed_multiset;

indexed_multiset ss[100005];

void Print(int a, int u){
    printf("a=%d u=%d:\n",a,u);
    for(auto x : ss[u]){
        printf("(%d %d), ",x.first, x.second);
    }
    printf("\n");
}
int Find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
void Make(int a, int t, int c){
    int u = Find(a);
    ss[u].insert(make_pair(t,c));
    //Print(a,u);
}
void Union(int a, int b) {
    int u = Find(a);
    int v = Find(b);
    if(u != v) {
        if(ss[u].size() > ss[v].size()) {
            for(auto x : ss[v]){
                //if(x!=make_pair(0,0) && x != make_pair(1000000001,0)){
                    ss[u].insert(x);
                //}
            }
            parent[v] = u;
            ss[v].clear();
            //Print(a,u);
        }else{
            for(auto x : ss[u]){
                //if(x!=make_pair(0,0) && x != make_pair(1000000001,0)){
                    ss[v].insert(x);
                //}
            }
            parent[u] = v;
            ss[u].clear();
            //rint(b,v);
        }
    }
}
int Query(int a, int l, int r){
    int u = Find(a);

    //ss[u].insert(0);
    //ss[u].insert(1000000001);

    //Print(a,u);

    //auto lb = ss[u].lower_bound(make_pair(l,0));
    //auto ub = ss[u].upper_bound(make_pair(r,300005));
    //ub--;
    //if((*ub)>r)ub--;

    //printf("val: (%d %d), (%d %d)\n",(*lb).first, (*lb).second, (*ub).first, (*ub).second);

    int lp = ss[u].order_of_key(make_pair(l,-1));
    int up = ss[u].order_of_key(make_pair(r,300001));
    //up--;

    //printf("pos: %d %d\n",lp, up);
    //ss[u].erase(0);
    //ss[u].erase(1000000001);

    return up-lp;
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++) {
        printf("Case %d:\n",ks);
        int n,q; scanf("%d%d",&n,&q);
        int c = 0;
        for(int i=1; i<=n; i++) {
            parent[i] = i;
            ss[i].clear();
            //ss[i].insert(make_pair(0,0));
            //ss[i].insert(make_pair(1000000001,0));
        }
        while(q--){
            int type; scanf("%d",&type);
            if(type==0) {
                int u,v; scanf("%d%d",&u,&v);
                Union(u,v);
            }else if(type==1) {
                int u,t; scanf("%d%d",&u,&t);
                Make(u,t,c++);
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

