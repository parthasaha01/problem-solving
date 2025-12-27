#include<stdio.h>
#define N 100000000
bool isprime[N+5];;
void sieve(){
    for(int i=1; i<=N; i++)isprime[i]=true;
    for(int i=4; i<=N; i+=2)isprime[i]=false;
    for(int i=3; i<=10000; i+=2){
        if(isprime[i]==true){
            for(int j=i*i; j<=N; j+=i+i){
                isprime[j] = false;
            }
        }
    }
}
int solve(int n){
    int x;
    if(n%2==0) x = (n/2)-1;
    else x = (n/2);

    for(int i=x; i>=1; i--){
        if(isprime[i] && isprime[n-i]){
            return i;
        }
    }
    return -1;
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

