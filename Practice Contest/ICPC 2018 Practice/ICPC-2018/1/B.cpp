#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 500005
int n,a[500005],tree[4*mx];
vector<int>vv;
map<int,int>mp;
void update(int nd,int b,int e,int x){
    if(b==e&&b==x){
        tree[nd] = 1;
        return;
    }
    int l=2*nd, r = l+1, m = (b+e)/2;
    if(x<=m)update(l,b,m,x);
    else update(r,m+1,e,x);
    tree[nd] = tree[l] + tree[r];
}
int query(int nd,int b,int e,int x,int y){
    if(b>y || e<x)return 0;
    if(b>=x&&e<=y)return tree[nd];
    int l=2*nd, r = l+1, m = (b+e)/2;
    return query(l,b,m,x,y) + query(r,m+1,e,x,y);
}
int main(){
    while(scanf("%d",&n)){
        if(n==0)break;

        vv.clear();
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            vv.push_back(a[i]);
        }

        sort(vv.begin(), vv.end());
        mp.clear();
        for(int i=0,k=0; i<n; i++){
            mp[vv[i]] = ++k;
        }

        memset(tree,0,sizeof(tree));
        ll ans = 0;
        for(int i=0; i<n; i++){
            int cnt = query(1,1,n,mp[a[i]]+1,n);
            ans += cnt;
            update(1,1,n,mp[a[i]]);
        }

        printf("%lld\n",ans);
    }

    return 0;
}
