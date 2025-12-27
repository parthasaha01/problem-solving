#include<bits/stdc++.h>
using namespace std;
#define mx 200005
vector<int>ed[mx+5];
int ans[mx+5],dg[mx+5];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0; i<=n; i++)ed[i].clear();
        memset(dg,0,sizeof(dg));

        for(int i=1; i<=m; i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
            dg[u]++;
            dg[v]++;
        }

        int mn = 1000000000;
        int nd = 0;
        for(int i=1; i<=n; i++)
        {
            if(dg[i]<mn)
            {
                mn = dg[i];
                nd = i;
            }
        }

        for(int i=1; i<=n; i++)ans[i]=1;
        ans[nd]=0;
        for(int i=0; i<ed[nd].size(); i++)
        {
            int v = ed[nd][i];
            ans[v]=0;
        }

        for(int i=1; i<=n; i++)
        {
            if(i<n)printf("%d ",ans[i]);
            else printf("%d\n",ans[i]);
        }
    }

    return 0;
}