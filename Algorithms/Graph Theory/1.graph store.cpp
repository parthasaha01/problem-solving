#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node,i,j,cost;
    int matrix[100][100];

    cout << "Number of Node: ";
    cin >> node;

    for(i=1; i<=node; i++){
        for(j=1; j<=node; j++){
            cin >> matrix[i][j];
        }
    }

    cout << endl;

    for(i=1; i<=node; i++){
        for(j=1; j<=node; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
if node=3; 1-2(cost 5), 2-3(cost 8), 3-1(cost 3); & the graph is bidirectional
0 5 3
5 0 8
3 8 0
*/
