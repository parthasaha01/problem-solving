#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
int cnt[10],k;
ll fac[20],ans=0;
void fun(int pos, vi v)
{
    if(pos==10){
        ll ret = 0;
        int tot = 0;
        for(int i=0; i<v.size(); i++) tot += v[i];
        ret = fac[tot];
        for(int i=0; i<v.size(); i++) ret /= fac[v[i]];
        if(v[0]>0){
            ll temp = fac[tot-1];
            temp /= fac[v[0]-1];
            for(int i=1; i<v.size(); i++) temp /= fac[v[i]];
            ret -= temp;
        }
        ans += ret;
        return;
    }

    if(cnt[pos]==0){
        vi u = v;
        u.push_back(0);
        fun(pos+1,u);
    }
    else{
        for(int i=1; i<=cnt[pos]; i++){
            vi u = v;
            u.push_back(i);
            fun(pos+1,u);
        }
    }
}
int main()
{
    fac[0] = 1;
    for(ll i=1; i<=20; i++) fac[i] = fac[i-1]*i;

    ll n; cin>>n;

    while(n!=0){
        int r = n%10LL;
        cnt[r]++;
        n /= 10LL;
    }

    ans = 0;
    vi v;
    fun(0,v);
    cout << ans << endl;

    return 0;
}

