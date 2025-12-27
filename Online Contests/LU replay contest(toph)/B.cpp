#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};
int n,m,vs[55][55],cs[55][55],a[55][55];
struct dt
{
    int x,y,d;
}st[2505];
bool valid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m || vs[x][y]==1)return false;
    return true;
}
bool flag(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m || vs[x][y]==0 || cs[x][y]==1)return false;
    return true;
}
bool cmp(dt u, dt v)
{
    return u.d>v.d;
}
void dfs(int x, int y, int d)
{
    vs[x][y]=1;

    for(int k=0; k<4; k++)
    {
        int xx = x+fx[k];
        int yy = y+fy[k];

        if(valid(xx,yy))
        {
            int dd = abs(a[x][y]-a[xx][yy]);
            if(dd>d)continue;

            dfs(xx,yy,d);
        }
    }
}
void fun(int x, int y)
{
    cs[x][y]=1;
    for(int k=0; k<4; k++)
    {
        int xx = x+fx[k];
        int yy = y+fy[k];

        if(flag(xx,yy))
        {
            fun(xx,yy);
        }
    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&m);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        int q; scanf("%d",&q);

        for(int i=1; i<=q; i++)
        {
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            st[i].x=x;
            st[i].y=y;
            st[i].d=d;
        }

        sort(st+1,st+q+1,cmp);

        memset(vs,0,sizeof(vs));
        for(int i=1; i<=q; i++)
        {
            int x = st[i].x;
            int y = st[i].y;
            int d = st[i].d;

            if(vs[x][y]==0)
            {
                dfs(x,y,d);
            }
        }

        int ans=0;
        memset(cs,0,sizeof(cs));

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(vs[i][j]==1 && cs[i][j]==0)
                {
                    ans++;
                    fun(i,j);
                }
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
