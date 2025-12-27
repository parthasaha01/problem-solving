#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int n; scanf("%d",&n);
        int neg = 0, sum = 0;
        for(int i=1; i<=n; i++){
            int x; scanf("%d",&x);
            if(x<0)neg++;
            sum += abs(x);
        }

        if(n==neg){
            printf("Case %d: inf\n",ks);
        }else{
            int gcd = __gcd(sum,n-neg);
            printf("Case %d: %d/%d\n",ks,sum/gcd,(n-neg)/gcd);
        }
    }
    return 0;
}
