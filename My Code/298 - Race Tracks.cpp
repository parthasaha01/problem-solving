#include<bits/stdc++.h>
using namespace std;
struct dt{
    int x,y,u,v;
};
int fx[] = {-1,-1,-1,+0,+0,+0,+1,+1,+1};
int fy[] = {-1,+0,+1,-1,+0,+1,-1,+0,+1};
int s[35][35],vs[35][35][10][10];
int r,c,sx,sy,dx,dy;

int fun()
{
    memset(vs,-1,sizeof(vs));
    queue<dt>qq;
    dt st;
    st.x = sx;
    st.y = sy;
    st.u = 0;
    st.v = 0;
    vs[sx][sy][4][4]=0;
    qq.push(st);

    while(!qq.empty())
    {
        dt nd = qq.front();
        qq.pop();

        for(int k=0; k<9; k++)
        {
            int px = nd.x;
            int py = nd.y;
            int pu = nd.u;
            int pv = nd.v;

            if(px==dx && py==dy)return vs[px][py][pu+4][pv+4];

            int uu = pu+fx[k];
            int vv = pv+fy[k];

            if(uu<(-3) || uu>3 || vv<(-3) || vv>3)continue;

            int tx = px+uu;
            int ty = py+vv;

            if(tx<0 || tx>=r || ty<0 || ty >=c || s[tx][ty]==-1 || vs[tx][ty][uu+4][vv+4]!=-1)continue;

            //if(valid(tx,ty,uu,vv))
            //{
                dt pp;
                pp.x = tx;
                pp.y = ty;
                pp.u = uu;
                pp.v = vv;
                vs[tx][ty][uu+4][vv+4]=vs[px][py][pu+4][pv+4]+1;
                qq.push(pp);
            //}
        }
    }

    return -1;
}
int main()
{
    int tt;
    scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&r,&c);
        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);

        memset(s,0,sizeof(s));
        int p;
        scanf("%d",&p);
        for(int i=1; i<=p; i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            for(int x=x1; x<=x2; x++)
            {
                for(int y=y1; y<=y2; y++)
                {
                    s[x][y]=-1;
                }
            }
        }

        int ans = fun();

        if(ans==-1)printf("No solution.\n");
        else printf("Optimal solution takes %d hops.\n",ans);
    }
    return 0;
}

/*
2
5 5
4 0 4 4
1
1 4 2 3
*/

