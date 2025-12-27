#include<bits/stdc++.h>
using namespace std;
char cell[55][55];
int vis[55][55];
int r,c,q,cnt,k;
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};
struct dt
{
    int x,y,g,v;
}st[3005];
bool cmp(dt a,dt b){
    return a.v<b.v;
}
bool valid(int tx,int ty,int g)
{
    if(tx>=0&&tx<r&&ty>=0&&ty<c&&cell[tx][ty]=='.'&&vis[tx][ty]==g){
        return true;
    }
    return false;
}
void dfs1(int ux,int uy)
{
    vis[ux][uy]=-1;
    for(int k=0; k<4; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(valid(tx,ty,0)){
            dfs1(tx,ty);
        }
    }
}
void dfs2(int ux,int uy,int g)
{
    if(cell[ux][uy]=='.'){
        cnt++;
    }
    vis[ux][uy]=g;

    for(int k=0; k<4; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(valid(tx,ty,0)){
            dfs2(tx,ty,g);
        }
    }
}
void dfs3(int ux,int uy,int g)
{
    cell[ux][uy]='*';

    for(int k=0; k<4; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(valid(tx,ty,g)){
            dfs2(tx,ty,g);
        }
    }
}
int main()
{
    while(scanf("%d%d%d\n",&r,&c,&k)==3)
    {
        for(int i=0; i<r; i++){
            scanf("%s",cell[i]);
        }

        memset(vis,0,sizeof(vis));

        for(int i=0; i<r; i++){
            if(cell[i][0]=='.'&&vis[i][0]==0){
                dfs1(i,0);
            }
            if(cell[i][c-1]=='.'&&vis[i][c-1]==0){
                dfs1(i,c-1);
            }
        }
        for(int j=0; j<c; j++){
            if(cell[0][j]=='.'&&vis[0][j]==0){
                dfs1(0,j);
            }
            if(cell[r-1][j]=='.'&&vis[r-1][j]==0){
                dfs1(r-1,j);
            }
        }

        int gr=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(cell[i][j]=='.'&&vis[i][j]==0){
                    st[gr].x=i;
                    st[gr].y=j;
                    cnt=0;
                    dfs2(i,j,gr+1);
                    st[gr].v=cnt;
                    st[gr].g=gr+1;
                    gr++;
                }
            }
        }

        sort(st,st+gr,cmp);

        printf("gr=%d\n",gr);

        for(int i=0; i<gr; i++){
            printf("g=%d: x=%d y=%d v=%d\n",gr+1,st[i].x,st[i].y,st[i].v);
        }

        int ans=0;
        for(int i=0; i<abs(gr-k); i++){

            ans+=st[i].v;
            int x=st[i].x;
            int y=st[i].y;
            int g=st[i].g;
            printf("x=%d, y=%d i=%d\n   ",x,y,i);
            dfs3(x,y,g);
        }

        printf("%d\n",ans);
        for(int i=0; i<r; i++){
            printf("%s\n",cell[i]);
        }
    }

    return 0;
}
