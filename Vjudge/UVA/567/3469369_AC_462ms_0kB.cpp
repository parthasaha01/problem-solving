#include<bits/stdc++.h>
using namespace std;
#define mx 25
#define Inf 1000
vector<int>edge[mx];
queue<int>Q;
int cost[mx];
int BFS(int src, int des)
{
    /*for(int i=1; i<=20; i++)
    {
            int sz=edge[i].size();
            cout << i << ": ";
            for(int j=0;j<sz;j++)
                cout << edge[i][j] << " ";
            cout << endl;
    }
    for(int i=1; i<mx; i++)
        cout << cost[i] << " ";
    cout << endl;*/

    int u,v,i,sz;
    cost[src]=0;
    Q.push(src);

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        //cout << u << " ";
        if(u==des)
            return cost[u];
        sz=edge[u].size();
        for(i=0; i<sz; i++){
            v=edge[u][i];
            if(cost[v]>cost[u]+1){
                cost[v]=cost[u]+1;
                Q.push(v);
            }
        }
    }
    //cout << endl;
    return Inf;
}
int main()
{
    int T=1,n,n1,n2,i,j,u,v,N,Mncst,src,des;

    while(cin >> n)
    {
        for(i=0;i<n;i++){
            cin >> v;
            edge[1].push_back(v);
            edge[v].push_back(1);
        }
        for(u=2;u<=19;u++){
            cin >> n;
            for(i=0;i<n;i++){
                cin >> v;
                edge[u].push_back(v);
                edge[v].push_back(u);

            }
        }

        cin >> N;
        cout << "Test Set #" << T++ << endl;

        for(i=0;i<N; i++)
        {
            //memset(cost,Inf,sizeof(cost));
            for(j=0;j<=mx;j++)
                cost[j]=Inf;

            cin >> src >> des;
            Mncst=BFS(src,des);
            printf("%2d to %2d: %d\n",src,des,Mncst);

            while(!Q.empty())
            Q.pop();
        }
        
        cout << endl;

        for(i=0; i<mx; i++)
        {
            edge[i].erase(edge[i].begin(),edge[i].end());
        }
        /*while(!Q.empty())
            Q.pop();*/

    }

    return 0;
}
