#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 993344777;
int n, a[1000005], vis[65];
ll dp[100001][65][2][2];
vector<int>prime[65];
ll fun(int pos, int xorr, int isOdd,int suru){
    if(pos==n){
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
    int newXorr = xorr;
    if(a[pos]>1){
        for(int i=0; i<prime[a[pos]].size(); i++){
            newXorr ^= prime[a[pos]][i];
        }
    }

    ret += fun(pos+1,newXorr,1-isOdd,1);
    ret %= mod;
    ret += fun(pos+1,xorr,isOdd,suru);
    ret %= mod;

    return dp[pos][xorr][isOdd][suru] = ret;
}
void sieve(){
    for(int i=2; i<=60; i++){
        if(vis[i]==0){
            prime[i].push_back(i);
            for(int j=i+i; j<=60; j+=i){
                vis[j] = 1;
                int k=0;
                int temp = j;
                while(temp%i==0){
                    k++;
                    temp /= i;
                }
                if(k%2==1){
                    prime[j].push_back(i);
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sieve();
    while(cin>>n){
        for(int i=0; i<n; i++)cin>>a[i];
        memset(dp,-1,sizeof(dp));
        ll ans = fun(0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}

