#include<bits/stdc++.h>
using namespace std;
int b,c,a,cnt,k,flag,zero;
int dp[2005][1005],col[2005];
vector<int>ed[2005];
bool vis[2005];
struct dt{
    int n,v;
}gr[2005];
void dfs(int u,int cl)
{
    cnt++;
    vis[u]=true;
    col[u]=cl;
    if(cl==0)zero++;

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(vis[v]==true && col[v]==col[u]){
            flag = -1; return;
        }
        if(vis[v]==true) continue;
        dfs(v,1-col[u]);
    }
    return;
}
int fun(int pos,int bn)
{
    if(pos==k){
        if(bn==0) return 1;
        else return 0;
    }
    if(dp[pos][bn]!=-1) return dp[pos][bn];

    int ret1=0,ret2=0;
    int node = gr[pos].n;
    int zero = gr[pos].v;
    int one  = gr[pos].n - gr[pos].v;

    if(bn-zero>=0) ret1 = fun(pos+1,bn-zero);
    if(bn-one>=0)  ret2 = fun(pos+1,bn-one);

    return dp[pos][bn] = ret1 | ret2;
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d%d",&b,&c,&a);
        int n = b+c;
        for(int i=0; i<=n; i++)ed[i].clear();

        for(int i=1; i<=a; i++){
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        k=0;
        memset(vis,false,sizeof(vis));

        for(int i=1; i<=n; i++){
            cnt=zero=flag=0;
            if(vis[i]==false){
                dfs(i,0);
                if(flag==-1)break;
                gr[k].n = cnt;
                gr[k].v = zero;
                k++;
            }
        }

        if(flag==-1){
            printf("no\n"); continue;
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,b);
        if(ans)printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
