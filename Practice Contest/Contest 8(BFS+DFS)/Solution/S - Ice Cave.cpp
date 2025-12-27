#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,0,0,1};
int fy[]={0,-1,1,0};
int n,m,sx,sy,dx,dy;
string cell[505];
bool vis[505][505],flag;
bool valid(int tx, int ty)
{
    if(tx>=0&&tx<n&&ty>=0&&ty<m&&vis[tx][ty]==false&&cell[tx][ty]=='.'){
        return true;
    }
    return false;
}
void DFS(int ux, int uy)
{
    if(flag==true){
        return;
    }

    vis[ux][uy]=true;
    cell[ux][uy]='X';

    for(int k=0; k<4; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(tx==dx&&ty==dy && vis[tx][ty]==true){
            flag=true;
        }
        else if(valid(tx,ty)==true){
            DFS(tx,ty);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(vis,false,sizeof(vis));

        for(int i=0; i<n; i++){
            cin >> cell[i];
        }

        scanf("%d%d",&sx,&sy);
        scanf("%d%d",&dx,&dy);

        sx--, sy--, dx--, dy--;

        flag=false;
        if(cell[dx][dy]=='X'){
            vis[dx][dy]=true;
        }
        DFS(sx,sy);

        if(flag==true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}
