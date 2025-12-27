#include<bits/stdc++.h>
using namespace std;
vector<int>ed[35];
map<string,int>mp;
queue<int>q;
int level[35];
int vis[35];
int bfs(int src, int des)
{
    int u,v,sz;
    q.push(src);
    level[src]=0;

    while(!q.empty())
    {
        u = q.front();

        if(vis[u]==0)
        {
            sz = ed[u].size();

            for(int i=0; i<sz; i++)
            {
                v = ed[u][i];

                if(level[u]+1<level[v])
                {
                    level[v] = level[u]+1;
                }
                q.push(v);
            }

            vis[u]=1;
        }

        q.pop();
    }

    return level[des];
}
int main()
{
    int t,n,m,p,val,lev,res,x,y;
    string s,u,v,src,des;
    scanf("%d",&t);

    printf("SHIPPING ROUTES OUTPUT\n\n");

    for(int kase=1; kase<=t; kase++)
    {
        printf("DATA SET  %d\n\n",kase);

        scanf("%d%d%d",&m,&n,&p);

        for(int i=1; i<=m; i++)
        {
            cin >> s;
            mp[s]=i;
        }

        for(int i=1; i<=n; i++)
        {
            cin >> u >> v;
            ed[mp[u]].push_back(mp[v]);
            ed[mp[v]].push_back(mp[u]);
        }

        for(int i=1; i<=p; i++)
        {
            scanf("%d",&val);

            cin >> src >> des;

            for(int i=0; i<=32; i++)
            {
                level[i]=1000;
            }

            memset(vis,0,sizeof(vis));

            lev = bfs(mp[src],mp[des]);

            if(lev!=1000)
            {
                res = val*lev*100;
                printf("$%d\n",res);
            }
            else
            {
                printf("NO SHIPMENT POSSIBLE\n");
            }

        }

        for(int i=0; i<=32; i++){
            ed[i].clear();
        }
        mp.clear();

        printf("\n");
    }

    printf("END OF OUTPUT\n");

    return 0;
}
