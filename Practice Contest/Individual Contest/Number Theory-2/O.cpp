#include<stdio.h>
#define N 31622
int isprime[N+5], pr[3405], sz;
void sieve(){
    for(int i=2; i<=N; i++)isprime[i]=1;
    for(int i=2; i<=N; i++){
        if(isprime[i]){
            pr[++sz] = i;
            for(int j=i+i; j<=N; j+=i){
                isprime[j] = 0;
            }
        }
    }
}
int EulerPhi(int n){
    if(n==1)return 0;
    int ans = n;
    for(int i=1; i<=sz && pr[i]*pr[i]<=n; i++){
        if(n%pr[i]==0){
            ans /= pr[i];
            ans *= (pr[i]-1);
            while(n%pr[i]==0){
                n /= pr[i];
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
        int ans = EulerPhi(n);
        printf("%d\n",ans);
    }
    return 0;
}
