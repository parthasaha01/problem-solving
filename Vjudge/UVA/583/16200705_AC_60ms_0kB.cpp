#include<stdio.h>
#define N 46350
bool isprime[N+5];
int prime[4805], factor[35], sz=0, k;
void sieve(){
    for(int i=2; i<=N; i++){
        isprime[i] = true;
    }
    for(int i=2; i<=N; i++){
        if(isprime[i]==true){
            prime[++sz] = i;
            for(int j=i+i; j<=N; j+=i){
                isprime[j] = false;
            }
        }
    }
    //printf("Total Prime = %d\n",sz);
}
void factorize(int n){
    k = 0;
    for(int i=1; i<=sz && prime[i]*prime[i]<=n; i++){
        while(n%prime[i]==0){
            factor[++k] = prime[i];
            n /= prime[i];
        }
    }
    if(n>1)factor[++k] = n;
}
void solve(int n){
    if(n==1 || n==-1){
        printf("%d = %d\n",n,n);
        return;
    }

    if(n<0) printf("%d = -1 x",n);
    else printf("%d =",n);

    if(n<0) n*=-1;

    factorize(n);

    for(int i=1; i<=k; i++){
        if(i==k)printf(" %d\n",factor[i]);
        else printf(" %d x",factor[i]);
    }
}
int main(){
    sieve();
    int n;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        solve(n);
    }
    return 0;
}

