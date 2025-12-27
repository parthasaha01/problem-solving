#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>v;
void precalc(){
    ll sum = 0;
    for(int i=1; i<=100000; i++){
        int card = 2*i + (i-1);
        sum += card;
        if(sum>1000000000){
            break;
        }
        v.push_back(sum);
    }
    //cout<<v.size()<<endl;
}
int card_need(int n) {
    int lo=0, hi=v.size()-1;
    int cnt = 0;
    while(lo<=hi){
        int md = (lo+hi)/2;
        if(v[md]<=n){
            cnt = v[md];
            lo = md+1;
        }else{
            hi = md-1;
        }
    }
    return cnt;
}
int solve(int n) {
    int ans = 0;
    while(n>1){
        int cnt = card_need(n);
        n -= cnt;
        ans++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    precalc();

    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
