#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>both, alice, bob;
ll solve(int k){

    if((int)both.size()+(int).alice.size() < k) return -1;
    if((int)both.size()+(int).bob.size() < k) return -1;

    int bs=0, as=0, bb = 0;
    ll ans = 0;
    for(int i=0; i<k; i++){
        if(bs==(int)both.size()){
            ans += alice[as++];
            ans += bob[bb++];
        }else{

        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        for(int i=0; i<n; i++){
            int t,a,b; cin>>t>>a>>b;
            if(a && b){
                both.push_back(t);
            }else if(a){
                alice.push_back(t);
            }else if(b){
                bob.push_back(t);
            }
        }

        sort(both.begin(), both.end());
        sort(alice.begin(), alice.end());
        sort(bob.begin(), bob.end());

        cout<<solve(k)<<endl;
    }
    return 0;
}





