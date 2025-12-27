#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,0,0,1};
int fy[]={0,-1,1,0};
int cost[25][25];
string cell[25];
bool vis[25][25];
int r,c;

void RESET()
{
    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){
            vis[i][j]=false;
            cost[i][j]=999999999;
        }
    }
}
bool VALID(int tx, int ty)
{
    if(tx>0 && tx<r-1 && ty>0 && ty<c-1 && cell[tx][ty]!='m' && cell[tx][ty]!='#' && vis[tx][ty]==false){
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

    int cnt=0;

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

                if(cell[tx][ty]=='a' || cell[tx][ty]=='b' || cell[tx][ty]=='c'){
                    cnt++;
                    if(cnt==3){
                        return cost[tx][ty];
                    }
                }
                q.push({tx,ty});
                vis[tx][ty]=true;
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%d%d",&r,&c);

        RESET();

        for(int i=0; i<r; i++)
        {
            cin >> cell[i];
        }
        int sx,sy;

        for(int i=1; i<r-1; i++){
            for(int j=1; j<c-1; j++){
                if(cell[i][j]=='h'){
                    sx=i;
                    sy=j;
                    goto label;
                }

            }
        }

        label:
        int res=bfs(sx,sy);

        printf("Case %d: %d\n",kase,res);
    }

    return 0;
}

