#include<bits/stdc++.h>
using namespace std;
int phi[1000005];
long long int ans[1000005];
void EulerPhi(){
    for(int i=2; i<=1000000; i++) phi[i]=i;
    for(int i=2; i<=1000000; i++){
        if(phi[i]==i){
            phi[i] = i-1;
            for(int j=i+i; j<=1000000; j+=i){
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }

    for(int i=1; i<=1000000; i++){
        ans[i] = ans[i-1]+phi[i];
    }
}
int main(){
    EulerPhi();
    int n;
    while(scanf("%d",&n) && n){
        printf("%lld\n",ans[n]);
    }
    return 0;
}
