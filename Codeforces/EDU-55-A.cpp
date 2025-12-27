#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n,ll x,ll y,ll d){
    ll diff = abs(x-y);
    ll ans = 100000000000000000;
    if(diff%d==0){
        return diff/3;
    }else{
        ll s,cur;

        s=0,cur=0;
        s = x-1;
        cur += s/d;
        if(s%d!=0)cur++;
        s = y-1;
        if(s%d==0){
            cur += s/d;
            ans = min(ans,cur);
        }

        s=0,cur=0;
        s = x-1;
        cur += s/d;
        if(s%d!=0)cur++;
        s = n-1;
        cur += s/d;
        if(s%d!=0)cur++;
        s = n-y;
        if(s%d==0){
            cur += s/d;
            ans = min(ans,cur);
        }

        s=0,cur=0;
        s = n-x;
        cur += s/d;
        if(s%d!=0)cur++;
        s = n-y;
        if(s%d==0){
            cur += s/d;
            ans = min(ans,cur);
        }

        s=0,cur=0;
        s = n-x;
        cur += s/d;
        if(s%d!=0)cur++;
        s = n-1;
        cur += s/d;
        if(s%d!=0)cur++;
        s = y-1;
        if(s%d==0){
            cur += s/d;
            ans = min(ans,cur);
        }

        if(x<y){

        }else{
            s=0,cur=0;
            s = x-y;

        }

        if(ans==100000000000000000)return -1;
        else return ans;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        ll n,x,y,d;
        cin>>n>>x>>y>>d;
        ll ans = solve(n,x,y,d);
        cout<<ans<<endl;
    }
    return 0;
}
