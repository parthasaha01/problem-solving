#include<bits/stdc++.h>
using namespace std;
int r,c,vis[105][105];
char ss[105][105];
int fx[]={-1,-1,+0,+0,+1,+1,+1,-1};
int fy[]={-1,+0,-1,+1,+0,+1,-1,+1};
int BFS(int x,int y)
{
    if(ss[x][y]=='L')return 0;

    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    queue< pair<int,int> >q;
    q.push(make_pair(x,y));
    int cnt=0;

    while(!q.empty())
    {
        pair<int,int> u;
        u = q.front();
        q.pop();
        x = u.first;
        y = u.second;
        cnt++;

        for(int k=0; k<8; k++)
        {
            int tx = x+fx[k];
            int ty = y+fy[k];

            if(tx<0||tx>=r||ty<0||ty>=c)continue;
            if(ss[tx][ty]=='L')continue;
            if(vis[tx][ty]==1)continue;

            vis[tx][ty]=1;
            q.push(make_pair(tx,ty));
        }
    }
    return cnt;
}
int main()
{
    int tt,ks=0; scanf("%d",&tt);
    getchar();
    getchar();
    while(tt--)
    {
        if(ks)printf("\n");
        ks++;
        int n=0;
        //flag = 0;
        while(gets(ss[n]))
        {
            if(ss[n][0]=='\0')break;
            else if(ss[n][0]=='L'||ss[n][0]=='W'){
                c = strlen(ss[n]);
                n++;
                r = n;
            }
            else{
                int p = strlen(ss[n]);
                int x = 0,y=0;
                for(int i=0; i<p; i++){
                    if(ss[n][i]==' '){
                        i++;
                        while(i<p){
                            y+=(y*10)+(ss[n][i]-'0');
                            i++;
                        }
                    }
                    else {
                        x+=(x*10)+(ss[n][i]-'0');
                    }
                }

                int ans = BFS(--x,--y);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}


