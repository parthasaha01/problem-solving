#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define INF 1000000000
bool vis[105][mx];
int cost[105][mx];
int a[105];
int fx[]={-1,1,0,0};
int fy[]={0,0,1,-1};
queue<int>q;
int BFS(int sx, int sy, int dx, int dy, int n)
{
    while(!q.empty())
        q.pop();

    memset(vis,false,sizeof(vis));
    //memset(cost,INF,sizeof(cost));
    for(int i=0; i<105; i++){
        for(int j=0; j<mx; j++){
            cost[i][j]=INF;
        }
    }

    vis[sx][sy] = true;
    cost[sx][sy] = 0;

    q.push(sx);
    q.push(sy);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int v=q.front();
        q.pop();

        for(int k=0; k<4; k++)
        {
            int tx=u+fx[k];
            int ty=v+fy[k];

            //printf("u=%d v=%d k=%d tx=%d ty=%d\n",u,v,k,tx,ty);

            if(k==0){
                if(tx<0){
                    continue;
                }
                if(ty>a[tx]){
                    ty=a[tx];
                }
            }
            else if(k==1){
                if(tx>n-1){
                    continue;
                }
                if(ty>a[tx]){
                    ty=a[tx];
                }
            }
            else if(k==2){
                if(ty>a[tx]){
                    continue;
                }
            }
            else{
                if(ty<0){
                    continue;
                }
            }

            //printf("partha1\n");
            //printf("u=%d v=%d k=%d tx=%d ty=%d\n",u,v,k,tx,ty);

            if(vis[tx][ty]==false)
            {
                //printf("partha2\n");
                vis[tx][ty]=true;
                cost[tx][ty]=cost[u][v]+1;
                q.push(tx);
                q.push(ty);
            }

            if(tx==dx && ty==dy){
                return cost[tx][ty];
            }
            //printf("partha2\n");
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;

    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        int sx,sy,dx,dy;
        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);

        int mincst = BFS(sx-1,sy-1,dx-1,dy-1,n);

        printf("%d\n",mincst);
    }

    return 0;
}
