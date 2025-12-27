#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,0,0,1};
int fy[]={0,-1,1,0};
int w,h,cnt;
string cell[55];
int vis[55][55];
vector<int>V;
void dfs1(int,int);
void dfs2(int,int);
bool VALID(int tx, int ty)
{
    if(tx>=0 && tx<h && ty>=0 && ty<w && vis[tx][ty]==false){
        return true;
    }
    return false;
}
void dfs2(int ux, int uy)
{
    vis[ux][uy]=true;
    for(int k=0; k<4; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(VALID(tx,ty)==true){
            if(cell[tx][ty]=='X'){
                dfs2(tx,ty);
            }
            else if(cell[tx][ty]=='*'){
                dfs1(tx,ty);
            }
        }
    }
}
void dfs1(int ux, int uy)
{
    vis[ux][uy]=true;

    for(int k=0; k<4; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(VALID(tx,ty)==true){

            if(cell[tx][ty]=='*')
            {
                dfs1(tx,ty);
            }
            else if(cell[tx][ty]=='X')
            {
                cnt++;
                dfs2(tx,ty);
            }
        }
    }

    return;
}
int main()
{
    int kase=0;

    while(scanf("%d%d",&w,&h))
    {
        if(w==0&&h==0){
            break;
        }

        memset(vis,false,sizeof(vis));

        for(int i=0; i<h; i++){
            cin >> cell[i];
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(vis[i][j]==false && cell[i][j]=='*')
                {
                    cnt=0;
                    dfs1(i,j);
                    V.push_back(cnt);
                }
            }
        }

        sort(V.begin(),V.end());

        printf("Throw %d\n",++kase);

        for(int i=0; i<V.size(); i++){
            if(i==V.size()-1){
                printf("%d\n",V[i]);
            }
            else{
                printf("%d ",V[i]);
            }
        }
        printf("\n");
        V.clear();
    }

    return 0;
}
/*
30 15
..............................
..............................
...............*..............
...*****......****............
...*X***.....**X***...........
...*****....***X**............
...***X*.....****.............
...*****.......*..............
..............................
........***........******.....
.......**X****.....*X**X*.....
......*******......******.....
.....****X**.......*X**X*.....
........***........******.....
..............................
10 6
..........
.XXX......
....XXX...
.......XXX
....XXX...
*X*X......
6 6
XXXXX*
.....X
.....X
.....X
.....X
.....X
6 6
XXXXX.
.....X
.....X
.....X
.....X
.....X
6 6
XXXXX.
....*X
.....X
.....X
.....X
.....X

*/
