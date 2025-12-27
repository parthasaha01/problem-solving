#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define mx 1002
vector<int>ed[mx];
int d[mx],police[mx],ans[mx];
int cost[mx][mx];
bool vis[mx];
struct st
{
    int n,w;
}bank[mx];
struct dt
{
    int u,w;
    dt(int x, int y){
        u=x;w=y;
    }
    bool operator <(const dt& r)const{
        return r.w < w;
    }
};
bool cmp(st x,st y)
{
    if(x.w==y.w){
        return x.n<y.n;
    }
    else{
        return x.w>y.w;
    }
}
void Dijkstra(int s,int n)
{
    for(int i=0; i<=n; i++){
        vis[i]=false;
        d[i]=inf;
    }

    priority_queue<dt>pq;

    d[s]=0;
    ans[s]=0;
    pq.push(dt(s,d[s]));

    while(!pq.empty())
    {
        dt top=pq.top();
        pq.pop();
        int u=top.u;

        if(vis[u]) continue;

        for(int i=0; i<ed[u].size(); i++)
        {
            int v=ed[u][i];
            if(d[u]+cost[u][v]<ans[v])
            {
                d[v]=d[u]+cost[u][v];
                ans[v]=d[v];
                pq.push(dt(v,d[v]));
            }
        }
        vis[u]=true;
    }
}
int main()
{
    int n,m,b,p;
    while(scanf("%d%d%d%d",&n,&m,&b,&p)==4)
    {
        for(int i=0; i<=n; i++){
            ans[i]=inf;
            ed[i].clear();
        }

        for(int i=0; i<m; i++)
        {
            int u,v,t;
            scanf("%d%d%d",&u,&v,&t);
            ed[u].push_back(v);
            ed[v].push_back(u);
            cost[u][v]=t;
            cost[v][u]=t;
        }

        for(int i=0; i<b; i++){
            scanf("%d",&bank[i].n);
        }

        for(int i=0; i<p; i++){
            scanf("%d",&police[i]);
        }

        for(int i=0; i<p; i++){
            Dijkstra(police[i],n);
        }

        for(int i=0; i<b; i++){
            int u=bank[i].n;
            bank[i].w=ans[u];
        }

        sort(bank,bank+b,cmp);

        int cnt=0;
        int maxx=bank[0].w;
        for(int i=0; i<b; i++){
            if(bank[i].w<maxx){
                break;
            }
            cnt++;
        }

        if(maxx==inf){
            printf("%d *\n",cnt);
        }
        else{
            printf("%d %d\n",cnt,maxx);
        }

        printf("%d",bank[0].n);
        for(int i=1; i<cnt; i++){
            printf(" %d",bank[i].n);
        }
        printf("\n");
    }

    return 0;
}
