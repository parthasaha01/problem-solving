#include<bits/stdc++.h>
using namespace std;
const int N  = 10005;
const int RT = 100;
int n,k,a[N],last[N],lft[N],rgt[N],cnt[N],ans[100005];
unordered_multiset<int>gap[N];
map<int,int>res;
struct query {
    int l, r, id;
    bool operator < (query q) {
        return (l/RT != q.l/RT) ? (l/RT < q.l/RT) : (r<q.r);
    }
};
void Add(int x,int d){
    int v = a[x];
    cnt[v]++;

    if( (int)gap[v].size()>0 && (*gap[v].begin())<=k ){
        int sz = (int)gap[v].size();
        res[sz]--;
        if(res[sz]==0) res.erase(sz);
    }

    if(cnt[v]>=2) gap[v].insert(d);

    if( (int)gap[v].size()>0 && (*gap[v].begin())<=k ){
        int sz = (int)gap[v].size();
        res[sz]++;
    }
}
void Remove(int x,int d){
    int v = a[x];
    cnt[v]--;

    if( (int)gap[v].size()>0 && (*gap[v].begin())<=k ){
        int sz = (int)gap[v].size();
        res[sz]--;
        if(res[sz]==0) res.erase(sz);
    }

    if(cnt[v]>=1){
        if(gap[v].find(d) != gap[v].end()){
            auto it = gap[v].find(d);
            gap[v].erase(it);
        }
    }

    if( (int)gap[v].size()>0 && (*gap[v].begin())<=k ){
        int sz = (int)gap[v].size();
        res[sz]++;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt;cin>>tt;
    for(int ks=1; ks<=tt; ks++){
        cin>>n>>k;
        for(int i=1; i<=n; i++)cin>>a[i];

        for(int i=0; i<N; i++)last[i]=0;
        for(int i=1; i<=n; i++){
            lft[i] = i-last[a[i]];
            last[a[i]] = i;
        }

        for(int i=0; i<N; i++)last[i]=n+1;
        for(int i=n; i>=1; i--){
            rgt[i] = last[a[i]]-i;
            last[a[i]] = i;
        }

        int q; cin>>q;
        vector<query>queries;
        for(int i=1; i<=q; i++){
            int l,r; cin>>l>>r;
            if(l>r)swap(l,r);
            queries.push_back({l,r,i});
        }
        sort(queries.begin(), queries.end());

        for(int i=0; i<=n; i++) cnt[i] = 0;
        for (int i=0; i<=n; i++) gap[i].clear();
        res.clear();

        int l=1,r=0;
        for(query q : queries){
            while(r<q.r) ++r, Add(r,lft[r]);
            while(r>q.r) Remove(r,lft[r]), r--;
            while(l>q.l) --l, Add(l,rgt[l]);
            while(l<q.l) Remove(l,rgt[l]), l++;

            if((int)res.size()==0) ans[q.id] = 0;
            else ans[q.id] = res.rbegin()->second;
        }

        for(int i=1; i<=q; i++) cout<<ans[i]<<endl;
    }
    return 0;
}
