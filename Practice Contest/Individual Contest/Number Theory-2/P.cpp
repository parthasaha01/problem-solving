#include<stdio.h>
#define N 1000000
int phi[N+5];
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
}

int main(){
    EulerPhi();
    int tt; scanf("%d",&tt);
    while(tt--){
        int n; scanf("%d",&n);
        printf("%d\n",phi[n]);
    }
    return 0;
}

