#include<bits/stdc++.h>
using namespace std;
int maxx,ans[1005],level[1005],b[1005];
vector<int>ed[1005];
void dfs(int u,int p,int l,int x)
{
    level[l]+=b[u];
    maxx = max(maxx,level[l]);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==p)continue;
        if(v==x)continue;
        dfs(v,u,l+1,x);
    }
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&b[i]);
        }

        for(int i=2; i<=n; i++){
            int p; scanf("%d",&p);
            ed[i].push_back(p);
            ed[p].push_back(i);
        }

        for(int i=2; i<=n; i++){
            maxx = 0;
            memset(level,0,sizeof(level));
            dfs(1,0,0,i);
            ans[i]=maxx;
        }
        for(int i=2; i<=n; i++){
            printf("%d\n",ans[i]);
        }

        for(int i=1; i<=n; i++)ed[i].clear();
    }
    return 0;
}
