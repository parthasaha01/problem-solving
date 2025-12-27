#include<bits/stdc++.h>
using namespace std;
#define mx 2005
int vis[mx],col[mx],dp[mx][mx];
int cnt,x,flag,id,a,b,c;
vector<int>ed[mx];
struct dt
{
    int nd,xx,yy;
}st[mx];
void dfs(int u,int cl)
{
    vis[u]=1;
    col[u]=cl;
    cnt++;
    if(cl==0)x++;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];

        if(vis[v]){
            if(col[v]==col[u]){
                flag=0;
                return;
            }
        }
        else{
            dfs(v,1-col[u]);
        }
    }
}
int fun(int pos,int sum)
{
    if(pos>id){
        if(sum==0) return 1;
        else return 0;
    }

    if(dp[pos][sum]!=-1)return dp[pos][sum];

    int ret1=0,ret2=0;

    if(sum-st[pos].xx>=0)ret1 = fun(pos+1,sum-st[pos].xx);
    if(sum-st[pos].yy>=0)ret2 = fun(pos+1,sum-st[pos].yy);

    return dp[pos][sum] = ret1|ret2;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int b,c,a;
        scanf("%d%d%d",&b,&c,&a);

        for(int i=0; i<=b+c; i++)ed[i].clear();

        for(int i=1; i<=a; i++){
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        flag = 1;
        id=0;
        memset(vis,0,sizeof(vis));

        for(int i=1; i<=b+c; i++)
        {
            if(!vis[i]){
                id++;
                cnt=x=0;
                dfs(i,0);
                if(flag==0)break;
                st[id].nd=cnt;
                st[id].xx=x;
                st[id].yy=cnt-x;
            }
        }

        if(!flag){
            printf("no\n");
            continue;
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(1,b);

        if(ans)printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
