#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge,k,node1,node2,cost;
    int matrix[100][100];

    cin >> node >> edge;

    for(k=1; k<=edge; k++)
    {
        cin >> node1 >> node2 >> cost;
        matrix[node1][node2]=cost;
        matrix[node2][node1]=cost;
    }

    cout << endl;

    for(node1=1; node1<=node; node1++){
        for(node2=1; node2<=node; node2++){
            cout << matrix[node1][node2] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
if node=3; 1-2(cost 5), 2-3(cost 8), 3-1(cost 3); & the graph is bidirectional
3 3 // 3 node & 3 edge
1 2 5 //node1 node2 cost
2 3 8
1 3 3
*/

