#include<stdio.h>
#define LL long long int
#define N 100000000
#define M 5761460
bool isprime[N+2];
LL pr[5761460], sz=0;
void sieve(){
    for(int i=2; i<=N; i++) isprime[i] = true;
    for(int i=4; i<=N; i+=2) isprime[i] = false;
    for(int i=3; i<=10000; i+=2){
        if(isprime[i]==true){
            for(int j = i*i; j<=N; j+=2*i){
                isprime[j] = false;
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(isprime[i]){
            pr[++sz] = i;
        }
    }
}
LL getPower(LL b, LL k){
    LL ans = 1;
    for(int i=1; i<=k; i++) ans *= b;
    return ans;
}
LL SumOfDivisors(LL n){
    LL ans = 1;
    LL m = n;
    for(int i=1; i<=sz && (LL)pr[i]*pr[i]<=n; i++){
        if(n%pr[i]==0){
            int k = 0;
            while(n%pr[i]==0){
                k++;
                n /= pr[i];
            }
            ans *= (getPower(pr[i],k+1)-1)/(pr[i]-1);
        }
    }
    if(n>1){
        ans *= (n+1);
    }
    ans -= m;
    return ans;
}
int main(){
    sieve();
    int tt; scanf("%d",&tt);
    while(tt--){
        LL n; scanf("%lld",&n);
        LL ans = SumOfDivisors(n);
        printf("%lld\n",ans);
    }
    return 0;
}
