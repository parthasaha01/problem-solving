#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char cell[505][505];
int ss[505][505];
bool freq[30],vis[30][505];
struct dt
{
    int x,y;
}col[30][505];
int bfs(int sx,int sy,int v)
{
    int cst=999999999;
    for(int i=0; i<m; i++)
    {
        if(vis[v][i]==true)
        {
            int x=col[v][i].x;
            int y=col[v][i].y;
            int dist=abs(sx-x)+abs(sy-y);
            cst=min(cst,dist);
        }
    }

    return min(k,cst);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<n; i++){
            scanf("%s",cell[i]);
        }

        memset(freq,false,sizeof(freq));
        memset(vis,false,sizeof(vis));
        long long int res=0LL;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                char ch=cell[i][j];
                int c=ch-'a';

                if(freq[c]==false)
                {
                    res+=k;
                    freq[c]=true;
                }
                else
                {
                    int cst=bfs(i,j,c);
                    res+=cst;
                }
                ss[i][j]=c;
                col[c][j].x=i;
                col[c][j].y=j;
                vis[c][j]=true;
            }
        }

        printf("Case %d: %lld\n",ks,res);
    }

    return 0;
}
