#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
vector<ll>ed[mx];
ll n,cost[mx],res[mx],cntp,cntn;
bool vis[mx];
void reset()
{
    for(int i=0; i<=n; i++)
    {
        ed[i].clear();
        vis[i]=false;
        res[i]=0;
        cntp=0;
        cntn=0;
    }
}
ll DFS(ll u)
{
    vis[u]=true;

    for(ll i=0; i<ed[u].size(); i++)
    {
        ll v=ed[u][i];

        if(vis[v]==false)
        {
            DFS(v);

            cntn=max(cntn,-cost[v]);

            cntp=max(cntp,cost[v]);

            //cout << v << " " << cost[v] << " cntp=" << cntp << " cntn=" << cntn << endl;
        }

    }

    //cout << "cost-" << u << " = " << cost[u] << " cntp=" << cntp << " cntn=" << cntn << endl;

    cost[u]-=cntp;
    cost[u]+=cntn;

    res[u] = abs(cost[u])+cntp+cntn;

    if(cost[u]<0){
        cntn+=abs(cost[u]);
    }
    else{
        cntp+=cost[u];
    }

    /*if(cost[u]<0){
        cost[u]=cost[u]-cntn-cntp;
    }
    else{
        cost[u]=cost[u]-cntn-cntp;
    }*/
    //cout << "cost," << u << " = " << cost[u] << endl;
    return res[u];

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

        ll ans=DFS(1);

        printf("%I64d\n",abs(ans));

        /*for(ll i=1; i<=n; i++)
        {
            printf("%I64d\n",res[i]);
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
