#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,0,0,1};
int fy[]={0,-1,1,0};
int n,m,vis[20][20],cnt;
string cell[20];
bool VALID(int tx, int ty, char ch)
{
    if(tx>=0 && tx<n && ty>=0 && ty<m && cell[tx][ty]==ch && vis[tx][ty]==false){
        return true;
    }
    return false;
}
void dfs(int ux, int uy, char ch)
{
    vis[ux][uy]=true;
    cnt++;

    for(int k=0; k<4; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(VALID(tx,ty,ch)==true){
            dfs(tx,ty,ch);
        }
    }

    return;
}
int main()
{
    while(cin>>m>>n)
    {
        for(int i=0; i<n; i++){
            cin>>cell[i];
        }

        memset(vis,false,sizeof(vis));

        int maxx1=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==false&&cell[i][j]=='*'){
                    cnt=0;
                    dfs(i,j,'*');
                    if(cnt>maxx1){
                        maxx1=cnt;
                    }
                }
            }
        }


        int maxx2=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==false&&cell[i][j]=='.'){
                    cnt=0;
                    dfs(i,j,'.');
                    if(cnt>maxx2){
                        maxx2=cnt;
                    }
                }
            }
        }
        if(maxx1==maxx2)
        {
            printf("NOBODY LOSES.\n");
        }
        else if(maxx1>maxx2)
        {
            printf("TULTUL WINS THE ROUND.\n");
        }
        else
        {
            printf("TASFIA WINS THE ROUND.\n");
        }
    }

    return 0;
}
