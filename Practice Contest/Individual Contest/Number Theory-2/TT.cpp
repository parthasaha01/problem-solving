#include<stdio.h>
#define N 100000000
bool isprime[N+5];
int prime[5761460], sz;
void sieve(){
    for(int i=2; i<=N; i++)isprime[i]=true;
    for(int i=4; i<=N; i+=2)isprime[i]=false;
    for(int i=3; i<=10000; i+=2){
        if(isprime[i]){
            for(int j=i*i; j<=N; j+=i+i){
                isprime[j] = false;
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(isprime[i]){
            prime[++sz] = i;
        }
    }
    //printf("sz=%d\n",sz);
}
int BinarySearch(int x){
    int lo = 1, hi = sz;
    int idx = 0;
    while(lo<=hi){
        int md = (lo+hi)/2;
        if(prime[md]<=x){
            idx = md;
            lo = md+1;
        }else{
            hi = md-1;
        }
    }
    return idx;
}
int solve(int n){
    if(n<4)return -1;
    if(n%2==1){
        if(isprime[n-2]==true)return 2;
        return -1;
    }else{
        int x = (n/2)-1;
        int p = BinarySearch(x);
        for(int i=p; i>=1; i--){
            if(isprime[n-prime[i]]){
                return prime[i];
            }
        }
        return -1;
    }
}
int main(){
    sieve();
    int n;
    while(scanf("%d",&n)==1){
        int p1 = solve(n);
        if(p1==-1) printf("%d is not the sum of two primes!\n",n);
        else printf("%d is the sum of %d and %d.\n",n,p1,n-p1);
    }
    return 0;
}


