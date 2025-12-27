#include<bits/stdc++.h>
using namespace std;
int vis[1000005], cnt[1000005], a[100005];
vector<int>primeFactor[1000005];
vector<int>prime;
void sieve(){
    for(int i=2; i<=1000000; i++){
        if(vis[i]==0){
            primeFactor[i].push_back(i);
            prime.push_back(i);
            for(int j=i+i; j<=1000000; j+=i){
                vis[j] = 1;
                primeFactor[j].push_back(i);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sieve();
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++){
        int n; cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            for(int j=0; j<primeFactor[a[i]].size(); j++){
                cnt[primeFactor[a[i]][j]]++;
            }
        }
        int ans = 0;
        for(int i=0; i<prime.size(); i++){
            ans += (cnt[prime[i]]/3);
            if(cnt[prime[i]]%3 != 0)ans++;
            cnt[prime[i]] = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
