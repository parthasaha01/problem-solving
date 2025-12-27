#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int n,cmax[105][105],cmin[105][105],vs[105];
vector<int>ed[105];
struct emax
{
    int u,v,w;
    emax(int x, int y, int c){
        u=x;v=y;w=c;
    }
    bool operator < (const emax& p) const{
        return w < p.w;
    }
};
struct emin
{
    int u,v,w;
    emin(int x, int y, int c){
        u=x;v=y;w=c;
    }
    bool operator < (const emin& p) const{
        return p.w < w;
    }
};
int primsMax()
{
    memset(vs,0,sizeof(vs));
    priority_queue<emax>pq;

    for(int i=0; i<ed[0].size(); i++){
        pq.push(emax(0,ed[0][i],cmax[0][ed[0][i]]));
    }

    int sum=0;
    vs[0]=1;

    while(!pq.empty())
    {
        emax nd(0,0,0);
        nd = pq.top();
        pq.pop();

        int u=nd.u, v=nd.v, w=nd.w;

        if(vs[v]) continue;
        vs[v]=1;
        sum+=w;

        for(int i=0; i<ed[v].size(); i++){
            if(vs[ed[v][i]]==0){
                pq.push(emax(v,ed[v][i],cmax[v][ed[v][i]]));
            }
        }
    }

    return sum;
}
int primsMin()
{
    memset(vs,0,sizeof(vs));
    priority_queue<emin>pq;

    for(int i=0; i<ed[0].size(); i++){
        pq.push(emin(0,ed[0][i],cmin[0][ed[0][i]]));
    }

    int sum=0;
    vs[0]=1;

    while(!pq.empty())
    {
        emin nd(0,0,0);
        nd = pq.top();
        pq.pop();

        int u=nd.u, v=nd.v, w=nd.w;

        if(vs[v]) continue;
        vs[v]=1;
        sum+=w;

        for(int i=0; i<ed[v].size(); i++){
            if(vs[ed[v][i]]==0){
                pq.push(emin(v,ed[v][i],cmin[v][ed[v][i]]));
            }
        }
    }

    return sum;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);

        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                cmax[i][j]=-1;
                cmin[i][j]=inf;
            }
        }

        int u,v,w;
        while(scanf("%d%d%d",&u,&v,&w)==3)
        {
            if(!u&&!v&&!w)break;

            if(cmax[u][v]==-1)
            {
                ed[u].push_back(v);
                ed[v].push_back(u);
            }

            cmax[u][v]=cmax[v][u]=max(cmax[u][v],w);
            cmin[u][v]=cmin[v][u]=min(cmin[u][v],w);
        }

        int maxx = primsMax();
        int minn = primsMin();
        int sum  = maxx+minn;

        if(sum%2==0)printf("Case %d: %d\n",ks,sum/2);
        else printf("Case %d: %d/2\n",ks,sum);

        for(int i=0; i<=n; i++)ed[i].clear();
    }

    return 0;
}

