#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n, q, aa[mx], bb[mx], pr;
vector<int>vec[mx];
unordered_map<int,int>mp;
struct data{
    int sum,lazy;
}tree[4*mx];

void init(){
    mp.clear();
    for(int i=1; i<=n; i++)vec[i].clear();
    for(int i=1, k=0; i<=n; i++){
        if(mp.find(bb[i])==mp.end())mp[bb[i]] = ++k;
        vec[mp[bb[i]]].push_back(i);
    }
}
void build(int nd,int b,int e){
    if(b==e){
        if(aa[b]==bb[b])tree[nd].sum=1;
        else tree[nd].sum=0;
        tree[nd].lazy = -1;
        return;
    }
    int l = nd<<1, r = l+1, m = (b+e)>>1;
    build(l,b,m);
    build(r,m+1,e);
    tree[nd].sum = tree[l].sum + tree[r].sum;
    tree[nd].lazy = -1;
}
void pushDown(int nd,int b,int e){
    if(tree[nd].lazy != -1){
        int v = tree[nd].lazy;
        if(b != e){
            int l = 2*nd, r = (2*nd+1), m = (b+e)/2;
            tree[l].lazy = tree[nd].lazy;
            tree[r].lazy = tree[nd].lazy;
        }
        int cnt1 = lower_bound(vec[mp[v]].begin(), vec[mp[v]].end(), e+1)-vec[mp[v]].begin();
        int cnt2 = lower_bound(vec[mp[v]].begin(), vec[mp[v]].end(), b)-vec[mp[v]].begin();
        tree[nd].sum = cnt1-cnt2;
        tree[nd].lazy = -1;
    }
}
void update(int nd,int b,int e,int x,int y,int v){
    pushDown(nd,b,e);
    if(b>y || e<x)return;
    if(b>=x && e<=y){
        tree[nd].lazy = v;
        pushDown(nd,b,e);
        return;
    }
    int l = nd<<1, r = l+1, m = (b+e)>>1;
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

