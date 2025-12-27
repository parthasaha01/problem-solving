#include<stdio.h>
#define N 500000
int sod[N+5];
void sieve(){
    for(int i=1; i<=N; i++){
        for(int j=i+i; j<=N; j+=i){
            sod[j]+=i;
        }
    }
}

int main(){
    sieve();
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int x; scanf("%d",&x);
        printf("%d\n",sod[x]);
    }
    return 0;
}
