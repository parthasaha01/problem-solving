#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define LL long long
LL a[MAXN], c[MAXN];
vector<LL>tree[4*MAXN];
void Merge(int nd, int lf, int rg){
    int i=0, j=0;
    while(i<tree[lf].size() && j<tree[rg].size()){
        if(tree[lf][i] < tree[rg][j]){
            tree[nd].push_back(tree[lf][i++]);
        }else{
            tree[nd].push_back(tree[rg][j++]);
        }
    }
    while(i<tree[lf].size()) tree[nd].push_back(tree[lf][i++]);
    while(j<tree[rg].size()) tree[nd].push_back(tree[rg][j++]);
}
void build(int nd, int b,int e){
    if(b==e){ tree[nd].push_back(c[b]); return;}
    int m = (b+e)/2;
    build(2*nd,b,m);
    build(2*nd+1,m+1,e);
    Merge(nd,2*nd,2*nd+1);
}
int BinarySearch(int nd,LL v){
    int lo = 0, hi = tree[nd].size()-1;
    int cnt = 0;
    while(lo<=hi){
        int md = (lo+hi)/2;
        if(tree[nd][md]<=v){
            cnt = md+1;
            lo = md+1;
        }else{
            hi = md-1;
        }
    }
    return (int)tree[nd].size()-cnt;
}
int query(int nd,int b,int e,int x,int y,LL v){
    if(x>y)return 0;
    if(b>y || e<x)return 0;
    if(b>=x && e<=y) return BinarySearch(nd,v);
    int m = (b+e)/2;
    return query(2*nd,b,m,x,y,v) + query(2*nd+1,m+1,e,x,y,v);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    LL n,t; cin>>n>>t;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        c[i] = c[i-1] + a[i];
    }

    build(1,1,n);

    LL ans = 0;
    for(int i=1; i<=n; i++){
        ans += query(1,1,n,1,i-1,c[i]-t);
        if(c[i]<t)ans++;
    }
    cout << ans << endl;
    return 0;
}

