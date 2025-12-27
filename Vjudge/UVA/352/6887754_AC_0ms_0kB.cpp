#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,-1,-1,0,0,1,1,1};
int fy[]={-1,0,1,-1,1,-1,0,1};
int n,vis[30][30];
string cell[30];
bool VALID(int tx, int ty)
{
    if(tx>=0 && tx<n && ty>=0 && ty<n && cell[tx][ty]=='1' && vis[tx][ty]==false){
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
    int kase=0;

    //freopen("input.txt","r",stdin);
    //freopen("input.txt","w",stdout);

    while(scanf("%d",&n)==1)
    {
        memset(vis,false,sizeof(vis));

        for(int i=0; i<n; i++){
            cin >> cell[i];
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(cell[i][j]=='1' && vis[i][j]==false){
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n",++kase,cnt);
    }

    return 0;
}
