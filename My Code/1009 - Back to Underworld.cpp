#include<bits/stdc++.h>
using namespace std;
#define mx 100002
#define nx 20002
bool vis[mx+2],ase[nx+2];
int color[mx+2],vamp,lyk;
vector<int>ed[mx+2];
void reset()
{
    for(int i=0; i<=nx; i++){
        vis[i]=false;
        ase[i]=false;
        color[i]=-1;
        ed[i].clear();
    }
}
void dfs(int u,int pc)
{
    vis[u]=true;

    for(int i=0; i<ed[u].size(); i++){
        int v=ed[u][i];
        if(!vis[v]){
            color[v]=1-pc;
            if(color[v]==0){
                vamp++;
            }
            else{
                lyk++;
            }
            dfs(v,color[v]);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        reset();

        for(int i=0; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);

            ed[u].push_back(v);
            ed[v].push_back(u);
            ase[u]=true;
            ase[v]=true;
        }
        int ans=0;
        for(int i=1; i<=nx; i++){

            if(!vis[i]&&ase[i]){
                color[i]=0;
                vamp=lyk=0;
                vamp++;
                dfs(i,0);
                ans+=max(vamp,lyk);
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
