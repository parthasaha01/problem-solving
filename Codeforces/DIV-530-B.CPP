#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll n){
    if(n==1)return 2;
    ll lo = 1, hi = 1000000000;
    ll ret = 0;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        ll sum = mid*(mid+1);
        if(sum==n){
            ret = mid;
            break;
        }else if(sum<n){
            ret = mid+1;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }

    ll tot = ret*(ret-1);
    ll fst = tot+ret;
    ll scd = fst+ret;
    if(n<=fst){
        ll ans = 2*ret;
        return ans;
    }else{
        ll ans = 2*ret;
        ans++;
        return ans;
    }

}
int main(){
    ll n; cin>>n;
    ll ans = fun(n);
    cout<<ans<<endl;
    //main();
    return 0;
}
