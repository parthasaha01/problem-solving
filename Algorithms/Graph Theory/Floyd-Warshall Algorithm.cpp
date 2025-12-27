#include<bits/stdc++.h>
using namespace std;
#define mx 100
#define INF 10000
int cost[mx][mx];

void FloydWarshall(int node)
{
    for(int k=1; k<=node; k++){
        for(int i=1; i<=node; i++){
            for(int j=1; j<=node; j++){
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }
}
int main()
{
    int node,edge,u,v,w;

    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;
    cout << "Enter the edges and weights:" << endl;

    for(int i=1;i<=node;i++){
        for(int j=1;j<=node;j++){
            cost[i][j]=INF;
        }
    }

    for(int i=0; i<edge; i++){
        cin >> u >> v >> w;
        cost[u][v]=w;
    }
    cout << endl;
    FloydWarshall(node);
    cout<< "enter sorce node and target node:"<<endl;
    while(cin >> u >> v)
    {
        if(cost[u][v]<INF)
            cout << "The Minimum cost from " << u << " to " << v << " is: " << cost[u][v] << endl << endl;
        else
            cout << "It is not possible to go from " << u << " to " << v << endl << endl;
    }

    return 0;
}
