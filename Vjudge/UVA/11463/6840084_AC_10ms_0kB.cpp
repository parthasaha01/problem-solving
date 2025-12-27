#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n,r;
        scanf("%d",&n);
        scanf("%d",&r);

        int cost[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cost[i][j]=99999;
            }
        }
        for(int i=0; i<n; i++){
            cost[i][i]=0;
        }

        for(int i=0; i<r; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            cost[u][v]=1;
            cost[v][u]=1;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }

        int s,d;
        scanf("%d%d",&s,&d);

        int maxx=0;
        for(int i=0; i<n; i++){
            maxx=max(maxx,cost[s][i]+cost[i][d]);
        }

        printf("Case %d: %d\n",kase,maxx);
    }

    return 0;
}
