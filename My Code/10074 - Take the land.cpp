#include<bits/stdc++.h>
using namespace std;
int n,m,a[105][105],c[105][105],v[105],kd[105];
int main()
{
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==1)a[i][j]=-1000000;
                else a[i][j]=1;
            }
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                c[i][j]=c[i][j-1]+a[j][i];
            }
        }

        int ans=0;

        for(int i=1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
            {
                for(int k=1; k<=m; k++)
                {
                    v[k] = c[k][j]-c[k][i-1];
                }
                for(int x=1; x<=m; x++)
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

/*

6 7
0 1 1 0 1 1 0
0 0 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 0 0 0 1
1 1 0 0 0 1 0
1 1 0 1 1 0 0

5 3
1 1 0
1 1 0
1 1 1
1 0 0
0 0 0


*/

