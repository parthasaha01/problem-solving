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
    cnt++;
    vis[u]=true;
    col[u]=cl;
    if(cl==0)x++;

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
    if(pos==id){
        if(bn==0) return 1;
        else return 0;
    }
    if(dp[pos][bn]!=-1) return dp[pos][bn];

    int ret1=0,ret2=0;
    int node = st[pos].nd;
    int zero = st[pos].xx;
    int one  = st[pos].nd - st[pos].xx;

    if(bn-zero>=0) ret1 = fun(pos+1,bn-zero);
    if(bn-one>=0)  ret2 = fun(pos+1,bn-one);

    return dp[pos][bn] = ret1 | ret2;
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
        memset(vis,false,sizeof(vis));

        for(int i=1; i<=b+c; i++)
        {
            if(!vis[i]){
                cnt=x=0;
                dfs(i,0);
                if(flag==-1)break;
                st[id].nd=cnt;
                st[id].xx=x;
                st[id].yy=cnt-x;
                id++;
            }
        }

        if(flag==-1){
            printf("no\n");
            continue;
        }

        //flag=0;
        memset(dp,-1,sizeof(dp));
        int ans = fun(0,b);

        if(ans)printf("yes\n");
        else printf("no\n");


    }

    return 0;
}
