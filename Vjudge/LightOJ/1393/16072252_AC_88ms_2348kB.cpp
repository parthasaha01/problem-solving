#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int n,m; scanf("%d%d",&n,&m);
        int coins[n+1][m+1], valid[n+1][m+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                scanf("%d",&coins[i][j]);
            }
        }
        for(int i=n; i>=1; i--){
            for(int j=m; j>=1; j--){
                if(j==m){
                    if(i==n)valid[i][j]=0;
                    else valid[i][j] = !valid[i+1][j];
                }
                else{
                    valid[i][j] = !valid[i][j+1];
                }
            }
        }
        int xxor = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(valid[i][j]){
                    xxor^=coins[i][j];
                }
            }
        }

        if(xxor==0)printf("Case %d: lose\n",ks);
        else printf("Case %d: win\n",ks);
    }
    return 0;
}
