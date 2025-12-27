#include<bits/stdc++.h>
using namespace std;
struct dt
{
    int ka,va;
}r[5005],c[5005];
int main()
{
    int n,m,k;

    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        int cell[n+5][m+5];

        memset(cell,0,sizeof(cell));

        for(int i=0; i<=n; i++)
        {
            r[i].ka=0;
            r[i].va=0;
        }
        for(int i=0;i<=m; i++)
        {
            c[i].ka=0;
            c[i].va=0;
        }

        for(int i=1; i<=k; i++)
        {
            int t,p,a;
            scanf("%d%d%d",&t,&p,&a);

            if(t==1)
            {
                r[p].ka=i;
                r[p].va=a;
            }
            else
            {
                c[p].ka=i;
                c[p].va=a;
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(r[i].ka>c[j].ka)
                {
                    cell[i][j]=r[i].va;
                }
                else if(r[i].ka<c[j].ka)
                {
                    cell[i][j]=c[j].va;
                }

            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(j<m){
                    printf("%d ",cell[i][j]);
                }
                else{
                    printf("%d\n",cell[i][j]);
                }
            }
        }
    }

    return 0;
}
