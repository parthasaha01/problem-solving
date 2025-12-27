#include<bits/stdc++.h>
using namespace std;
int n,m,money[1007];
double cnt,total,sum;
vector<int>ed[1005];
bool vis[1005];
void RESET()
{
    for(int i=0; i<=n; i++){
        vis[i]=false;
        ed[i].clear();
    }
}
void dfs(int u)
{
    vis[u]=true;
    cnt+=1;
    total+=money[u];

    for(int i=0; i<ed[u].size(); i++){
        if(vis[ed[u][i]]==false){
            dfs(ed[u][i]);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        RESET();

        scanf("%d%d",&n,&m);

        sum=0.0;
        for(int i=1; i<=n; i++){
            scanf("%d",&money[i]);
            sum+=money[i];
        }

        for(int i=0; i<m; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        bool flag=true;
        int per=(int)(sum/(double)n);

        if((sum/(double)n) != per)
        {
            flag=false;
        }
        else
        {
            for(int i=1; i<=n; i++){
                if(vis[i]==false){
                    cnt=0;
                    total=0;
                    dfs(i);
                int perg=(int)(total/cnt);
                if(((total/cnt) != perg) || (perg!=per)){
                        flag=false;
                        break;
                    }
                }
            }
        }

        if(flag)
            printf("Case %d: Yes\n",kase);
        else
            printf("Case %d: No\n",kase);

    }

    return 0;
}