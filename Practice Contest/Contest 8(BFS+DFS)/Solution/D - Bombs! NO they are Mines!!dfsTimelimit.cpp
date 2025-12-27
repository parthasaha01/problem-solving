#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,0,0,1};
int fy[]={0,-1,1,0};
int cell[1005][1005],cost[1005][1005];
bool vis[1005][1005];
int r,c,sx,sy,dx,dy;

void RESET()
{
    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){
            vis[i][j]=false;
            cost[i][j]=999999999;
            cell[i][j]=0;
        }
    }
}
bool VALID(int tx, int ty)
{
    if(tx>=0 && tx<r && ty>=0 && ty<c && cell[tx][ty]==0 && vis[tx][ty]==false){
        return true;
    }
    return false;
}
int bfs(int sx, int sy)
{

    queue< pair <int,int> >q;
    q.push({sx,sy});
    cost[sx][sy]=0;
    vis[sx][sy]=true;

    if(sx==dx&&sy==dy){
        return 0;
    }

    while(!q.empty())
    {
        pair<int,int>u;
        u=q.front();
        q.pop();
        int ux=u.first;
        int uy=u.second;

        for(int k=0; k<4; k++)
        {
            int tx=ux+fx[k];
            int ty=uy+fy[k];

            if(VALID(tx,ty)==true)
            {
                cost[tx][ty]=cost[ux][uy]+1;
                if(tx==dx&&ty==dy){
                    return cost[tx][ty];
                }
                q.push({tx,ty});
                vis[tx][ty]=true;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&r,&c))
    {
        if(r==0&&c==0){
            break;
        }

        RESET();

        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            int u;
            scanf("%d",&u);
            int l;
            scanf("%d",&l);

            for(int i=0; i<l; i++)
            {
                int v;
                scanf("%d",&v);
                cell[u][v]=1;
            }
        }

        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
        int res=bfs(sx,sy);

        printf("%d\n",res);
    }

    return 0;
}

