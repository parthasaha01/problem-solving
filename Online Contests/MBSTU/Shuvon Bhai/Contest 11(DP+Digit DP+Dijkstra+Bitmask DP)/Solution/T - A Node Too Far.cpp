#include<bits/stdc++.h>
using namespace std;
#define mx 35
#define LLI long long
map<LLI,int>mp;
vector<int>V[mx];
queue<int>Q;
int cost[mx];
int vis[mx];
void Initiallize()
{
    while(!Q.empty())
        Q.pop();

    memset(cost,mx,sizeof(cost));
    memset(vis,0,sizeof(cost));
}

LLI BFS(int src, int TTL)
{
    int u,v,i,sz,cnt=0;
    cost[src]=0;
    vis[src]=1;
    Q.push(src);

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        if(cost[u]>=TTL)
            return cnt;

        sz=V[u].size();

        for(int i=0; i<sz; i++)
        {
            v=V[u][i];

            if(vis[v]==0){
                ++cnt;
                vis[v]=1;
            }

            if(cost[v]>cost[u]+1)
            {
                Q.push(v);
                cost[v]=cost[u]+1;
            }
        }
    }

    return cnt;
}
int main()
{
    LLI node,src,TTL,E,u,v,Tnode,result,test=0;

    while(cin >> E && E)
    {
        int k=0;
        for(int i=0; i<E; i++)
        {
            cin >> u >> v;
            if( mp.find(u) == mp.end() ){
                mp[u]=k;
                k++;
            }
            if( mp.find(v) == mp.end() ){
                mp[v]=k;
                k++;
            }

            V[mp[u]].push_back(mp[v]);
            V[mp[v]].push_back(mp[u]);

        }

        /*for( map<LLI,LLI>:: iterator it=mp.begin(); it!=mp.end(); ++it )
            cout<<it->first<<" "<<it->second<<endl;*/

        Tnode=k;

        while(cin >> node >> TTL)
        {
            if(!node && !TTL)
                break;

            Initiallize();

            result=Tnode-BFS(mp[node],TTL)-1;
            printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",++test,result,node,TTL);
        }

        mp.clear();
        for(int i=0; i<mx; i++)
            V[i].clear();
    }

    return 0;
}

