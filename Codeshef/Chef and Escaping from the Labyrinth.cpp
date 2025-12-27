#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int a[1002][1002];
int vis[1002][1002];
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};
int n,m;
void DFS(int i,int j,int v)
{
    dp[i][j]=v;
    vis[i][j]=1;
    if(v==0)return;

    for(int k=0; k<4; k++)
    {
        int tx = i+fx[k];
        int ty = j+fy[k];

        if(tx<1||tx>n||ty<0||ty>m)continue;
        if(a[tx][ty]==-1)continue;
        if(dp[tx][ty]<(v-1))
        {
            DFS(tx,ty,v-1);
        }
        else if(dp[tx][ty]==0 && vis[tx][ty]==0)
        {
            DFS(tx,ty,v-1);
        }

    }
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d%d",&n,&m);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&a[i][j]);
                dp[i][j] = a[i][j];
                vis[i][j]=0;
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(a[i][j]>0 && a[i][j]>=dp[i][j])
                {
                    DFS(i,j,a[i][j]);
                }
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(dp[i][j]<0)
                {
                    printf("B");
                }
                else if(dp[i][j]>0)
                {
                    printf("Y");
                }
                else if(dp[i][j]==0 && vis[i][j]==1)
                {
                    printf("Y");
                }
                else
                {
                    printf("N");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
