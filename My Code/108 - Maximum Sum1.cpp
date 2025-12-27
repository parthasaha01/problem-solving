#include<bits/stdc++.h>
using namespace std;
int a[105][105],c[105][105],v[105],kd[105];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d",&a[i][j]);
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                c[i][j]=c[i][j-1]+a[i][j];
            }
        }

        int ans=-10000000;

        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                for(int k=1; k<=n; k++){
                    v[k] = c[k][j]-c[k][i-1];
                }
                for(int x=1; x<=n; x++){
                    kd[x]=kd[x-1]+v[x];
                    if(kd[x]<0)kd[x]=0;
                    ans = max(ans,kd[x]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

