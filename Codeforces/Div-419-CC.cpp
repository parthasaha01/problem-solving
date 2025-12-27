#include<bits/stdc++.h>
using namespace std;
int n,m,g[105][105],gg[105][105];
int rx[105],cx[105],rn[105],cn[105],r[105],c[105];
int main()
{

    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&g[i][j]);
        }
    }

    for(int i=1; i<=n; i++)
    {
        int mn=1000;
        for(int j=1; j<=m; j++)
        {
            mn = min(mn,g[i][j]);
        }
        rn[i]=mn;
    }

    for(int j=1; j<=m; j++)
    {
        int mn=1000;
        for(int i=1; i<=n; i++)
        {
            mn = min(mn,g[i][j]);
        }
        cn[j]=mn;
    }

//    int flag=1;
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)
//        {
//            if(rn[i]+cn[j]<g[i][j])
//            {
//                printf("-1\n");
//                return 0;
//            }
//        }
//    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(g[i][j]>cn[j])
            {
                int d= g[i][j]-cn[j];
                r[i]+=d;
                for(int k=1; k<=m; k++)
                {
                    g[i][k] -= d;
                    if(g[i][k]<0)
                    {
                        printf("-1\n");
                        return 0;
                    }
                }
                rn[i]-=d;
            }
            if(g[i][j]>rn[i])
            {
                int d= g[i][j]-rn[i];
                c[j]+=d;
                for(int k=1; k<=n; k++)
                {
                    g[k][j] -= d;
                    if(g[k][j]<0)
                    {
                        printf("-1\n");
                        return 0;
                    }
                }
                cn[j]-=d;
            }
        }
    }

    if(n<=m)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(g[i][j]>0)
                {
                    int d = g[i][j];
                    r[i]+=d;
                    for(int k=1; k<=m; k++)
                    {
                        g[i][k] -= d;
                    }
                }
            }
        }
        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(g[i][j]>0)
                {
                    int d = g[i][j];
                    c[j]+=d;
                    for(int k=1; k<=n; k++)
                    {
                        g[k][j] -= d;
                    }
                }
            }
        }
    }
    else
    {
        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(g[i][j]>0)
                {
                    int d = g[i][j];
                    c[j]+=d;
                    for(int k=1; k<=n; k++)
                    {
                        g[k][j] -= d;
                    }
                }
            }
        }
        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(g[i][j]>0)
                {
                    int d = g[i][j];
                    c[j]+=d;
                    for(int k=1; k<=n; k++)
                    {
                        g[k][j] -= d;
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(g[i][j]<0)
            {
                printf("-1\n");
                return 0;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++)ans+=r[i];
    for(int j=1; j<=m; j++)ans+=c[j];

    printf("%d\n",ans);

    for(int i=1; i<=n; i++)
    {
        for(int k=1; k<=r[i]; k++)
        {
            printf("row %d\n",i);
        }
    }
    for(int j=1; j<=m; j++)
    {
        for(int k=1; k<=c[j]; k++)
        {
            printf("col %d\n",j);
        }
    }

    return 0;
}
