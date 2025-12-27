#include<bits/stdc++.h>
using namespace std;
int dp[100001][32], cum[32];
int N,A,B,X,Y,Z;
int HooliNeeds() {
    int need = Z-B;
    int d;
    if(need%Y==0){
        d = (need-1)/Y;
    }else{
        d = (need)/Y;
    }

    return d;
}
int solve() {
    int ans = -1;
    int lo = 0;
    int hi = 31;

    for(int i=0; i<32; i++) {

    }

}

int main() {
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++) {

        scanf("%d%d%d%d%d%d",&N,&A,&B,&X,&Y,&Z);

        for(int i=1; i<=N; i++) {
            scanf("%d",&c[i]);
        }

        memset(dp,0,sizeof(dp));

        for(int i=1; i<=N; i++) {
            dp[i][0] = 0;
            int x = a[i];
            for(int j=1; j<32; j++) {
                dp[i][j] += dp[i][j-1]+x;
                x /= 2;
            }
        }

        memset(cum,0,sizeof(cum));

        for(int j=1; j<32; j++) {
            for(int i=1; i<=N; i++) {
                cum[j] += dp[i][j];
            }
        }

        int ans = solve();

        if(ans<0){
            printf("RIP\n");
        }else{
            printf("%d\n",ans);
        }
    }

    return 0;
}
