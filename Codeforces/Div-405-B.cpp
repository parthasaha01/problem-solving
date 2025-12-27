#include<bits/stdc++.h>
using namespace std;
#define mx 150005
#define ll long long
vector<int>ed[mx+5];
vector<int>vv;
bool vis[mx+5];
void dfs(int u)
{
    vv.push_back(u);
    vis[u]=true;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==false){
            dfs(v);
        }
    }
}
int main()
{
    int n,m;

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0; i<=n; i++)ed[i].clear();

        for(int i=1; i<=m; i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        memset(vis,false,sizeof(vis));
        bool flag = true;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==false)
            {
                vv.clear();
                dfs(i);

                ll sz = vv.size();
                ll cnt = 0;
                for(int k=0; k<sz; k++)
                {
                    int u = vv[k];
                    cnt += ed[u].size();
//                    int cnt = ed[u].size();
//                    if(cnt!=sz-1){
//                        flag = false;
//                        break;
//                    }
                }

                if(cnt!=(sz*(sz-1))){
                    flag=false;
                    break;
                }
            }
        }

        if(flag)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

