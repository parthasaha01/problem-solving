#include<stdio.h>
#define N 1000000
int prime[N+5], NOD[N+5], ans[N+5], k=0;
void sieve(){
    for(int i=2; i<=N; i++) prime[i] = i;

    for(int i=2; i<=N; i++){
        if(prime[i]==i){
            for(int j=i+i; j<=N; j+=i){
                if(i<prime[j])prime[j] = i;
            }
        }
    }
}
void NumberOfDivisors(){
    for(int i=2; i<=N; i++) NOD[i] = 0;
    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j+=i){
            NOD[j]++;
        }
    }
}
int fun(int n){
    if(prime[n]==n)return 0;
    int x = prime[n];
    n /= prime[n];
    if(x == prime[n])return 0;
    if(n != prime[n])return 0;
    return 1;
}
void precalc(){
    k = 0;
    for(int i=2; i<=N; i++){
        if(fun(NOD[i])==1){
            ans[++k] = i;
        }
    }
}
void print(){
    for(int i=9; i<=k; i+=9){
        printf("%d\n",ans[i]);
    }
}
int main(){
    sieve();
    NumberOfDivisors();
    precalc();
    print();
}
