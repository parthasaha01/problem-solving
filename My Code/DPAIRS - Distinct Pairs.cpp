#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
map<int,int>mp;
vector<pii>a,b,ans;
bool cmp(pii x, pii y){
    return x.first < y.first;
}
void solve(int n,int m){
    mp.clear();
    int na = a.size(), nb = b.size();
    for(int i=0,k=na-1; i<=k; i++,k--){
        for(int j=0; j<b.size(); j++){
            int sum = a[i].first + b[j].first;
            if(mp.find(sum)==mp.end()){
                ans.push_back(make_pair(a[i].second, b[j].second));
                mp[sum] = 1;
                if((int)ans.size()==n+m-1)return;
            }
        }
        if(i==k)continue;
        for(int j=0; j<b.size(); j++){
            int sum = a[k].first + b[j].first;
            if(mp.find(sum)==mp.end()){
                ans.push_back(make_pair(a[k].second, b[j].second));
                mp[sum] = 1;
                if((int)ans.size()==n+m-1)return;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    mp.clear();
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(mp.find(x)==mp.end()){
            a.push_back(make_pair(x,i));
            mp[x] = 1;
        }
    }
    mp.clear();
    for(int i=0; i<m; i++){
        int x; cin>>x;
        if(mp.find(x)==mp.end()){
            b.push_back(make_pair(x,i));
            mp[x] = 1;
        }
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    solve(n,m);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return 0;
}
