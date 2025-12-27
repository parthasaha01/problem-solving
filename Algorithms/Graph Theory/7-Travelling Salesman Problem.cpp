#include<bits/stdc++.h>
using namespace std;
bool vis[100];
int cost[100][100];
int node,src;
int TSP(int pos, int rem)
{
    if(rem==1){
        return cost[pos][src];
    }

    vis[pos]=true;
    int Mincost=9999;
    int cst;

    for(int i=1; i<=node; i++)
    {
        if(vis[i]==false)
        {
            cst = cost[pos][i] + TSP(i,rem-1);
            Mincost = min(Mincost,cst);
            vis[i] = false;
        }
    }

    return Mincost;
}
int main()
{
    int Mincost,weight;
    memset(vis,false,sizeof(vis));
    printf("Enter the Number of Node: ");
    cin >> node;
    printf("Enter the adjacency Matrix:\n");

    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            cin >> weight;
            cost[i][j]=weight;
            cost[j][i]=weight;
        }
    }
    printf("Enter the Source: ");
    cin >> src;
    Mincost = TSP(src,node);

    printf("Minimum Cost is: %d\n",Mincost);

    return 0;
}
