#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define MP make_pair
struct query{
    char c;
    int id,i;
    ll x;
}qr[500005];
bool cmp(query u,query v){
    return u.i>v.i;
}
vector<ll>ans;
vector< pair<int,int> > vv;
multiset<ll>ss;
ll a[500005],last[500005],prvv[500005],weight[500005];
int parent[500005],rnk[500005];
bool mark[500005];

void make_set(int v){
    parent[v] = v;
    rnk[v] = 0;
    weight[v] = last[v];
    ss.insert(weight[v]);
}
int find_set(int v){
    if(v==parent[v])return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int u,int v){
    int pu = find_set(u);
    int pv = find_set(v);
    if(pu!=pv){
        if(rnk[pu]<rnk[pv])swap(pu,pv);
        parent[pv] = pu;
        if(rnk[pu]==rnk[pv])rnk[pu]++;

        ss.erase(ss.find(weight[pu]));
        ss.erase(ss.find(weight[pv]));
        weight[pu] += weight[pv];
        ss.insert(weight[pu]);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,m,q; cin>>n>>m>>q;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=n; i++)last[i]=a[i];
    vv.resize(m+3);
    for(int i=1; i<=m; i++){
        int u,v; cin>>u>>v;
        if(u>v)swap(u,v);
        vv[i] = MP(u,v);
    }
    for(int i=1; i<=q; i++){
        cin>>qr[i].c;
        if(qr[i].c=='P'){
            cin>>qr[i].id>>qr[i].x;
            qr[i].i = i;
            prvv[i] = last[qr[i].id];
            last[qr[i].id] = qr[i].x;
        }
        else{
            cin>>qr[i].id;
            qr[i].i = i;
            mark[qr[i].id]=true;
        }
    }

    for(int i=1; i<=n; i++)make_set(i);
    for(int i=1; i<=m; i++){
        if(!mark[i]){
            union_set(vv[i].first,vv[i].second);
        }
    }

    sort(qr+1,qr+q+1,cmp);

    for(int i=1; i<=q; i++)
    {
        ans.PB(*ss.rbegin());

        if(qr[i].c=='P'){
            int u = qr[i].id;
            int pu = find_set(u);
            ss.erase(ss.find(weight[pu]));
            weight[pu]-=last[u];
            weight[pu]+=prvv[q-i+1];
            last[u] = prvv[q-i+1];
            ss.insert(weight[pu]);
        }
        else{
            union_set(vv[qr[i].id].first,vv[qr[i].id].second);
        }
    }

    reverse(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)cout<<ans[i]<<endl;

    return 0;
}

