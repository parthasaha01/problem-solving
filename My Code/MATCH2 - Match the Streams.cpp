#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n, q, aa[mx], bb[mx], pr;
vector<int>vec[mx];
unordered_map<int,int>mp;
unordered_set<int>ss;
struct data{
    int sum,lazy;
}tree[4*mx];

void init(){
    ss.clear(); mp.clear();
    for(int i=1; i<=n; i++)vec[i].clear();

    for(int i=1; i<=n; i++) ss.insert(bb[i]);
    int k = 0;
    for(auto it=ss.begin(); it!=ss.end(); it++){
        mp[*it] = ++k;
    }
    for(int i=1; i<=n; i++){

        vec[mp[bb[i]]].push_back(i);
    }
}

int query(int x,int y,int v){
    if(mp.find(v)==mp.end())return 0;
    int cnt1 = lower_bound(vec[mp[v]].begin(), vec[mp[v]].end(), y+1)-vec[mp[v]].begin();
    int cnt2 = lower_bound(vec[mp[v]].begin(), vec[mp[v]].end(), x)-vec[mp[v]].begin();
    return cnt1-cnt2;
}
void build(int nd,int b,int e){
    if(b==e){
        if(aa[b]==bb[b])tree[nd].sum=1;
        else tree[nd].sum=0;
        tree[nd].lazy = -1;
        return;
    }
    int l = 2*nd, r = (2*nd+1), m = (b+e)/2;
    build(l,b,m);
    build(r,m+1,e);
    tree[nd].sum = tree[l].sum + tree[r].sum;
    tree[nd].lazy = -1;
}
void pushDown(int nd,int b,int e){
    if(tree[nd].lazy != -1){
        if(b != e){
            int l = 2*nd, r = (2*nd+1), m = (b+e)/2;
            tree[l].lazy = tree[nd].lazy;
            tree[r].lazy = tree[nd].lazy;
            tree[l].sum = query(b,m,tree[l].lazy);
            tree[r].sum = query(m+1,e,tree[r].lazy);
        }
        tree[nd].lazy = -1;
    }
}
void update(int nd,int b,int e,int x,int y,int v){
    pushDown(nd,b,e);
    if(b>y || e<x)return;
    if(b>=x && e<=y){
        tree[nd].sum = query(b,e,v);
        tree[nd].lazy = v;
        return;
    }
    int l = 2*nd, r = (2*nd+1), m = (b+e)/2;
    update(l,b,m,x,y,v);
    update(r,m+1,e,x,y,v);
    tree[nd].sum = tree[l].sum + tree[r].sum;
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++) scanf("%d",&aa[i]);
        for(int i=1; i<=n; i++) scanf("%d",&bb[i]);

        init();

        build(1,1,n);

        while(q--){
            pr = tree[1].sum;
            int x,y,v; scanf("%d%d%d",&x,&y,&v);
            x = pr^x; y = pr^y; v = pr^v;
            update(1,1,n,x,y,v);
            int ans = tree[1].sum;
            printf("%d\n",ans);
        }
    }
    return 0;
}
