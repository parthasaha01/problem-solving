#include<bits/stdc++.h>
using namespace std;
const int N  = 10005;
const int RT = 100;
int n,k,a[N],last[N],lft[N],rgt[N],cnt[N],ans[100005];
multiset<int>gap[N];
map<int,int>res;
struct query{
    int l,r,id;
};
bool cmp(query A, query B){
    if(A.l / RT != B.l / RT) return A.l < B.l;
    return ((A.l / RT) & 1) ? A.r > B.r : A.r < B.r;
}
void Add(int x,int d){
    int v = a[x];
    cnt[v]++;

    if( gap[v].size() && (*gap[v].begin())<=k ){
        int sz = (int)gap[v].size();
        res[sz]--;
        if(res[sz]==0) res.erase(sz);
    }

    if(cnt[v]>=2) gap[v].insert(d);

    if( gap[v].size() && (*gap[v].begin())<=k ){
        int sz = gap[v].size();
        res[sz]++;
    }
}
void Remove(int x,int d){
    int v = a[x];
    cnt[v]--;

    if( gap[v].size() && (*gap[v].begin())<=k ){
        int sz = gap[v].size();
        res[sz]--;
        if(res[sz]==0) res.erase(sz);
    }

    if(cnt[v]>=1){
        auto it = gap[v].find(d);
        if(it != gap[v].end()){
            gap[v].erase(it);
        }
    }

    if( gap[v].size() && (*gap[v].begin())<=k ){
        int sz = gap[v].size();
        res[sz]++;
    }
}
int main(){
    int tt;scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        for(int i=0; i<=n; i++)last[i]=0;
        for(int i=1; i<=n; i++){
            lft[i] = i-last[a[i]];
            last[a[i]] = i;
        }

        for(int i=0; i<=n; i++)last[i]=n+1;
        for(int i=n; i>=1; i--){
            rgt[i] = last[a[i]]-i;
            last[a[i]] = i;
        }

        int q; scanf("%d",&q);
        vector<query>queries;
        for(int i=1; i<=q; i++){
            int l,r; scanf("%d%d",&l,&r);
            if(l>r)swap(l,r);
            queries.push_back({l,r,i});
        }
        sort(queries.begin(), queries.end(),cmp);

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

        for(int i=1; i<=q; i++) printf("%d\n",ans[i]);
    }
    return 0;
}
