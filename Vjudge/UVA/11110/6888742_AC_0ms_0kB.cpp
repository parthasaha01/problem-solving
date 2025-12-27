#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,0,0,1};
int fy[]={0,-1,1,0};
int n,vis[105][105],cell[105][105];
vector<pair<int,int> >V[105];

void RESET()
{
    memset(vis,false,sizeof(vis));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cell[i][j]=n;
        }
    }
    for(int i=1; i<=n; i++){
        V[i].clear();
    }
}

bool VALID(int tx, int ty)
{
    if(tx>0 && tx<=n && ty>0 && ty<=n && vis[tx][ty]==false){
        return true;
    }
    return false;
}
void dfs(int ux, int uy)
{
    vis[ux][uy]=true;

    for(int k=0; k<4; k++)
    {
        int tx=ux+fx[k];
        int ty=uy+fy[k];

        if(VALID(tx,ty)==true){
            if(cell[tx][ty]==cell[ux][uy]){
               dfs(tx,ty);
            }
        }
    }

    return;
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        RESET();

        for(int i=1; i<n; i++)
        {
            int u,v;
            char ch;

            while(1)
            {
                scanf("%d%d%c",&u,&v,&ch);
                cell[u][v]=i;

                if(ch=='\n'){
                    break;
                }
            }
            V[i].push_back({u,v});
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(cell[i][j]==n){
                   V[n].push_back({i,j});
                   goto label;
                }
            }
        }

        label:

        for(int i=1; i<=n; i++){
            int x,y;
            x=V[i][0].first;
            y=V[i][0].second;
            dfs(x,y);
        }

        bool flag=true;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(vis[i][j]==false){
                    flag=false;
                    break;
                }

            }
        }

        if(flag==true){
            printf("good\n");
        }
        else{
            printf("wrong\n");
        }
    }

    return 0;
}
