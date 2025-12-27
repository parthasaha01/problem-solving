#include<stdio.h>
int isprime[1005], prime[1005], cum[1005], sz=0;
void sieve(){
    for(int i=1; i<=1000; i++) isprime[i] = 1;
    prime[++sz] = 1;
    for(int i=2; i<=1000; i++){
        if(isprime[i]==1){
            prime[++sz] = i;
            for(int j=i+i; j<=1000; j+=i){
                isprime[j] = 0;
            }
        }
    }

    for(int i=1; i<=1000; i++){
        if(isprime[i]==true){
            cum[i] = cum[i-1] + 1;
        }else{
            cum[i] = cum[i-1];
        }
    }
}

void solve(int n, int c){
    int k, cnt = cum[n];
    if(cnt%2==0) k = 2*c;
    else k = 2*c - 1;

    int bad=0, Beg = 1, End = cnt;
    if(cnt>=k){
        bad = cnt-k;
        Beg = (bad/2) + 1;
        End = cnt - (bad/2);
    }

    printf("%d %d:",n,c);
    for(int i=Beg; i<=End; i++){
        printf(" %d",prime[i]);
    }
    printf("\n\n");
}
int main(){
    sieve();
    int n,c;
    while(scanf("%d%d",&n,&c)==2){
        solve(n,c);
    }
    return 0;
}
