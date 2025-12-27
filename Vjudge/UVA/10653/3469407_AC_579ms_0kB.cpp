#include<bits/stdc++.h>
using namespace std;
#define mx 1005
int cell[mx][mx];
int vis[mx][mx];
int cost[mx][mx];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int row,col;
//pair<int,int>pii;
queue<int>Q;
int BFS(int sx, int sy, int dx, int dy)
{
    int k,tx,ty,u,v;
    vis[sx][sy]=1;
    cost[sx][sy]=0;
    Q.push(sx);
    Q.push(sy);

    while(!Q.empty())
    {
        //pii top=Q.front();
        u=Q.front();
        Q.pop();
        v=Q.front();
        Q.pop();

        for(k=0; k<4; k++)
        {
            tx = u+fx[k];
            ty = v+fy[k];

            if(tx==dx && ty==dy)
                return cost[u][v]+1;

            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                cost[tx][ty]=cost[u][v]+1;
                Q.push(tx);
                Q.push(ty);
            }
        }
    }
}
int main()
{
    int N,i,j,r,c,n,mncst,sx,sy,dx,dy,p;

    while(cin >> row >> col)
    {
        if(row==0 && col==0)
            break;

        cin >> N;

        for(i=0; i<N; i++)
        {
            cin >> r >> n;

            for(j=0; j<n; j++)
            {
                cin >> c;
                cell[r][c]=-1;
            }
        }

        cin >> sx >> sy;
        cin >> dx >> dy;

        mncst=BFS(sx,sy,dx,dy);
        cout << mncst << endl;;

        while(!Q.empty())
            Q.pop();

            memset(cell,0,sizeof(cell));
            memset(vis,0,sizeof(vis));
            //memset(cost,0,sizeof(cost));
    }

    return 0;
}
