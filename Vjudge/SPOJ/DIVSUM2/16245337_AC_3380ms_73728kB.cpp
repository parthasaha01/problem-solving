#include<stdio.h>
#define LL long long int
#define N 100000000
#define M 5761460
LL isprime[N/64+10];
LL pr[5761460];
int sz;
void sieve()
{
    for(LL i=3;i<=N;i+=2){
        if(!(isprime[i/64]&(1LL<<(i%64)))){
            for(LL j=i*i;j<=N;j+=2*i){
                isprime[j/64]|=(1LL<<(j%64));
            }
        }
    }

    pr[++sz]=2;
    for (int i = 3; i<=N; i+=2){
        if(!(isprime[i/64]&(1LL<<(i%64)))){
            pr[++sz] = i;
        }
    }
}
LL getPower(LL n, int p){
	LL x=1, y=n;
	while(p>0){
		if(p&1) x *= y;
		y *= y;
		p >>= 1;
	}
	return x;
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
            ans *= ((getPower(pr[i],k+1)-1)/(pr[i]-1));
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
