#include<bits/stdc++.h>
using namespace std;
#define mx 200
vector<int>edge[mx];
int color[mx];
int use[mx];
queue<int>Q;
bool BFS()
{
    int u,v,i,sz;
    color[0]=1;
    Q.push(0);

    while(!Q.empty())
    {
        u=Q.front();
        use[u]=1;
        Q.pop();
        sz=edge[u].size();

        for(i=0; i<sz; i++)
        {
            v=edge[u][i];
            if(use[v]==0)//{
                Q.push(v);
                if(color[v]!=0)
                {
                    if(color[u]==color[v])
                        return false;
                    else
                        color[v]=3-color[u];

                }
                else
                {
                    color[v]=3-color[u];
                }
            //}
        }
    }

    return true;
}
int main()
{
    int N,E,i,n1,n2,src,flag;

    while(cin >> N && N)
    {
        memset(color,0,sizeof(color));
        memset(use,0,sizeof(use));
        cin >> E;
        for(i=0; i<E; i++){
            cin >> n1 >> n2;
            edge[n1].push_back(n2);
            edge[n2].push_back(n1);
        }

        if(BFS())
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;

        for(i=0;i<N;i++){
            edge[i].erase(edge[i].begin(),edge[i].end());
        }
        while(!Q.empty())
            Q.pop();
    }

    return 0;
}
