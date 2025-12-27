#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL)
string st[1005];
int n,m,k,sx,sy,dx,dy;
int fx[]= {-1,+0,+0,+1};
int fy[]= {+0,-1,+1,+0};
int s[1005][1005],rsm[1005][1005],csm[1005][1005],vis[1005][1005],cost[1005][1005];
struct data
{
    int x,y,v;
};
queue<data>qq;
int valid(int tx,int ty)
{
    if(tx>=1 && tx<=n && ty>=1 && ty<=m && s[tx][ty]==0)
    {
        return 1;
    }
    return 0;
}
int BFS()
{
    data nd;
    nd.x=sx; nd.y=sy; nd.v=0;
    vis[sx][sy]=1;
    cost[sx][sy]=0;
    qq.push(nd);

    //int ans = 1000000000;

    while(!qq.empty())
    {
        data u = qq.front();
        qq.pop();

        int x,y,v;
        x = u.x; y = u.y; v = u.v;

        //printf("x=%d y=%d v=%d\n",x,y,v);
        //getchar();

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
//                    int d;
//                    if(j==0)d = csm[x][y] - csm[tx-1][ty];
//                    if(j==1)d = rsm[x][y] - rsm[tx][ty-1];
//                    if(j==2)d = rsm[tx][ty] - rsm[x][y-1];
//                    if(j==3)d = csm[tx][ty] - csm[x-1][y];
//
//                    if(d>0)break;

                    //printf("j=%d i=%d x=%d y=%d tx=%d ty=%d d=%d v=%d\n",j,i,x,y,tx,ty,d,v);

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

                    //if(cost[tx][ty]<cost[x][y]+1)break
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
    for(int i=0; i<n; i++)
    {
        cin>>st[i];
    }

    cin>>sx>>sy>>dx>>dy;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(st[i][j]=='.')s[i+1][j+1]=0;
            else s[i+1][j+1]=1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            rsm[i][j] = rsm[i][j-1]+s[i][j];
        }
    }

    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=n; i++)
        {
            csm[i][j] = csm[i-1][j]+s[i][j];
        }
    }

//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            printf("%d",s[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            printf("%d",rsm[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            printf("%d",csm[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");


    if(sx==dx && sy==dy)
    {
        printf("0\n");
        return 0;
    }

    if(s[sx][sy]==1 || s[dx][dy]==1){
        printf("-1\n");
        return 0;
    }

    int ans = BFS();

    printf("%d\n",ans);

    return 0;
}
