#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n,m,h=0,sum=0; cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
        h = max(h,a[i]);
        sum += a[i];
    }

    sort(a,a+n);

    if(n==1){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    ll cur = 0;
    for(int i=0; i<n; i++){
        if(cur==h){
            ans += a[i]-1;
            continue;
        }

        if(i==0 && i<n-1){
            cur++;
            ans += (a[i]-1);
        }else if(i<n-1){
            if(a[i]>cur){
                ans += (a[i]-1);
                cur++;
            }else{
                ans += (a[i]-1);
            }
        }else{
            ll rem = h-cur;
            if(rem>0){
                ans += a[i]-rem;
            }
        }
    }

    cout << ans << endl;

    //main();

    return 0;

}
