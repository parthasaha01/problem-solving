#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>a,b;
bool check(int x, int n, int k) {
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i]<=x){
            cnt++;
            i++;
        }
    }

}
int solve(int n, int k){
    sort(b.begin(), b.end());
    int lo = 0, hi = n-1;
    int ans = b[n-1];
    while(lo<=hi){
        int m = (lo+hi)/2;
        if(check(m, n, k)){
            ans = b[m];
            hi = m-1;
        }else{
            lo = m+1;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        a.push_back(x);
        b.push_back(x);
    }
    cout<<solve(n,k)<<endl;
    return 0;
}

