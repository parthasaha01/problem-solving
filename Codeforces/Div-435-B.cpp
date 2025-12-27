#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bb,ww;
int vis[100005];
vector<int>ed[100005];
void dfs(int u,int cl)
{
    if(cl==1)bb++;
    if(cl==0)ww++;
    vis[u]=1;

    for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
        if(vis[v]==0){
            dfs(v,1-cl);
        }
    }
}
int main()
{
    bb=0;ww=0;

    int n; scanf("%d",&n);



    for(int i=1; i<=n-1; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    if(n==1){
        printf("0\n");
        return 0;
    }

    dfs(1,0);

    ll ans = bb*ww;
    ans -= (n-1);

    printf("%I64d\n",ans);

    return 0;
}
