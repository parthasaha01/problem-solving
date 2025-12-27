#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<pii>a;
vector<int>tree;
vector<int>ans;
bool cmp(pii x, pii y){
    return x.first < y.first;
}
void update(int node, int b, int e, int x, int v){
    if(b==x && e==x){
        tree[node] = v; return;
    }
    int lson = (node<<1), rson = lson+1, m = (b+e)/2;
    if(x<=m) update(lson,b,m,x,v);
    else update(rson,m+1,e,x,v);
    tree[node] = tree[lson] + tree[rson];
}
int query(int node, int b, int e, int x){
    if(b==e) return b;
    int lson = (node<<1), rson = lson+1, m = (b+e)/2;
    if(tree[lson]>=x) return query(lson,b,m,x);
    else return query(rson,m+1,e,x-tree[lson]);
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int n; scanf("%d",&n);

        a.clear(); a.resize(n+1);
        tree.clear(); tree.resize(4*n);
        ans.clear(); ans.resize(n+1);

        for(int i=1; i<=n; i++){
            int hi,ti; scanf("%d%d",&hi,&ti);
            a[i]=make_pair(hi,ti);
        }

        sort(a.begin(), a.end(), cmp);

        for(int i=1; i<=n; i++){
            update(1,1,n,i,1);
        }

        int possible = 1;
        for(int i=1; i<=n; i++){
            int hi = a[i].first, ti = a[i].second;
            if(tree[1]<ti+1){
                possible = 0;
                break;
            }
            int pos = query(1,1,n,ti+1);
            ans[pos] = hi;
            update(1,1,n,pos,0);
        }

        if(possible==1){
            printf("Case %d:",ks);
            for(int i=1; i<=n; i++){
                printf(" %d",ans[i]);
            }
            printf("\n");
        }else{
            printf("Case %d: No ordering possible!\n",ks);
        }
    }
    return 0;
}
