#include<stdio.h>
int isprime[105], prime[30], ans[30], sz=0;
void sieve(){
    for(int i=2; i<=100; i++)isprime[i] = 1;
    for(int i=2; i<=100; i++){
        if(isprime[i]==1){
            prime[++sz] = i;
            for(int j=i+i; j<=100; j+=i){
                isprime[j] = 0;
            }
        }
    }
}
int fun(int n, int p){
    int cnt = 0;
    for(int i=p; i<=n; i*=p){
        cnt += (n/i);
    }
    return cnt;
}
void solve(int n){
    int k = 0;
    for(int i=1; i<=sz && prime[i]<=n; i++){
        ans[++k] = fun(n,prime[i]);
    }

    printf("%3d! =",n);
    if(k<=15){
        for(int i=1; i<=k; i++){
            printf("%3d",ans[i]);
        }
        printf("\n");
    }else{
        for(int i=1; i<=15; i++){
            printf("%3d",ans[i]);
        }
        printf("\n");
        printf("      ");
        for(int i=16; i<=k; i++){
            printf("%3d",ans[i]);
        }
        printf("\n");
    }
}
int main(){
    sieve();
    int n;
    while(scanf("%d",&n) && n){
        solve(n);
    }
    return 0;
}
