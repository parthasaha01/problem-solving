#include<bits/stdc++.h>
using namespace std;
int vis[55][55],par[2505],cost[2505][2505],r;
vector< pair<int,int> >gr[2505];
string ss[55];
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};

bool valid(int tx,int ty)
{
    if(tx>=0&&tx<r&&ty>=0&&ty<r&&ss[tx][ty]=='*'&&vis[tx][ty]==0) return true;
    else return false;
}
void dfs(int sx,int sy,int id)
{
    vis[sx][sy]=id;
    gr[id].push_back(make_pair(sx,sy));

    for(int k=0; k<4; k++){
        int tx = sx+fx[k];
        int ty = sy+fy[k];
        if(valid(tx,ty)) dfs(tx,ty,id);
    }
}
int bfs(int sx,int sy)
{

}
struct edge
{
    int u,v,w;
    edge(int a, int b, int c){
        u=a;v=b;w=c;
    }
    bool operator < (const edge& p) const{
        return p.w < w;
    }
};

priority_queue<edge>pq;

int findparent(int x)
{
    if(par[x]==x) return x;
    else return par[x]=findparent(par[x]);
}

int kruskalMST(int node)
{
    for(int i=1; i<=node; i++) par[i]=i;
    int sum=0;
    for(int i=1; i<=node-1; i++)
    {
        label:
        edge top = pq.top();
        pq.pop();

        int parU = findparent(top.u);
        int parV = findparent(top.v);

        if(parU==parV) goto label;
        else{
            par[parU]=parV;
            sum+=top.w;
        }
    }

    while(!pq.empty())pq.pop();
    return sum;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&r);

        for(int i=0; i<r; i++) cin>>ss[i];

        int id = 0;
        memset(vis,0,sizeof(vis));

        for(int i=0; i<r; i++){
            for(int j=0; j<r; j++){
                if(vis[i][j]==0 && ss[i][j]=='*'){
                    dfs(i,j,++id);
                }
            }
        }

        for(int i=1; i<=id; i++)
        {
            for(int j=i+1; j<=id; j++)
            {
                int mn = 1000000000;
                for(int x=0; x<gr[i].size(); x++)
                {
                    int sx = gr[i][x].first;
                    int sy = gr[i][x].second;

                    for(int y=0; y<gr[j].size(); y++)
                    {
                        int dx = gr[j][y].first;
                        int dy = gr[j][y].second;
                        int dd = abs(sx-dx)+abs(sy-dy);
                            mn = min(mn,dd);
                    }
                }
                pq.push(edge(i,j,mn));
            }
        }

        int ans = kruskalMST(id);
        printf("%d\n",ans);

        for(int i=0; i<=id; i++)gr[i].clear();
    }

    return 0;
}

/*
20

3
*..
.*.
*.*

3
..*
.**
..*

3
*..
..*
*..

5
.**..
.*...
...**
*...*
**...

10
.........*
..***...**
......****
..........
..*.....**
.....**.*.
******..**
..........
*******...
**********

11
****.......
.**........
*****......
*........**
.....*****.
....**.....
...........
...........
...........
...........
...........

3
..*
.*.
..*

*/

