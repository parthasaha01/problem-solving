#include<bits/stdc++.h>
using namespace std;
vector<int>ed[205];
int color[205],n;
bool vis[205],flag;
void CLEAR()
{
    memset(vis,false,sizeof(vis));
    memset(color,-1,sizeof(color));
    for(int i=0;i<n;i++){
        ed[i].clear();
    }
}
void dfs(int u)
{
    vis[u]=true;

    for(int i=0; i<ed[u].size(); i++){
        int v=ed[u][i];

        if(vis[v]==false){
            color[v]=1-color[u];
            dfs(v);
        }
        else{
            if(color[u]==color[v]){
                flag=false;
            }
        }
    }

    return;
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        CLEAR();

        int l;
        scanf("%d",&l);
        for(int i=0; i<l; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        flag=true;
        color[0]=0;
        dfs(0);

        if(flag==true){
            printf("BICOLORABLE.\n");
        }
        else{
            printf("NOT BICOLORABLE.\n");
        }
    }

    return 0;
}
