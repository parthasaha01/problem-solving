#include<stdio.h>
#define N 10000
#define LL long long
int phi[N+5], cum[N+5];
void EulerPhi(){
    for(int i=1; i<=N; i++)phi[i]=i;
    for(int i=2; i<=N; i++){
        if(phi[i]==i){
            phi[i] = i-1;
            for(int j=i+i; j<=N; j+=i){
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }

    for(int i=1; i<=N; i++){
        cum[i] = cum[i-1]+phi[i];
    }
}

int main(){
    EulerPhi();
    int tt; scanf("%d",&tt);
    while(tt--){
        int n; scanf("%d",&n);
        LL ans = (LL)cum[n]*cum[n];
        printf("%lld\n",ans);
    }
    return 0;
}


