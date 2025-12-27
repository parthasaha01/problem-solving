#include<bits/stdc++.h>
using namespace std;
#define mx 300005
bool vis[mx+5];
vector<int>ed[mx+5];
int cost[mx+5],up[mx+5];
struct st
{
    int u,w;
    st(int a, int b)
    {
        u=a;
        w=b;
    }
    bool operator <(const st& p)const{
        return w < p.w;
    }
};
priority_queue<st>pq;
int main()
{
    int n; scanf("%d",&n);

    int suru=0, maxx=-1000000007;
    for(int i=1; i<=n; i++){
        scanf("%d",&cost[i]);
        if(cost[i]>maxx){
            maxx=cost[i];
            suru=i;
        }
    }

    for(int i=1; i<=n-1; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    pq.push(st(suru,cost[suru]));

    int ans=-1000000005;
    while(!pq.empty())
    {
        st top = pq.top();
        pq.pop();

        int u = top.u;
        int w = top.w;

        if(vis[u])continue;
        vis[u]=true;

        ans = max(ans,w);

        //printf("\nu=%d: ",u);

        for(int i=0; i<ed[u].size(); i++)
        {
            int v = ed[u][i];
            if(vis[v])continue;
            cost[v]++;
            for(int j=0; j<ed[v].size(); j++)
            {
                int z = ed[v][j];
                if(vis[z])continue;
                cost[z]++;
            }
            //printf("%d ",v);
            pq.push(st(v,cost[v]));
        }
    }
    //printf("\n");
    printf("%d\n",ans);

    return 0;
}
