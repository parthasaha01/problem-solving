#include<bits/stdc++.h>
using namespace std;
string cell[25];
int cnt,W,H;
bool vis[25][25];
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};
bool valid(int tx, int ty)
{
    if(tx<0||tx>=H||ty<0||ty>=W||cell[tx][ty]!='.'||vis[tx][ty]==true){
        return false;
    }
    return true;
}
void DFS(int sx, int sy)
{
    vis[sx][sy]=true;
    cnt++;

    for(int k=0; k<4; k++)
    {
        int tx=sx+fx[k];
        int ty=sy+fy[k];

        if(valid(tx,ty)){
            DFS(tx,ty);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%d%d",&W,&H);

        for(int i=0; i<H; i++){
            cin>>cell[i];
        }

        int sx,sy;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(cell[i][j]=='@'){
                    sx=i;
                    sy=j;
                    goto label;
                }
            }
        }

        label:
        memset(vis,false,sizeof(vis));
        cnt=0;
        DFS(sx,sy);

        printf("Case %d: %d\n",kase,cnt);
    }

    return 0;
}
