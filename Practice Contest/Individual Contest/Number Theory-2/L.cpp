#include<stdio.h>
#define N 1000000
int div[N+5];
void sieve(){
    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j+=i){
            div[j]++;
        }
    }
}
int gcd(int x, int y){
    while(y!=0){
        int r = x%y;
        x = y;
        y = r;
    }
    return x;
}
int main(){
    sieve();
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int a,b; scanf("%d%d",&a,&b);
        int g = gcd(a,b);
        printf("%d\n",div[g]);
    }
    return 0;
}
