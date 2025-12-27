#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MAXP 1000000
#define MAXN 1000000
using namespace std;
pair<ll,ll>tree[4*MAXP];
vector<int>add[MAXN+5], del[MAXN+5];
struct Data{
    int l,r,c,p;
}tariff[200005];
bool cmp(Data x, Data y){
    return x.p<y.p;
}
void update(int node,int b,int e,int p,int c,int f){
    if(b==p&&e==p){
        tree[node].first  += c*f;
        tree[node].second += (1LL)*b*c*f;
        return;
    }
    int lson = (node*2), rson = lson+1, m=(b+e)/2;
    if(p<=m) update(lson, b, m, p, c, f);
    else update(rson, m+1, e, p, c, f);
    tree[node].first  = tree[lson].first  + tree[rson].first;
    tree[node].second = tree[lson].second + tree[rson].second;
}
ll query(int node,int b,int e,int k){
    if(tree[node].first<=k)return tree[node].second;
    if(k==0) return 0;
    if(b==e) return (1LL)*b*k;

    int lson = (node*2), rson = lson+1, m=(b+e)/2;
    if(tree[lson].first>=k) return query(lson, b, m, k);
    else return tree[lson].second + query(rson, m+1, e, k-tree[lson].first);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k,m; cin>>n>>k>>m;
    for(int i=0; i<m; i++){
        int l,r,c,p; cin>>l>>r>>c>>p;
        tariff[i].l = l, tariff[i].r = r;
        tariff[i].c = c, tariff[i].p = p;
    }
    //sort(tariff, tariff+m, cmp);
    for(int i=0; i<m; i++){
        add[tariff[i].l].push_back(i);
        del[tariff[i].r+1].push_back(i);
    }
    memset(tree,0,sizeof(tree));

    ll ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<(int)add[i].size(); j++){
            int p = tariff[add[i][j]].p;
            int c = tariff[add[i][j]].c;
            update(1, 1, MAXP, p, c, +1);
        }
        for(int j=0; j<(int)del[i].size(); j++){
            int p = tariff[del[i][j]].p;
            int c = tariff[del[i][j]].c;
            update(1, 1, MAXP, p, c, -1);
        }
        ll ret = query(1,1,MAXP,k);
        ans += ret;
    }
    cout << ans << endl;
    return 0;
}
