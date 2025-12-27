#include<bits/stdc++.h>
using namespace std;
int n,a[105];
double dp[105];
double fun(int pos){
    if(pos==n) return a[pos];
    if(dp[pos]!=-1.0) return dp[pos];
    double ret = a[pos];
    for(int i=1; i<=6; i++){
        double k=min(6.0,(double)n-pos);
        if(pos+i<=n){
            ret += (1.0/k)*fun(pos+i);
        }
    }
    return dp[pos] = ret;
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }
        for(int i=0; i<105; i++)dp[i]=-1.0;
        double ans = fun(1);
        printf("Case %d: %.10f\n",ks,ans);
    }
    return 0;
}
