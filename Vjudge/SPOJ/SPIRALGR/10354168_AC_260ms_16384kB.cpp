#include<bits/stdc++.h>
using namespace std;
int prime[40005],gr[205][205],ss[205][205];
int fx[]={-1,0,0,1};
int fy[]={0,-1,1,0};
int cost[205][205];
bool vis[205][205];
int sx,sy,dx,dy;
struct dt{
    int x,y;
}st[40005];
void sieve()
{
    for(int i=2; i<=40000; i++)prime[i]=1;
    for(int i=4; i<=40000; i+=2)prime[i]=0;

    for(int i=3; i<=200; i+=2){
        if(prime[i]==1){
            for(int j=i*i; j<=40000; j+=2*i){
                prime[j]=0;
            }
        }
    }
}
void ConstructGrid()
{
    int v=40000;

    for(int i=1; i<=100; i++)
    {
        for(int j=i; j<=201-i; j++)
        {
            gr[i][j] = v;
            if(prime[v]==1) ss[i][j]=0;
            else ss[i][j]=1;
            st[v].x=i; st[v].y=j;
            v--;
        }

        for(int x=i+1; x<=201-i; x++)
        {
            gr[x][201-i] = v;
            if(prime[v]==1) ss[x][201-i]=0;
            else ss[x][201-i]=1;
            st[v].x=x; st[v].y=201-i;
            v--;
        }

        for(int y=200-i; y>=i; y--)
        {
            gr[201-i][y] = v;
            if(prime[v]==1) ss[201-i][y]=0;
            else ss[201-i][y]=1;
            st[v].x=201-i; st[v].y=y;
            v--;
        }

        for(int x=200-i; x>=i+1; x--)
        {
            gr[x][i] = v;
            if(prime[v]==1) ss[x][i]=0;
            else ss[x][i]=1;
            st[v].x=x; st[v].y=i;
            v--;
        }
    }
}
bool VALID(int tx, int ty)
{
    if(tx>=1 && tx<=200 && ty>=1 && ty<=200 && ss[tx][ty]==1 && vis[tx][ty]==false){
        return true;
    }
    return false;
}
int BFS()
{
    for(int i=1; i<=200; i++){
        for(int j=1; j<=200; j++){
            vis[i][j]=false;
            cost[i][j]=999999999;
        }
    }

    queue< pair <int,int> >q;
    q.push({sx,sy});
    cost[sx][sy]=0;
    vis[sx][sy]=true;

    if(sx==dx&&sy==dy) return 0;

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

                if(tx==dx&&ty==dy) return cost[tx][ty];

                q.push({tx,ty});
                vis[tx][ty]=true;
            }
        }
    }

    return -1;
}
int main()
{
    sieve();
    ConstructGrid();

    int ks=0,u,v;
    while(scanf("%d%d",&u,&v)==2)
    {
        sx=st[u].x; sy=st[u].y;
        dx=st[v].x; dy=st[v].y;

        int ans = BFS();
        if(ans==-1)printf("Case %d: impossible\n",++ks,ans);
        else printf("Case %d: %d\n",++ks,ans);
    }
    return 0;
}
