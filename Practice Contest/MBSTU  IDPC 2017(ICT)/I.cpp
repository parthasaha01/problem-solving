#include<bits/stdc++.h>
using namespace std;
#define mx 10005
#define ll long long
bool vis[mx];
int par[mx+5],nn;
ll maxx;
map<string,int>mp;
vector<int>ed[mx];
vector<ll>cost[mx];
struct edge
{
    int u,v; ll w;
    edge(int a, int b, ll c){
        u=a;v=b;w=c;
    }

    bool operator < (const edge& p) const{
        return p.w < w;
    }
};

priority_queue<edge>pq;

int findparent(int x)
{
    if(par[x]==x)
        return x;
    else
        return par[x]=findparent(par[x]);
}

void kruskalMST(int node)
{
    for(int i=1; i<=node; i++) par[i]=i;

    for(int i=1; i<=node-1; i++)
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
            ed[top.u].push_back(top.v);
            ed[top.v].push_back(top.u);
            cost[top.u].push_back(top.w);
            cost[top.v].push_back(top.w);
        }
    }

    while(!pq.empty())pq.pop();
}
void dfs1(int u, ll weight)
{
    vis[u]=true;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v=ed[u][i];

        if(vis[v]==false)
        {
            ll w=cost[u][i];
            if(weight+w>=maxx){
                maxx=weight+w;
                nn=v;
            }
            dfs1(v,weight+w);
        }
    }
    vis[u]=false;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,m; scanf("%d%d",&n,&m);
        getchar();

        int k=0;
        mp.clear();
        for(int i=1; i<=m; i++)
        {
            string s1,s2; int u,v,w;
            //scanf("%s %s %d\n",s1,s2,w);
            cin >> s1 >> s2 >> w;

            if(mp[s1]==0)mp[s1]=++k;
            if(mp[s2]==0)mp[s2]=++k;

            u = mp[s1], v = mp[s2];
            pq.push(edge(u,v,w));
        }

        kruskalMST(n);

        maxx=0;
        dfs1(1,0);

        maxx=0;
        dfs1(nn,0);

        printf("Case %d: %lld\n",ks,maxx);

        for(int i=0; i<=n; i++)
        {
            ed[i].clear();
            cost[i].clear();
            vis[i]=false;
        }
    }

    return 0;
}

/*
2

6 6
Dhaka Tangail 6
Tangail Bogra 4
Barisal Tangail 8
Modhupur Tangail 3
Dhaka Modhupur 15
Modhupur Santosh 2

3 3
Dhaka Sylhet 2
Sylhet Dinajpur 5
Dinajpur Dhaka 3

*/
