#include<stdio.h>
#include<math.h>
#define N 31630
int isprime[N+5], prime[3405], ans[100005], vis[100005], sz=0;
void sieve(){
    for(int i=2; i<=N; i++) isprime[i] = 1;

    for(int i=2; i<=N; i++){
        if(isprime[i]==1){
            prime[++sz] = i;
            for(int j=i+i; j<=N; j+=i){
                isprime[j] = 0;
            }
        }
    }
    //printf("%d %d\n",sz, prime[sz]);
}
void segmented_sieve(int m, int n){
    for(int i=0; i<=100002; i++)vis[i] = 1;
    if(m<2) vis[0] = 0;

    for(int i=1; i<=sz && prime[i]*prime[i]<=n; i++){
        int start = (m/prime[i])*prime[i];
        if(start<m) start += prime[i];
        if(start==prime[i]) start += prime[i];
        for(int j=start; j<=n; j+=prime[i]){
            vis[j-m] = 0;
        }
    }
}
void solve(int m,int n){
    if(m>n){
        int temp = m;
        m = n;
        n = temp;
    }
    int k = 0;
    if(n<=31630){
        for(int i=m; i<=n; i++){
            if(isprime[i]==1){
                ans[++k]  = i;
            }
        }
    }else{
        segmented_sieve(m,n);

        for(int i=m; i<=n; i++){
            if(vis[i-m]==1){
                ans[++k] = i;
            }
        }
    }

    for(int i=1; i<=k; i++){
        printf("%d\n",ans[i]);
    }
}
int main(){
    sieve();
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        if(ks>1)printf("\n");
        int m,n; scanf("%d%d",&m,&n);
        solve(m,n);
    }
    return 0;
}
