#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n, q, aa[mx], bb[mx], pr;
vector<int>vec[4*mx];
struct data{
    int sum,lazy;
}tree[4*mx];
void init(int nd,int b,int e){
    vec[nd].clear();
    if(b==e){
        if(aa[b]==bb[b])tree[nd].sum=1;
        else tree[nd].sum=0;
        tree[nd].lazy = -1;
        vec[nd].push_back(bb[b]);
        return;
    }
    int l = nd<<1, r = l+1, m = (b+e)>>1;
    init(l,b,m);
    init(r,m+1,e);
    tree[nd].sum = tree[l].sum + tree[r].sum;
    tree[nd].lazy = -1;
    merge(vec[l].begin(), vec[l].end(), vec[r].begin(), vec[r].end(), back_inserter(vec[nd]));
}

void pushDown(int nd,int b,int e){
    if(tree[nd].lazy != -1){
        if(b != e){
            int l = nd<<1, r = l+1, m = (b+e)>>1;
            tree[l].lazy = tree[nd].lazy;
            tree[r].lazy = tree[nd].lazy;
        }
        int x = upper_bound(vec[nd].begin(), vec[nd].end(), tree[nd].lazy)-vec[nd].begin();
        int y = lower_bound(vec[nd].begin(), vec[nd].end(), tree[nd].lazy)-vec[nd].begin();
        tree[nd].sum = x-y;
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
        for(int i=1; i<=n; i++){
            scanf("%d",&aa[i]);
        }
        for(int i=1; i<=n; i++){
            scanf("%d",&bb[i]);
        }

        init(1,1,n);

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

