#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define vii vector<pii>
map<vii, int>mp;
vector<int>prime;
vector<pii>factor;
vector<pii>need;
bool vis[100005];
int n,k, a[100005];
ll one = 0, ans = 0;

void sieve() {
    for(int i=2; i<=100000; i++) {
        if(!vis[i]){
            prime.push_back(i);
            for(int j=i+i; j<=n; j+=i) {
                vis[j] = 1;
            }
        }
    }
}
void factorize(int x) {
    factor.clear();
    need.clear();
    for(int i=0; (i<(int)prime.size()) && (prime[i]*prime[i]<=x); i++) {
        if(x%prime[i]==0) {
            int p = 0;
            while(x%prime[i]==0){
                p++;
                x /= prime[i];
            }
            p %= k;
            if(p!=0){
                factor.push_back(make_pair(prime[i],p));
                need.push_back(make_pair(prime[i],k-p));
            }
        }
    }
    if(x>1){
        int p = 1%k;
        factor.push_back(make_pair(x,p));
        need.push_back(make_pair(x,k-p));
    }

    if((int)need.size()==0) {
        ans += one;
        one++;
    }else{
        ans += mp[need];
        mp[factor]++;
    }
}
int main() {
    sieve();
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    for(int i=0; i<n; i++) {
        factorize(a[i]);
    }

    printf("%lld\n",ans);

    return 0;
}
