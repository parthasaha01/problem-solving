#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 999999999999LL
#define mx 10005
ll dis1[mx+5],dis2[mx+5];
bool vis1[mx+5],vis2[mx+5];
vector<ll>ed[mx+5],rv[mx+5];
void bfs1(ll ss)
{
    memset(vis1,false,sizeof(vis1));
    for(int i=0; i<mx; i++) dis1[i]=inf;

    vis1[ss]=true;
    dis1[ss]=0;
    queue<ll>q1;
    q1.push(ss);

    while(!q1.empty())
    {
        ll u=q1.front();
        q1.pop();

        for(int i=0; i<ed[u].size(); i++)
        {
           ll v=ed[u][i];
           if(vis1[v]==false)
           {
               vis1[v]=true;
               dis1[v]=dis1[u]+1;
               q1.push(v);
           }
        }
    }
}
void bfs2(ll ss)
{
    memset(vis2,false,sizeof(vis2));
    for(int i=0; i<mx; i++) dis2[i]=inf;

    vis2[ss]=true;
    dis2[ss]=0;
    queue<ll>q2;
    q2.push(ss);

    while(!q2.empty())
    {
        ll u=q2.front();
        q2.pop();

        for(int i=0; i<rv[u].size(); i++)
        {
           ll v=rv[u][i];
           if(vis2[v]==false)
           {
               vis2[v]=true;
               dis2[v]=dis2[u]+1;
               q2.push(v);
           }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        printf("Case %d:\n",ks);

        ll n,r,c,q;

        scanf("%lld%lld%lld%lld",&n,&r,&c,&q);

        for(int i=0; i<mx; i++){
            ed[i].clear();
            rv[i].clear();
        }

        for(int i=0; i<r; i++)
        {
            ll u,v;
            scanf("%lld%lld",&u,&v);
            ed[u].push_back(v);
            rv[v].push_back(u);
        }

        bfs1(c);
        bfs2(c);

        for(int i=0; i<q; i++)
        {
            ll u,v;
            scanf("%lld%lld",&u,&v);

            if(dis2[u]>=inf || dis1[v]>=inf){
                printf("Not possible to go from %lld to %lld.\n",u,v);
            }
            else{
                ll ans=dis2[u]+dis1[v];
                printf("The shortest distance from %lld to %lld is %lld.\n",u,v,ans);
            }
        }
    }

    return 0;
}
