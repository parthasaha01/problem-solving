#include<bits/stdc++.h>
using namespace std;
int n,cnt,total;
int vis[105],cost[105][105];
vector<int>ed[105];
void RESET()
{
    for(int i=0; i<=n; i++){
        ed[i].clear();
        vis[i]=false;
    }
}
int DFS(int u)
{
    vis[u]=true;
    for(int i=0; i<ed[u].size(); i++){
        int v=ed[u][i];
        if(vis[v]==false){
            cnt+=cost[u][v];
            DFS(v);
        }
    }


}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        RESET();

        scanf("%d",&n);
        total=0;

        for(int i=0; i<n; i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            ed[x].push_back(y);
            ed[y].push_back(x);
            cost[x][y]=0;
            total+=c;
            cost[y][x]=c;
        }

        cnt=0;
        DFS(1);
        int s2=ed[1][1];
        cnt+=cost[s2][1];
        int res=min(cnt,total-cnt);

        printf("Case %d: %d\n",kase,res);
    }

    return 0;
}