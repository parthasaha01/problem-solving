#include<bits/stdc++.h>
using namespace std;
string cell[505];
int vis[505][505];
int ans[100005];
int r,c,q,cnt;
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};
bool valid(int tx,int ty)
{
    if(tx>=0&&tx<r&&ty>=0&&ty<c&&cell[tx][ty]!='#'&&vis[tx][ty]==0){
        return true;
    }
    return false;
}
void dfs(int ux,int uy,int g)
{
    //cout << ux << " " << uy << endl;
    if(cell[ux][uy]=='C'){
        cnt++;
    }
    vis[ux][uy]=g;

    for(int k=0; k<4; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(valid(tx,ty)){
            dfs(tx,ty,g);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d%d%d",&r,&c,&q);

        for(int i=0; i<r; i++){
            cin >> cell[i];
        }

        int gr=0;
        memset(vis,0,sizeof(vis));

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(cell[i][j]!='#'&&vis[i][j]==0){
                    cnt=0;
                    gr++;
                    dfs(i,j,gr);
                    //cout << "gr-" << gr << " " << cnt << endl<<endl;;
                    ans[gr]=cnt;
                }
            }
        }

        printf("Case %d:\n",ks);
        for(int i=0; i<q; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            int g=vis[x][y];
            printf("%d\n",ans[g]);
        }
    }

    return 0;
}
