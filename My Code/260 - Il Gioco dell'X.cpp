#include<bits/stdc++.h>
using namespace std;
int n,rowb[205],vis[205][205];
char ss[205][205];
int fx[]={-1,-1,+0,+0,+1,+1};
int fy[]={-1,+0,-1,+1,+0,+1};
void BFS(int x,int y)
{
    vis[x][y]=1;
    queue< pair<int,int> >q;
    q.push(make_pair(x,y));

    while(!q.empty())
    {
        pair<int,int> u;
        u = q.front();
        q.pop();
        x = u.first;
        y = u.second;
        rowb[x]=1;

        for(int k=0; k<6; k++)
        {
            int tx = x+fx[k];
            int ty = y+fy[k];

            if(tx<0||tx>=n||ty<0||ty>=n)continue;
            if(ss[tx][ty]=='w')continue;
            if(vis[tx][ty]==1)continue;

            vis[tx][ty]=1;
            q.push(make_pair(tx,ty));
        }
    }
}
char FUN()
{
    memset(vis,0,sizeof(vis));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j]==1 || ss[i][j]=='w')continue;
            memset(rowb,0,sizeof(rowb));
            BFS(i,j);
            int cnt=0;
            for(int k=0; k<n; k++){
                if(rowb[k])cnt++;
            }
            if(cnt==n)return 'B';
        }
    }
    return 'W';
}
int main()
{
    int ks=0;
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n; i++)
            scanf("%s",ss[i]);

        char ans = FUN();
        printf("%d %c\n",++ks,ans);
    }
    return 0;
}
