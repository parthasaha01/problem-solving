#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 993344777;
int n, k, a[1000005], b[65], vis[65], v[65], fre[65], cnt[65];
ll dp[65][65][2][2];
vector<int>prime[65];
ll fun(int pos, int xorr, int isOdd,int suru){
    if(pos==k){
        if(suru==0) return 0LL;
        if(xorr==0){
            if(isOdd==0) return 1LL;
            else return 0LL;
        }else{
            if(isOdd==1) return 1LL;
            else return 0LL;
        }
    }

    if(dp[pos][xorr][isOdd][suru] != -1)return dp[pos][xorr][isOdd][suru];

    ll ret = 0;
    ret += (cnt[pos] * fun(pos+1,xorr^v[b[pos]],1-isOdd,1))%mod;
    ret %= mod;
    ret += fun(pos+1,xorr,isOdd,suru)%mod;
    ret %= mod;

    return dp[pos][xorr][isOdd][suru] = ret;
}
void sieve(){
    for(int i=2; i<=60; i++){
        if(vis[i]==0){
            prime[i].push_back(i);
            for(int j=i+i; j<=60; j+=i){
                vis[j] = 1;
                int kk=0;
                int temp = j;
                while(temp%i==0){
                    kk++;
                    temp /= i;
                }
                if(kk%2==1){
                    prime[j].push_back(i);
                }
            }
        }
    }

    for(int i=1; i<=60; i++){
        int temp = 0;
        for(int j=0; j<prime[i].size(); j++){
            temp ^= prime[i][j];
        }
        v[i] = temp;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sieve();
    while(cin>>n){
        set<int>ss;
        memset(fre,0,sizeof(fre));
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<n; i++){
            cin>>a[i];
            ss.insert(a[i]);
            fre[a[i]]++;
        }
        k = 0;
        for(auto it=ss.begin(); it!=ss.end(); it++){
            b[k] = *it;
            cnt[k++] = fre[*it];
        }
        memset(dp,-1,sizeof(dp));
        ll ans = fun(0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
