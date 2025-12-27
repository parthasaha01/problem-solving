#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[400005], cum[400005][65], ret[65], s[65];

void process_array(int n){
    for(int i=1; i<=n; i++) {
        for(ll j=0; j<64; j++) {
            if(a[i]&(1LL<<j)){
                cum[i][j] = cum[i-1][j]+1;
                //cout<<1;
            }else{
                cum[i][j] = cum[i-1][j];
                //cout<<0;
            }
        }
    }
    return;
}

void process_solution(int n) {
    for(int i=1; i<n; i++) {
        for(ll j=0; j<64; j++) {
            if(a[i]&(1LL<<j)){
                ret[j] += (n-i) - (cum[n][j] - cum[i][j]);
            }else{
                ret[j] += cum[n][j] - cum[i][j];
            }
        }
    }
}
ll get_solution() {
    int carry = 0;
    for(int i=0; i<64; i++) {
        int cnt = ret[i] + carry;
        s[i] = cnt&1;
        carry = cnt/2;
    }

    ll ans = 0;
    for(ll i=0; i<64; i++) {
        ans += (s[i]*(1LL<<i));
    }
    return ans;
}
int main() {
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%lld",&a[i]);
    }

    process_array(n);

    process_solution(n);

    ll ans = get_solution();

    printf("%lld\n",ans);

    return 0;
}
