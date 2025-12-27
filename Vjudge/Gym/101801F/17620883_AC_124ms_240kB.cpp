#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt; scanf("%d",&tt);
    while(tt--){
        int n; scanf("%d",&n);
        int xr = 0;
        for(int i=1; i<=n; i++){
            int x; scanf("%d",&x);
            xr ^= x;
        }

        if(xr==0)printf("1\n");
        else printf("0\n");
    }
    return 0;
}
