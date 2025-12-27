#include<bits/stdc++.h>
using namespace std;
int par[105];
struct nt{
    double x,y;
}nd[105];
struct edge
{
    int u,v;
    double w;
    edge(int a, int b, double c){
        u=a;v=b;w=c;
    }

    bool operator < (const edge& p) const{
        return p.w < w;
    }
};
priority_queue<edge>pq;
queue<edge>Q;
int findparent(int x)
{
    if(par[x]==x)
        return x;
    else
        return par[x]=findparent(par[x]);
}
double kruskalMST(int n)
{
    double Mincost=0.0;

    for(int i=1; i<=n; i++)par[i]=i;

    for(int i=1; i<n; i++)
    {
        label:
        edge top = pq.top();
        pq.pop();

        int parU = findparent(top.u);
        int parV = findparent(top.v);

        if(parU==parV){
            goto label;
        }
        else{
            par[parU]=parV;
            Q.push(top);
            Mincost+=top.w;
        }
    }
    return Mincost;
}
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
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            double x,y; scanf("%lf%lf",&x,&y);
            nd[i].x = x;
            nd[i].y = y;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                double w = dist(nd[i],nd[j]);
                pq.push(edge(i,j,w));
            }
        }

        double ans = kruskalMST(n);

        printf("%.2lf\n",ans);
        if(ks<tt)printf("\n");

        while(!pq.empty())pq.pop();
        while(!Q.empty())Q.pop();
    }

    return 0;
}
