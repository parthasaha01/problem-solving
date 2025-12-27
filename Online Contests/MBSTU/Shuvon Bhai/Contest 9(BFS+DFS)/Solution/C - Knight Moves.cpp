#include<bits/stdc++.h>
using namespace std;
#define mx 10
int vis[mx][mx];
int cost[mx][mx];
int fx[]={2,2,1,1,-1,-1,-2,-2};
int fy[]={-1,1,-2,2,-2,2,-1,1};
queue<int>Q;
bool VALID(int tx, int ty)
{
    if(vis[tx][ty]==1 || tx<1 || tx>8 || ty<1 || ty>8)
        return false;
    else
        return true;
}
int BFS(int sx, int sy, int dx, int dy)
{
    while(!Q.empty())
        Q.pop();

    memset(vis,0,sizeof(vis));
    memset(cost,0,sizeof(cost));

    int u,v,k,tx,ty;

    vis[sx][sy]=1;
    cost[sx][sy]=0;

    Q.push(sx);
    Q.push(sy);

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        v=Q.front();
        Q.pop();

        for(k=0; k<8; k++)
        {
            tx=u+fx[k];
            ty=v+fy[k];

            if(VALID(tx,ty)==true)
            {
                vis[tx][ty]=1;
                cost[tx][ty]=cost[u][v]+1;
                Q.push(tx);
                Q.push(ty);
            }

            if(tx==dx && ty==dy)
                return cost[tx][ty];
        }
    }

    return cost[sx][sy];
}
int main()
{
    char ys,yd;
    int sx,sy,dx,dy,Min;

    while(cin >> ys >> sx >> yd >> dx)
    {
        sy=ys-'a'+1;
        dy=yd-'a'+1;

        Min=BFS(sx,sy,dx,dy);

        cout << "To get from " << ys << sx << " to " << yd << dx << " takes " << Min << " knight moves." << endl;
    }

    return 0;
}
