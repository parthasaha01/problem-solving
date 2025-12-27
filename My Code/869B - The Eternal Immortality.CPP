#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll NumberOfFive(ll v)
{
    ll cnt = 0;
    for(ll i=5; i<=v; i*=5) cnt+=(v/i);
    return cnt;
}
int main()
{
    ll a,b; cin>>a>>b;
    ll cnta = NumberOfFive(a);
    ll cntb = NumberOfFive(b);
    //cout << cnta<< " " << cntb << endl;
    if(cntb-cnta>10)cout << 0 << endl;
    else {
        ll digit = 1;
        for(ll i=b; i>a; i--){
            digit*=(i);
            digit%=10;
        }
        cout << digit << endl;
    }
    return 0;
}
