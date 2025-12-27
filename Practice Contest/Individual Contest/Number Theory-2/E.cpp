#include<stdio.h>
#include<math.h>
struct data{
    int prime, power;
}factor[25];
int isprime[10005],pr[10005],sz=0,k=0;
void sieve(){
    for(int i=2; i<=10000; i++) isprime[i] = 1;
    for(int i=2; i<=10000; i++){
        if(isprime[i]==1){
            pr[++sz] = i;
            for(int j=i+i; j<=10000; j+=i){
                isprime[j] = 1;
            }
        }
    }
}
void factorize(int n){
    k = 0;
    for(int i=1; i<=sz && pr[i]*pr[i]<=n; i++){
        if(n%pr[i]==0){
            int cnt = 0;
            while(n%pr[i]==0){
                cnt++;
                n /= pr[i];
            }
            ++k;
            factor[k].prime = pr[i];
            factor[k].power = cnt;
        }
    }
    if(n>1){
        ++k;
        factor[k].prime = n;
        factor[k].power = 1;
    }
}
int fun(int n, int p){
    int cnt = 0;
    for(int i=p; i<=n; i*=p){
        cnt += (n/i);
    }
    return cnt;
}
int solve(int m,int n){
    factorize(m);
    int ans = 10000000;
    for(int i=1; i<=k; i++){
        int cnt = fun(n, factor[i].prime);
        if(cnt<factor[i].power)return -1;
        int ret = cnt / factor[i].power;
        if(ret<ans) ans = ret;
    }
    return ans;
}
int main(){
    sieve();
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int m,n; scanf("%d%d",&m,&n);
        int ans = solve(m,n);
        printf("Case %d:\n",ks);
        if(ans==-1)printf("Impossible to divide\n");
        else printf("%d\n",ans);
    }
    return 0;
}
