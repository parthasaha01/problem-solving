#include<bits/stdc++.h>
using namespace std;
int r,c,d;
int mat[51][51];
int col[51][51];
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
bool flag;
void f(int x, int y, int cur)
{
//    printf("x-%d y-%d cur-%d\n",x,y,cur);
    if(x >= r || y >= c || x < 0 || y < 0 || mat[x][y]==cur)
    {
        return;
    }
    for(int i=0; i<4; i++)
    {
        int tx = x+fx[i];
        int ty = y+fy[i];
        if(tx >= r || ty >= c || tx < 0 || ty < 0)
        {
            continue;
        }
        int dif = abs(mat[x][y] - mat[tx][ty]);
        if(dif<=d && col[tx][ty]!=cur)
        {
            if(col[tx][ty]!=-1)
            {
                flag = 0;
            }
            for(int k=0; k<4; k++)
            {
                int px = tx+fx[k];
                int py = ty+fy[k];
                if(px >= r || py >= c || px < 0 || py < 0)
                {
                    continue;
                }
                if(col[px][py]!=-1 && col[px][py]!=cur)
                {
                    flag = 0;
                }
            }
            col[tx][ty] = cur;
            f(tx,ty,cur);
        }
    }
}
int main()
{
    int TC, ind = 0;
    scanf("%d",&TC);
    while(TC--){
    scanf("%d %d",&r,&c);
    memset(col, -1, sizeof(col));
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    int p,cnt =0;
    scanf("%d",&p);
    for(int i=0; i<p; i++)
    {
        flag = 1;
        int x,y;
        scanf("%d %d %d",&x,&y,&d);
        f(x-1,y-1,i);
        if(flag) cnt++;
    }
    printf("Case %d: %d\n",++ind,cnt);
    }
}

