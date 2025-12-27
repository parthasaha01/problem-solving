#include<bits/stdc++.h>
using namespace std;
int n,e,flag,vis[205],chk[205][205];
vector<int>ed[205];
queue<int>q;
int BFS(int s)
{
    int c0=0,c1=0;
    vis[s]=0;
    c0++;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        int clr = 1-vis[u];
        q.pop();
        for(int i=0; i<ed[u].size(); i++)
        {
            int v = ed[u][i];
            if(vis[v]==-1){
                vis[v]=clr;
                if(clr==0)c0++;
                if(clr==1)c1++;
                q.push(v);
            }
            else{
                if(vis[v]!=clr){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0)break;
    }

    return min(max(1,c0),max(1,c1));
}
int main()
{
    int tt; scanf("%d",&tt);
    while(tt--)
    {
        memset(vis,-1,sizeof(vis));
        memset(chk,0,sizeof(chk));

        scanf("%d%d",&n,&e);
        for(int i=0; i<e; i++){
            int u,v; scanf("%d%d",&u,&v);
            if(chk[u][v]==1||chk[v][u]==1)continue;
            if(u==v)continue;
            ed[u].push_back(v);
            ed[v].push_back(u);
            chk[u][v]=chk[v][u]=1;
        }
        int ans = 0;
        flag = 1;

        for(int i=0; i<n; i++)
        {
            if(vis[i]==-1) ans+=BFS(i);

            if(flag==0){
                ans=-1;
                break;
            }
        }

        printf("%d\n",ans);

        for(int i=0; i<n; i++)ed[i].clear();
        while(!q.empty())q.pop();
    }
    return 0;
}
