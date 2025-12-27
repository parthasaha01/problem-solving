#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
vector<ll>ed[mx];
ll n,cost[mx],res[mx],ans,pos[mx],neg[mx];
bool vis[mx];
void reset()
{
    for(int i=0; i<=n; i++)
    {
        ed[i].clear();
        vis[i]=false;
        res[i]=pos[i]=neg[i]=cost[i]=0;
    }
}
void DFS(ll u)
{
    vis[u]=true;

    for(ll i=0; i<ed[u].size(); i++)
    {
        ll v=ed[u][i];

        if(vis[v]==false)
        {
            DFS(v);

            pos[u]=max(pos[u],pos[v]);
            neg[u]=max(neg[u],neg[v]);
            //cout << "costv-" << v << "="  << cost[v] << " u=" << u << " pos[u]=" << pos[u] << " neg[u]=" << neg[u] << endl;
        }

    }

    //cout << "costu-" << u << " = " << cost[u] << " pos[u]=" << pos[u] << " neg[u]=" << neg[u] << endl;

    cost[u]-=pos[u];
    cost[u]+=neg[u];

    //ans = abs(cost[u])+ps[u]+ng[u];

    res[u] = abs(cost[u])+pos[u]+neg[u];

    if(cost[u]>=0){
        pos[u]+=cost[u];
    }
    else{
        neg[u]+=abs(cost[u]);
    }

    /*if(cost[u]<0){
        cost[u]=cost[u]-cntn-cntp;
    }
    else{
        cost[u]=cost[u]-cntn-cntp;
    }*/
    //cout << "cost," << u << " = " << cost[u] << " pos[u]=" << pos[u] << " neg[u]=" << neg[u] << endl << endl;
    //return res[u];

}
int main()
{

    while(scanf("%I64d",&n)==1)
    {
        reset();

        for(ll i=1; i<n; i++)
        {
            ll u,v;
            scanf("%I64d%I64d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        for(ll i=1; i<=n; i++)
        {
            scanf("%I64d",&cost[i]);
        }

        DFS(1);

        printf("%I64d\n",res[1]);

        /*for(ll i=1; i<=n; i++)
        {
            printf("%I64d %I64d\n",res[i],cost[i]);
            //printf("%I64d\n",cost[i]);
        }*/
    }

    return 0;
}
/*
8
1 2
1 3
2 4
2 5
2 6
3 7
3 8
5 -10 10 -5 6 -8 5 -2
*/

