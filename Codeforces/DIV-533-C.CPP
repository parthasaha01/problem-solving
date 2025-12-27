#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll dp[200005][3];
ll zero,one,two;
int n,l,r;
ll fun(int pos, int rem){
    if(pos==n){
        if(rem==0) return 1LL;
        else return 0LL;
    }

    if(dp[pos][rem] != -1) return dp[pos][rem];

    ll ret = 0;
    if(rem == 0){
        ret += (zero * fun(pos+1,0)) % mod;
        ret %= mod;
        ret += (one  * fun(pos+1,1)) % mod;
        ret %= mod;
        ret += (two  * fun(pos+1,2)) % mod;
        ret %= mod;
    }else if(rem == 1){
        ret += (zero * fun(pos+1,1)) % mod;
        ret %= mod;
        ret += (one  * fun(pos+1,2)) % mod;
        ret %= mod;
        ret += (two  * fun(pos+1,0)) % mod;
        ret %= mod;
    }else{
        ret += (zero * fun(pos+1,2)) % mod;
        ret %= mod;
        ret += (one  * fun(pos+1,0)) % mod;
        ret %= mod;
        ret += (two  * fun(pos+1,1)) % mod;
        ret %= mod;
    }

    return dp[pos][rem] = ret;
}
void precalc(){
    zero = one = two = 0;
    int tl = 0, tr = 0;
    //zero = (r/3) - ((l-1)/3);
    for(int i=l; i<=r; i++){
        if(i%3==0){
            tl = i;
            break;
        }
    }
    for(int i=r; i>=l; i--){
        if(i%3==0){
            tr = i;
            break;
        }
    }

    if(tl==0){
        zero = 0;
    }else{
        zero = ((tr-tl)/3)+1;
    }

    tl = 0, tr = 0;
    for(int i=l; i<=r; i++){
        if(i%3==1){
            tl = i;
            break;
        }
    }
    for(int i=r; i>=l; i--){
        if(i%3==1){
            tr = i;
            break;
        }
    }

    if(tl==0){
        one = 0;
    }else{
        one = ((tr-tl)/3)+1;
    }

    tl = 0, tr = 0;
    for(int i=l; i<=r; i++){
        if(i%3==2){
            tl = i;
            break;
        }
    }
    for(int i=r; i>=l; i--){
        if(i%3==2){
            tr = i;
            break;
        }
    }

    if(tl==0){
        two = 0;
    }else{
        two = ((tr-tl)/3)+1;
    }
}
int main(){
    cin>>n>>l>>r;

    precalc();

    memset(dp,-1,sizeof(dp));
    ll ans = fun(0,0)%mod;
    cout<<ans<<endl;
    //main();
    return 0;
}
