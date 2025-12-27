#include<bits/stdc++.h>
using namespace std;
int a[105][105],c[105][105],v[105],kd[105];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int row,col;
        row=col=n;
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                scanf("%d",&a[i][j]);
            }
        }

        for(int i=1; i<=col; i++){
            for(int j=1; j<=row; j++){
                c[i][j]=c[i][j-1]+a[i][j];
            }
        }

        int ans=-10000000;

        for(int i=1; i<=row; i++)
        {
            for(int j=i; j<=row; j++)
            {
                for(int k=1; k<=col; k++)
                {
                    v[k] = c[k][j]-c[k][i-1];
                }
                for(int x=1; x<=col; x++) // kadane or 1D maximum sum
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
