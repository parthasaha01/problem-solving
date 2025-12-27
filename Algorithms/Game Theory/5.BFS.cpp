#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
#define Mx 1000
#define inf 10000
vector<int>edge[Mx];
int level[Mx];
int vis[Mx];
queue<int>Q;
int main()
{
    int N,E,n1,n2,i,j,k,sor,des,sz,d,n;

    cin >> N >> E;

    for(i=0; i<E; i++)
    {
        cin >> n1 >> n2;
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }

    cout << endl;

    while(cin >> sor >> des)
    {
        memset(level,inf,sizeof(level));
        memset(vis,0,sizeof(vis));
        Q.push(sor);
        level[sor]=0;
        while(!Q.empty())
        {
            n=Q.front();
            if(vis[n]==0)
            {
                sz=edge[n].size();
                for(i=0; i<sz; i++)
                {
                    d=edge[n][i];
                    if(level[n]+1 < level[d])
                        level[d]=level[n]+1;
                    Q.push(d);
                }
                vis[n]=1;
            }
            Q.pop();
        }

        cout << "Minimum step: " << level[des] << endl << endl;

    }


    return 0;
}
