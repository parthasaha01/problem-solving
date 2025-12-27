#include<bits/stdc++.h>
using namespace std;
#define mx 10005
bool hand[mx],vis[mx];
vector<int>v[mx];
int L[mx];
void DFS(int x)
{
    if(vis[x]==true){
        return;
    }
    vis[x]=true;

    for(int i=0; i<v[x].size(); i++){
        int y=v[x][i];
        DFS(y);
    }

    return;
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);

        int x,y;
        for(int i=0; i<m; i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            //v[y].push_back(x);
        }

        for(int i=0; i<l; i++){
            scanf("%d",&L[i]);
            DFS(L[i]);
            //hand[x]=true;
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
           if(vis[i]==true){
                ++cnt;
           }
        }

        printf("%d\n",cnt);

        for(int i=0; i<=n; i++){
            v[i].clear();
            vis[i]=false;
        }
    }

    return 0;
}

/*
10
7 6 2
1 2
2 3
3 4
4 5
5 1
6 7
4 6
*/
