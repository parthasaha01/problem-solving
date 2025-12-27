#include<bits/stdc++.h>
using namespace std;
#define mx 27
int vis[mx][mx];
int fx[]={-1,-1,-1,0,0,1,1,1};
int fy[]={-1,0,1,-1,1,-1,0,1};
queue<int>Q;
string grid[mx];
int N;
bool VALID(int tx, int ty)
{
    if(vis[tx][ty]==1 || tx<0 || tx>N-1 || ty<0 || ty>N-1)
        return false;
    else
        return true;
}
int BFS()
{
    memset(vis,0,sizeof(vis));

    int i,j,u,v,k,tx,ty,cnt=0;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(vis[i][j]==1)
                continue;

            vis[i][j]=1;

            if(grid[i][j]=='1')
            {
                Q.push(i);
                Q.push(j);

                while(!Q.empty())
                {
                    u=Q.front();
                    Q.pop();
                    v=Q.front();
                    Q.pop();
                    for(k=0; k<8; k++)
                    {
                        tx=u+fx[k];
                        ty=v+fy[k];

                        if(VALID(tx,ty)==true)
                        {
                            if(grid[tx][ty]=='0')
                            {
                                vis[tx][ty]=1;
                                continue;
                            }

                            vis[tx][ty]=1;
                            Q.push(tx);
                            Q.push(ty);
                        }
                    }
                }
                cnt++;
                while(!Q.empty())
                    Q.pop();
            }
        }
    }

    return cnt;
}
int main()
{
    int res,T=0,i;
    while(cin >> N)
    {
        for(i=0; i<N; i++)
            cin >> grid[i];

        res=BFS();
        cout << "Image number " << ++T << " contains " << res << " war eagles." << endl;
    }

    return 0;
}
