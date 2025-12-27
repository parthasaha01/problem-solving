#include<bits/stdc++.h>
using namespace std;
struct nt{ double x,y; }nd[1005];
double dist(nt u,nt v)
{
    double x1,x2,y1,y2;
    x1 = u.x, x2 = v.x, y1 = u.y, y2 = v.y;
    return sqrt( ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)) );
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; double r;
        scanf("%d%lf",&n,&r);

        for(int i=1; i<=n; i++)
        {
            scanf("%lf%lf",&nd[i].x,&nd[i].y);
        }

        memset(cl,0,sizeof(cl));

        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {

            }
        }

    }
}
