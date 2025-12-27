#include<bits/stdc++.h>
using namespace std;
const int N  = 10005;
const int RT = 100;
int n,k,a[N],last[N],lft[N],rgt[N],ans[100005];
int validGap[N],cnt[N],strength[N];
bool active[N];
set<int>res;
struct query{
    int l,r,id;
    bool operator < (const query& q) const {
        if(l / RT != q.l / RT) return l < q.l;
        return ((l / RT) & 1) ? r > q.r : r < q.r;
    }
};
void Add(int idx){
    int v = a[idx];
    if(active[v]){
        strength[cnt[v]]--;
        if(strength[cnt[v]]==0) res.erase(cnt[v]);

        cnt[v]++;

        strength[cnt[v]]++;
        if(strength[cnt[v]]==1) res.insert(cnt[v]);
    }else{
        cnt[v]++;
        if(validGap[v]>0){
            active[v] = true;
            strength[cnt[v]]++;
            if(strength[cnt[v]]==1) res.insert(cnt[v]);
        }
    }
}
void Remove(int idx){
    int v = a[idx];
    if(active[v]){
        strength[cnt[v]]--;
        if(strength[cnt[v]]==0) res.erase(cnt[v]);

        cnt[v]--;

        if(validGap[v]>0){
            strength[cnt[v]]++;
            if(strength[cnt[v]]==1) res.insert(cnt[v]);
        }else{
            active[v] = false;
        }
    }else{
        cnt[v]--;
    }
}
int main(){
    int tt;scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        for(int i=0; i<=n; i++)last[i]=0;
        for(int i=1; i<=n; i++){
            lft[i] = last[a[i]];
            last[a[i]] = i;
        }

        for(int i=0; i<=n; i++)last[i]=n+1;
        for(int i=n; i>=1; i--){
            rgt[i] = last[a[i]];
            last[a[i]] = i;
        }

        int q; scanf("%d",&q);
        //RT = sqrt((n*n)/q);
        vector<query>queries;
        for(int i=1; i<=q; i++){
            int l,r; scanf("%d%d",&l,&r);
            if(l>r)swap(l,r);
            queries.push_back({l,r,i});
        }
        sort(queries.begin(), queries.end());

        res.clear();
        for (int i=0; i<=n; i++){
            cnt[i] = 0;
            active[i] = false;
            validGap[i] = 0;
            strength[i] = 0;
        }

        int l=1,r=0;
        for(query q : queries){
            while(r<q.r) {
                ++r;
                if(lft[r]>=l && r-lft[r]<=k) validGap[a[r]]++;
                Add(r);
            }
            while(l>q.l) {
                --l;
                if(rgt[l]<=r && rgt[l]-l<=k) validGap[a[l]]++;
                Add(l);
            }
            while(r>q.r) {
                if(lft[r]>=l && r-lft[r]<=k) validGap[a[r]]--;
                Remove(r);
                r--;
            }
            while(l<q.l) {
                if(rgt[l]<=r && rgt[l]-l<=k) validGap[a[l]]--;
                Remove(l);
                l++;
            }

            if((int)res.size()==0) ans[q.id] = 0;
            else ans[q.id] = strength[*res.rbegin()];
        }

        for(int i=1; i<=q; i++) printf("%d\n",ans[i]);
    }
    return 0;
}
