#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL)
string st[1005];
int n,m,k,sx,sy,dx,dy;
int fx[]= {-1,+0,+0,+1};
int fy[]= {+0,-1,+1,+0};
int vis[1005][1005],cost[1005][1005];
struct data{
    int x,y,v;
};
queue<data>qq;
int valid(int tx,int ty)
{
    if(tx>=0&&tx<n&&ty>=0&&ty<m&&st[tx][ty]=='.') return 1;
    return 0;
}
int BFS()
{
    data nd;
    nd.x=sx; nd.y=sy; nd.v=0;
    vis[sx][sy]=1;
    cost[sx][sy]=0;
    qq.push(nd);

    while(!qq.empty())
    {
        data u = qq.front();
        qq.pop();

        int x,y,v;
        x = u.x; y = u.y; v = u.v;

        if(x==dx && y == dy) return v;

        for(int j=0; j<4; j++)
        {
            for(int i=1; i<=k; i++)
            {
                int tx,ty;
                tx = (i*fx[j]) + x;
                ty = (i*fy[j]) + y;

                if(valid(tx,ty)==1)
                {
                    if(vis[tx][ty]==0)
                    {
                        data tm;
                        tm.x = tx;
                        tm.y = ty;
                        tm.v = v+1;
                        cost[tx][ty]=v+1;
                        vis[tx][ty]=1;
                        qq.push(tm);
                    }
                    else
                    {
                        if(cost[tx][ty]<cost[x][y]+1)break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    return -1;
}
int main()
{
    IO;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++) cin>>st[i];

    cin>>sx>>sy>>dx>>dy;
    sx--; sy--; dx--; dy--;

    int ans = BFS();

    printf("%d\n",ans);

    return 0;
}

