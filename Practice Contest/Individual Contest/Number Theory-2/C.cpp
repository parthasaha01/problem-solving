#include<stdio.h>
#include<math.h>
#define LL long long int
const int MAXN = 10000000;
bool isprime[MAXN+5];
int prime[664585], sz=0;
void sieve(){
    for(int i=2; i<=MAXN; i++) isprime[i] = 1;

    for(int i=2; i<=MAXN; i++){
        if(isprime[i]==1){
            prime[++sz] = i;
            for(int j=i+i; j<=MAXN; j+=i){
                isprime[j] = 0;
            }
        }
    }
    //printf("sz=%d\n",sz);
}

LL solve(LL n){
    if(n<0)n *= -1LL;
    LL LPD = -1;
    int cnt = 0;
    for(int i=1; i<=sz && prime[i]<=sqrt(n); i++){
        if(n%prime[i]==0){
            cnt++;
            if(prime[i]>LPD) LPD = prime[i];
            while(n%prime[i]==0){
                n /= prime[i];
            }
        }
    }
    if(n>1){
        cnt++;
        if(n>LPD) LPD = n;
    }

    if(cnt>1)return LPD;
    else return -1;
}
int main(){
    sieve();
    LL n;
    while(scanf("%lld",&n) && n){
        LL LPD = solve(n);
        printf("%lld\n",LPD);
    }
    return 0;
}

