#include<bits/stdc++.h>
using namespace std;
#define N 31625
int isprime[N+5], prime[N+5], sz;
void sieve(){
    for(int i=1; i<=N; i++)isprime[i]=1;
    for(int i=2; i<=N; i++){
        if(isprime[i]==1){
            prime[++sz] = i;
            for(int j=i+i; j<=N; j+=i){
                isprime[j] = 1;
            }
        }
    }
}
int EulerPhi(int n){
    int ans = n;
    for(int i=1; i<=sz && prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            ans /= prime[i];
            ans *= (prime[i]-1);
            while(n%prime[i]==0){
                n /= prime[i];
            }
        }
    }
    if(n>1){
        ans /= n;
        ans *= (n-1);
    }
    return ans;
}
int main(){
    sieve();
    int n;
    while(scanf("%d",&n) && n){
        printf("%d\n",EulerPhi(n));
    }
    return 0;
}