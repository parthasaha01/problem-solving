#include<bits/stdc++.h>
using namespace std;
#define Mx 100000   // Maximum node
vector<int>edge[Mx];
vector<int>cost[Mx];
int main()
{
    int N,E,n1,n2;

    cin >> N >> E;

    for(int i=1; i<=E; i++)
    {
        cin >> n1 >> n2;
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
        cost[n1].push_back(1);
        cost[n2].push_back(1);
    }

    cout << endl;

    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<edge[i].size(); j++)
        {
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
