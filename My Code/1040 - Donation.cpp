#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int n,cnt,vs[55],cost[55][55];

struct edge
{
    int u,v,w;
    edge(int x, int y, int c){
        u=x;v=y;w=c;
    }
    bool operator < (const edge& p) const{
        return p.w < w;
    }
};
int primsMST()
{
    memset(vs,0,sizeof(vs));
    priority_queue<edge>pq;

    vs[1]=1;
    for(int i=1; i<=n; i++){
        if(vs[i]==0 && cost[1][i]>0){
            pq.push(edge(1,i,cost[1][i]));
        }
    }

    int sum=0;
    cnt=1;

    while(!pq.empty())
    {
        edge nd(0,0,0);
        nd = pq.top();
        pq.pop();

        int u=nd.u, v=nd.v, w=nd.w;

        if(vs[v]) continue;
        vs[v] = 1;
        cnt++;

        sum+=w;

        for(int i=1; i<=n; i++){
            if(vs[i]==0 && cost[v][i]>0){
                pq.push(edge(v,i,cost[v][i]));
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

        int total=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d",&cost[i][j]);
                total += cost[i][j];
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                if(cost[i][j]>0 && cost[j][i]>0){
                    cost[i][j] = cost[j][i] = min(cost[i][j],cost[j][i]);
                }
                else if(cost[i][j]>0){
                    cost[j][i] = cost[i][j];
                }
                else if(cost[j][i]>0){
                    cost[i][j] = cost[j][i];
                }
            }
        }

        int res = primsMST();
        int ans = total-res;

        if(cnt<n)printf("Case %d: -1\n",ks);
        else printf("Case %d: %d\n",ks,ans);

    }

    return 0;
}
