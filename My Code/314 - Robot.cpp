#include<bits/stdc++.h>
using namespace std;
int m,n,sx,sy,dx,dy;
struct dt
{
    int pos[55][55],dir;
} st;
int main()
{
    while(scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0)
        {
            break;
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&flag[i][j]);

                if(flag[i][j]==1)
                {
                    flag[i-1][j]=1;
                    flag[i-1][j-1]=1;
                    flag[i][j-1]=1;
                }
            }
        }

        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
        string sdir;
        cin >> sdir;

        int time=BFS(sx,sy,dx,dy)
    }

    return 0;
}
