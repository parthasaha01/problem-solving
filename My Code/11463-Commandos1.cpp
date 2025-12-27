#include<bits/stdc++.h>
using namespace std;
vector<int>v[105];
queue<int>q;
bool vis[105];
int level[105],slevel[105],dlevel[105];
void BFS(int s, int cost[])
{
    for(int i=0; i<105; i++){
        vis[i]=false;
    }
    cost[s]=0;
    q.push(s);
    vis[s]=true;

    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        int sz=v[x].size();
        for(int i=0; i<sz; i++){
            int y=v[x][i];
            if(vis[y]==false){
                cost[y]=cost[x]+1;
                vis[y]=true;
                q.push(y);
           }
        }
    }

    return;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n,r;
        scanf("%d",&n);
        scanf("%d",&r);

        for(int i=0; i<r; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int s,d;
        scanf("%d%d",&s,&d);

        BFS(s,slevel);
        BFS(d,dlevel);

        for(int i=0; i<n; i++){
            level[i]=slevel[i]+dlevel[i];
        }

        int maxx=0;
        for(int i=0; i<n; i++){
            maxx=max(maxx,level[i]);
        }

        printf("Case %d: %d\n",kase,maxx);

        for(int i=0; i<n; i++){
            v[i].clear();
        }
    }

    return 0;
}

