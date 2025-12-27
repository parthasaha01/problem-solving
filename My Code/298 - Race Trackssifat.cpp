///Accepted
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mx 31
int fx[] = {-1,0,1};
int vis[31][31][10][10];
int obs[31][31];
int n,m,t;
int ans;
int X1,X2,Y1,Y2;
void bfs()
{
    queue <int> Qx, Qy, Qvx, Qvy;
    Qx.push(X1);
    Qy.push(Y1);
    Qvx.push(0);
    Qvy.push(0);
    vis[X1][Y1][4][4]=1;
    while(!Qy.empty())
    {
        int px = Qx.front();
        int py = Qy.front();
        int vx = Qvx.front();
        int vy = Qvy.front();
        if(px == X2 && py == Y2)
        {
            ans = vis[px][py][vx+4][vy+4];
            return;
        }
        Qx.pop();
        Qvx.pop();
        Qy.pop();
        Qvy.pop();
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                int vx1 = vx+fx[i];
                int vy1 = vy+fx[j];
                if(vx1 <= 3 && vy1 <= 3 && vx1 >= -3 && vy1 >=-3)
                {
                    int qx = px+vx1;
                    int qy = py+vy1;
                    if(qx<n && qx>=0 && qy<m && qy >= 0 && !vis[qx][qy][vx1+4][vy1+4] && !obs[qx][qy])
                    {

                        vis[qx][qy][vx1+4][vy1+4] = vis[px][py][vx+4][vy+4] + 1;
                        Qx.push(qx);
                        Qy.push(qy);
                        Qvx.push(vx1);
                        Qvy.push(vy1);
                    }
                }
            }
        }
    }
}
int main()
{
    int TC;
    cin >> TC;
    while(TC--)
    {
        scanf("%d %d",&n,&m);
        memset(vis,0,sizeof(vis));
        memset(obs,0,sizeof(obs));
        scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
        scanf("%d",&t);
        ans = -1;

        for(int i=0; i<t; i++)
        {
            int ax1,ax2,ay1,ay2;
            scanf("%d %d %d %d",&ax1,&ax2,&ay1,&ay2);
            for(int i=ax1; i<=ax2; i++)
            {
                for(int j=ay1; j<=ay2; j++)
                {
                    obs[i][j] = 1;
                }
            }
        }
        bfs();
        if(ans==-1)
        {
            printf("No solution.\n");
        }
        else
        {
            printf("Optimal solution takes %d hops.\n",ans-1);
        }
    }
}
