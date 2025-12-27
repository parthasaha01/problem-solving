#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 0;
    for(int i=0; i<=4; i++){
        for(int j=0; j<=4; j++){
            for(int k=0; k<=4; k++){
                for(int l=0; l<=4; l++){
                    if(i==0&&j==0&&k==0&&l==0)continue;
                    if(i==0&&j==0&&k==0)continue;
                    if(i==0&&j==0){
                        if(k==l){
                            ans++;
                        printf("%d - %d%d%d%d\n",ans,i,j,k,l);
                        }
                        continue;
                    }
                    if(i==0){
                        continue;
                    }
                    if(i==j){
                        if(k==l){
                            ans++;
                            printf("%d - %d%d%d%d\n",ans,i,j,k,l);
                        }
                    }
                    else if(i==k){
                        if(j==l){
                            ans++;
                            printf("%d - %d%d%d%d\n",ans,i,j,k,l);
                        }
                    }
                    else if(i==l){
                        if(j==k){
                            ans++;
                            printf("%d - %d%d%d%d\n",ans,i,j,k,l);
                        }
                    }
                }
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}
