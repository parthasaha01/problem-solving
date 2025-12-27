#include<bits/stdc++.h>
using namespace std;
char s[105][105];
int fx[] = {-1,+0,+0,+1};
int fy[] = {+0,-1,+1,+0};
struct dt{
    int x,y,v;
};
queue<dt>qq;
int cost[105][105];
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int m,n; scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[i]);
        }

        int sx,sy;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='$'){
                    sx = i, sy = j;
                    break;
                }
            }
        }

        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                cost[i][j] = 10000000;
            }
        }
        while(!qq.empty()){
            qq.pop();
        }


        dt p;
        p.x = sx, p.y = sy, p.v = 0;
        qq.push(p);
        cost[sx][sy] = 0;

        int ans = 10000000;


        while(!qq.empty())
        {
            dt u;
            u = qq.front();
            qq.pop();

            int x,y,v;
            x = u.x, y = u.y, v = u.v;

            //printf("x=%d y=%d v=%d\n",x,y,v);
            //getchar();

            for(int k=0; k<4; k++)
            {
                int tx = x+fx[k];
                int ty = y+fy[k];

                if(tx<0 || tx>=n || ty<0 || ty>=m)
                {
                    ans = min(ans,v);
                }
                else
                {
                    if(s[tx][ty]!='*')
                    {
                        int nv=v+1;
                        if(s[tx][ty]=='.')nv=v;
                        if(s[tx][ty]=='#')nv=v+1;
                        if(nv<cost[tx][ty]){
                            dt z;
                            z.x = tx, z.y = ty, z.v = nv;
                            cost[tx][ty] = nv;
                            qq.push(z);
                        }
                    }
                }
            }
        }

        if(ans>10000)printf("Case %d: Impossible\n",ks);
        else printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}

