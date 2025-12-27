///https://toph.co/p/easy-math
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bigmod(ll b, ll p, ll m){
    ll res = 1%m, k = b%m;
    while(p){
        if(p&1) res = (res*k)%m;
        k = (k*k)%m;
        p = p>>1LL;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string a,b;
    ll m;
    while(cin>>a>>b>>m){
        if(a=="0" && b=="0" && m==0)break;

        ll base = 0;
        for(int i=0; i<a.size(); i++){
            int d = a[i]-'0';
            base = ((base*10)+d)%m;
        }

        ll ans = 1;
        for(int i=0; i<b.size(); i++){
            int d = b[i]-'0';
            ans = (bigmod(ans,10,m) * bigmod(base,d,m))%m;
        }

        cout << ans << endl;
    }
    return 0;
}
