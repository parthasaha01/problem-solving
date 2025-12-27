#include<bits/stdc++.h>
using namespace std;
int a[105][105],c[105][105],v[105],kd[105];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int s; scanf("%d",&s);

        for(int i=1; i<=s; i++){
            for(int j=1; j<=s; j++){
                a[i][j]=1;
            }
        }

        int b; scanf("%d",&b);

        for(int i=1; i<=b; i++)
        {
            int r1,c1,r2,c2;
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            for(int x=r1; x<=r2; x++){
                for(int y=c1; y<=c2; y++){
                    a[x][y] = -1000000;
                }
            }
        }

        for(int i=1; i<=s; i++){
            for(int j=1; j<=s; j++){
                c[i][j]=c[i][j-1]+a[i][j];
            }
        }

        int ans=-1000000;

        for(int i=1; i<=s; i++)
        {
            for(int j=i; j<=s; j++)
            {
                for(int k=1; k<=s; k++)
                {
                    v[k] = c[k][j]-c[k][i-1];
                }
                for(int x=1; x<=s; x++) // kadane or 1D maximum sum
                {
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
