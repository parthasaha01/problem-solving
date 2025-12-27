#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000002
ll mod = 10000007LL;
ll vis[mx+5],ans[mx+5],cnt[78500+5],tree[4*78500];
int sz;
vector< pair<int,int> >factor[mx+5];
map<int,int>mp;
void sieve(){
    for(int i=2; i<=mx; i++)vis[i] = 1;
    for(int i=2; i<=mx; i++){
        if(vis[i]==1){
            mp[i] = ++sz;
            factor[i].push_back(make_pair(i,1));
            for(int j=i+i; j<=mx; j+=i){
                vis[j] = 0;
                int k = 0;
                int temp = j;
                while(temp%i==0){
                    ++k;
                    temp /= i;
                }
                factor[j].push_back(make_pair(i,k));
            }
        }
    }
}
void update(int node,int b,int e,int x,ll v){
    if(b==x && e==x){
        tree[node] = v;
        return;
    }
    int lson=node*2, rson=lson+1, m=(b+e)/2;
    if(x<=m)update(lson,b,m,x,v);
    else update(rson,m+1,e,x,v);
    tree[node] = (tree[lson]*tree[rson])%mod;
}
void precalc(){
    for(int i=1; i<=sz; i++){
        update(1,1,sz,i,1LL);
    }
    ans[1] = 1;
    for(int i=2; i<=mx; i++){
        for(int j=0; j<factor[i].size(); j++){
            int pr = factor[i][j].first;
            int k  = factor[i][j].second;
            int idx = mp[pr];
            cnt[idx] += k;
            ll v = (((cnt[idx]+1)*(cnt[idx]+2))/2)%mod;
            update(1,1,sz,idx,v);
        }
        ans[i] = tree[1];
    }
}
int main(){
    sieve();
    precalc();
    int n;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        printf("%lld\n",ans[n]);
    }
    return 0;
}



