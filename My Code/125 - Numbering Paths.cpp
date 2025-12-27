#include<bits/stdc++.h>
using namespace std;
vector<int>ed[105];
int n,m,way[105][105];
void floydWarshall()
{
    for(int k=0; k<=n; k++)
    {
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(way[i][k]!=0 && way[k][j]!=0)
                {
                    way[i][j] += way[i][k]*way[k][j];
                }
            }
        }
    }

    for(int k=0; k<=n; k++)
    {
        if(way[k][k]!=0) // have a cycle
        {
            for(int i=0; i<=n; i++)
            {
                for(int j=0; j<=n; j++)
                {
                    if(way[i][k]!=0 && way[k][j]!=0)
                    {
                        way[i][j] = -1;
                    }
                }
            }
        }
    }
}
int main()
{
    int ks=0;
    while(scanf("%d",&m)==1)
    {
        n=0;
        memset(way,0,sizeof(way));
        for(int i=1; i<=m; i++){
            int u,v; scanf("%d%d",&u,&v);
            n = max(n,max(u,v));
            ed[u].push_back(v);
            way[u][v]=1;
        }

        floydWarshall();

        printf("matrix for city %d\n",ks++);
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(j==0)printf("%d",way[i][j]);
                else printf(" %d",way[i][j]);
            }
            printf("\n");
        }

        for(int i=0; i<=n; i++)ed[i].clear();

    }
    return 0;
}
