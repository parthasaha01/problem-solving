#include<stdio.h>
#define LL long long int
LL solve(LL n){
    if(n<3)return n;
    if(n%2==1) return n*(n-1)*(n-2);
    else{
        if(n%3==0) return (n-1)*(n-2)*(n-3);
        else return n*(n-1)*(n-3);
    }
}
int main(){
    LL n;
    while(scanf("%lld",&n)==1){
        LL ans = solve(n);
        printf("%lld\n",ans);
    }
    return 0;
}
