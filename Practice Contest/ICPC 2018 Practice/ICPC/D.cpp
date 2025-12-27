#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a%c;

    while(b>0){
        if(b%2==1) x = (x+y)%c;
        y = (y*2)%c;
        b /= 2;
    }
    return x;
}
ll modulo (ll a, ll b, ll c){
    ll x = 1, y = a%c;
    while(b>0){
        if(b%2==1) x = mulmod(x,y,c);
        y = mulmod(y,y,c);
        b /= 2;
    }
    return x;
}
bool miller(ll p, int iter){
    if(p<2) return false;
    if(p==2) return true;
    if(p%2==0)return false;

    ll s = p-1;

    while(s%2==0){
        s/=2;
    }

    for(int i=0; i<iter; i++){
        ll a = rand()%(p-1) + 1;
        ll temp = s;
        ll mod = modulo(a, temp, p);

        while(temp != p-1 && mod != 1 && mod != p-1){
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }

        if(mod != p-1 && temp%2==0) return false;
    }

    return true;
}
bool check(ll n)
{
    while(n!=0){
        ll r = n%10;
        if(r==0 || r==1 || r==4 || r==6 || r==8 || r==9)return 0;
        n /= 10;
    }
    return 1;
}
ll solve(ll n)
{
    for(ll i=n; i>=2; i--){
        if(check(i)){
            bool ans = miller(i, 1);
            if(ans)return i;
        }
    }
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        ll n; scanf("%lld",&n);
        ll ans = solve(n);
        printf("Case %d: %lld\n", ks, ans);
    }
    return 0;
}

