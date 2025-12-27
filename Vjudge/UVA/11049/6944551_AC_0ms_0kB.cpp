#include<bits/stdc++.h>
using namespace std;

int fx[]={-1,1,0,0};  // NSWE
int fy[]={0,0,-1,1};
char dir[]={'N','S','W','E'};
int cost[10][10];
bool vis[10][10];
char res[10][10];
char ans[1000];
int r,c,sx,sy,dx,dy;
vector<int>ver;
vector<int>hor;
struct node
{
    int x,y;
}par[10][10];

void RESET()
{
    ver.clear();
    hor.clear();
    for(int i=0; i<=6; i++){
        for(int j=0; j<=6; j++){
            vis[i][j]=false;
            cost[i][j]=999999999;
        }
    }
}
bool vertical(int ux,int uy,int vx,int vy, char ch)
{
    int sz=ver.size();
    int cnt=sz/4;
    int k=0;
    //printf("vertical sz=%d cnt=%d ux=%d uy=%d vx=%d vy=%d ch=%c\n",sz,cnt,ux,uy,vx,vy,ch);
    for(int i=0; i<cnt; i++)
    {
        int ax,ay,bx,by;
        ax=ver[k++];
        ay=ver[k++];
        bx=ver[k++];
        by=ver[k++];

        if(ch=='W')
        {
            if(ux>ax&&ux<=bx){
                if(vy==ay){
                    return false;
                }
            }
        }
        else
        {
            if(ux>ax&&ux<=bx){
                if(uy==ay){
                    return false;
                }
            }
        }
    }

    return true;
}
bool horizontal(int ux,int uy,int vx,int vy, char ch)
{
    int sz=hor.size();
    int cnt=sz/4;
    int k=0;

    //printf("horizontal sz=%d cnt=%d ux=%d uy=%d vx=%d vy=%d ch=%c\n",sz,cnt,ux,uy,vx,vy,ch);

    for(int i=0; i<cnt; i++)
    {
        int ax,ay,bx,by;
        ax=hor[k++];
        ay=hor[k++];
        bx=hor[k++];
        by=hor[k++];

        if(ch=='N')
        {
            if(uy>ay&&uy<=by)
            {
                if(vx==ax){
                    return false;
                }
            }
        }
        else
        {
            if(uy>ay&&uy<=by)
            {
                if(ux==ax){
                    return false;
                }
            }
        }
    }

    return true;
}
bool VALID(int tx, int ty)
{
    if(tx>0 && tx<=6 && ty>0 && ty<=6 && vis[tx][ty]==false){
        return true;
    }
    return false;
}
int bfs()
{

    queue< pair <int,int> >q;
    q.push({sx,sy});
    cost[sx][sy]=0;
    vis[sx][sy]=true;

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

            if(VALID(tx,ty)==false){
                continue;
            }

            if(k<2){    //horizontal
                if(horizontal(ux,uy,tx,ty,dir[k])==false){
                    continue;
                }
            }
            else{   //vertical
                if(vertical(ux,uy,tx,ty,dir[k])==false){
                    continue;
                }
            }
            cost[tx][ty]=cost[ux][uy]+1;
            //printf("k=%d tx=%d ty=%d ux=%d uy=%d cost=%d dir=%c\n",k,tx,ty,ux,uy,cost[tx][ty],dir[k]);
            res[tx][ty]=dir[k];
            par[tx][ty].x=ux;
            par[tx][ty].y=uy;
            /*if(tx==dx&&ty==dy){
                return cost[tx][ty];
            }*/
            q.push({tx,ty});
            vis[tx][ty]=true;
        }
    }
}
int main()
{
    while(scanf("%d%d",&sy,&sx))
    {
        if(!sx&&!sy) break;

        RESET();

        scanf("%d%d",&dy,&dx);

        for(int i=0; i<3; i++)
        {
            int ax,ay,bx,by;
            scanf("%d%d%d%d",&ay,&ax,&by,&bx);
            if(ay==by){ //vertical
                if(ax>bx){
                    swap(ax,bx);
                }
                ver.push_back(ax);
                ver.push_back(ay);
                ver.push_back(bx);
                ver.push_back(by);
            }
            else if(ax==bx){    //horizontal
                if(ay>by){
                    swap(ay,by);
                }
                hor.push_back(ax);
                hor.push_back(ay);
                hor.push_back(bx);
                hor.push_back(by);
            }

        }

        bfs();

        /*for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++){
                printf("(%d,%d) ",par[i][j].x,par[i][j].y);
            }
            printf("\n");
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++){
                printf("%c ",res[i][j]);
            }
            printf("\n");
        }*/


        int len=cost[dx][dy];
        int px,py;
        px=dx;
        py=dy;
        for(int i=len-1; i>=0; i--)
        {
            //printf("%c %d %d\n",res[px][py],px,py);
            ans[i]=res[px][py];
            //printf("%c\n",ans[i]);
            int qx=par[px][py].x;
            int qy=par[px][py].y;
            px=qx;
            py=qy;
        }
        //printf("\n");

        //printf("%d %d\n",par[6][4].x, par[6][4].y);

        ans[len]='\0';
        puts(ans);

        /*for(int i=0; i<len; i++){
            printf("%c",ans[i]);
        }
        printf("\n");
        printf("%d\n",cost[dx][dy]);*/
    }

    return 0;
}