#include<bits/stdc++.h>
using namespace std;
#define Mx 100000   // Maximum node
vector<int>edge[Mx];
int indegree[Mx];
int outdegree[Mx];
int main()
{
    int N,E,n1,n2;

    cin >> N >> E;

    for(int i=1; i<=E; i++)
    {
        cin >> n1 >> n2;
        edge[n1].push_back(n2);
        indegree[n2]++;
        outdegree[n1]++;
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

    cout << endl;

    for(int i=1; i<=N;i++)
    {
        cout << indegree[i] << " " << outdegree[i] << endl;
    }

    return 0;
}
