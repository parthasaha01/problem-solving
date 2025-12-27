#include<bits/stdc++.h>
using namespace std;
#define mx 1005
#define INF 10000007
int cost[mx][mx],vis[mx][mx];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int row,col;
long d[mx][mx];
struct node
{
    int r,c;
    long w;

    node(int a, int b, long x)
    {
        r=a;
        c=b;
        w=x;
    }
    bool operator <(const node& p) const{
        return p.w < w;
    }
};
long Dijkstra()
{
    priority_queue<node>pq;

    d[0][0]=cost[0][0];
    pq.push(node(0,0,d[0][0]));
    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        int u=top.r;
        int v=top.c;
        int w=top.w;
        vis[u][v]=1;

        if(u==row-1 && v==col-1)
            return d[u][v];

        for(int k=0; k<4; k++)
        {
            int tx=u+fx[k];
            int ty=v+fy[k];

            //cout << tx << " " << ty << " " << cost[tx][ty] << " " << d[tx][ty] << endl;

            if(vis[tx][ty]==0 && tx>=0 && tx<row && ty>=0 && ty<col)
            {
                //cout << "p " << tx << " " << ty << " " << cost[tx][ty] << " " << d[tx][ty] << endl;
                if(d[u][v]+cost[tx][ty]<d[tx][ty])
                {
                    d[tx][ty]=d[u][v]+cost[tx][ty];
                    pq.push(node(tx,ty,d[tx][ty]));
                    //cout << tx << " " << ty << " " << cost[tx][ty] << " " << d[tx][ty] << endl;
                }

            }
        }
    }
    //cout << row-1 << " " << col-1 << " " << d[row-1][col-1] << endl;
    return d[row-1][col-1];
}
void CLEAR()
{
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            d[i][j]=INF;
            vis[i][j]=0;
        }
    }
    //memset(d,INF,sizeof(d));
    //memset(cost,INF,sizeof(cost));
    //memset(vis,0,sizeof(vis));
}
int main()
{
    int T,val;
    long mncst;

    cin >> T;

    while(T--)
    {
        //cin >> row >> col;
        scanf("%d %d",&row,&col);
        CLEAR();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                scanf("%d",&cost[i][j]);
            }
        }

        mncst=Dijkstra();
        printf("%ld\n",mncst);
    }

    return 0;
}
