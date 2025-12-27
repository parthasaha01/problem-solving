#include<stdio.h>
#include<math.h>
#define N 1000000
int isprime[N+5],pr[78500],primeGap[205],sz=0;
void sieve(){
    for(int i=2; i<=N; i++) isprime[i] = 1;
    for(int i=2; i<=N; i++){
        if(isprime[i]==1){
            pr[++sz] = i;
            for(int j=i+i; j<=N; j+=i){
                isprime[j] = 0;
            }
        }
    }
}
int Lower_Bound(int item){
    int lo = 1, hi = sz;
    int ans = sz+1;
    while(lo<=hi){
        int md = (lo+hi)/2;
        if(pr[md]>=item){
            ans = md;
            hi = md-1;
        }else{
            lo = md+1;
        }
    }
    return ans;
}
int solve(int L,int U){
    if(L>U){
        int temp = L; L = U; U = temp;
    }

    int LB = Lower_Bound(L);
    int UB = Lower_Bound(U);
    if(UB>sz || pr[UB]>U)UB--;

    if(LB>=UB)return -1;

    for(int i=0; i<=200; i++)primeGap[i] = 0;

    int maxx = 0;
    for(int i=LB; i<UB; i++){
        int d = pr[i+1] - pr[i];
        primeGap[d]++;
        if(primeGap[d]>maxx)maxx = primeGap[d];
    }

    int cnt = 0, ans = -1;
    for(int d=1; d<=200; d++){
        if(primeGap[d]==maxx){
            cnt++;
            ans = d;
        }
    }

    if(cnt>1)return -1;
    return ans;
}
int main(){
    sieve();
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int L,U; scanf("%d%d",&L,&U);
        int ans = solve(L,U);
        if(ans==-1)printf("No jumping champion\n");
        else printf("The jumping champion is %d\n",ans);
    }
    return 0;
}


