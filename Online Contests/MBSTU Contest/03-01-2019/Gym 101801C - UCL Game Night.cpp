#include<bits/stdc++.h>
using namespace std;
int row,col,kk,a[105][105],cs[105][105],v[105],kd[105];
int main(){
    int tt; scanf("%d",&tt);
    while(tt--){
        scanf("%d%d%d",&row,&col,&kk);
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                scanf("%d",&a[i][j]);
            }
        }

        for(int j=1; j<=col; j++){
            for(int i=1; i<=row; i++){
                cs[j][i]=cs[j][i-1]+a[i][j];
            }
        }

        int ans=0;
        for(int i=1; i<=row; i++){
            for(int k=i; k<=row; k++){
                for(int j=1; j<=col; j++){
                    v[j] = cs[j][k]-cs[j][i-1];
                }

                for(int x=1,c=1; x<=col; x++){
                    kd[x]=kd[x-1]+v[x];
                    if(kd[x]>kk){
                        for(int y=c; y<=x; y++){
                            kd[x] -= v[c];
                            c++;
                            if(kd[x]<=kk)break;
                        }
                        int area = (k-i+1)*(x-c+1);
                        ans = max(ans,area);
                    }else{
                        int area = (k-i+1)*(x-c+1);
                        ans = max(ans,area);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
