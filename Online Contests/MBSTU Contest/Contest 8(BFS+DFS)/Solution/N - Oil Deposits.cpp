#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,-1,-1,0,0,1,1,1};
int fy[]={-1,0,1,-1,1,-1,0,1};
int m,n,vis[105][105];
string cell[105];
bool VALID(int tx, int ty)
{
    if(tx>=0 && tx<m && ty>=0 && ty<n && cell[tx][ty]=='@' && vis[tx][ty]==false){
        return true;
    }
    return false;
}
void dfs(int ux, int uy)
{
    vis[ux][uy]=true;

    for(int k=0; k<8; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(VALID(tx,ty)==true){
            dfs(tx,ty);
        }
    }

    return;
}
int main()
{

    while(scanf("%d%d",&m,&n))
    {
        if(m==0){
            break;
        }

        memset(vis,false,sizeof(vis));

        for(int i=0; i<m; i++){
            cin >> cell[i];
        }

        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(cell[i][j]=='@' && vis[i][j]==false){
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}

