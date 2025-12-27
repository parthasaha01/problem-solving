#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int D,P,R,B,sum,n;
vector<pii>gr[205];
vector<pii>cnt;
vector<int>ed[205][2];
int a[205][2], vis[205][2],cost[205],b[205][2],dp[205][10005],value[205],vu[205],vv[205];
void DFS(int u,int k,int id)
{
    vis[u][k]=1;
    gr[id].push_back(pii(u,k));
    sum+=a[u][k];

    for(int i=0; i<ed[u][k].size(); i++){
        int v = ed[u][k][i];
        if(vis[v][1-k]==0){
            DFS(v,1-k,id);
        }
    }
}
int fun(int pos,int w)
{
    if(pos>n)return 0;

    if(dp[pos][w]!=-1)return dp[pos][w];

    printf("pos=%d w=%d value=%d cost=%d\n",pos,w,value[pos],cost[pos]);

    int p1=0,p2=0;
    if(w-cost[pos]>=0 && value[pos]>0)p1 = value[pos] + fun(pos+1,w-cost[pos]);
    p2 = fun(pos+1,w);

    int ret = max(p1,p2);
    return dp[pos][w]=ret;
}
void path(int pos,int w)
{
    if(pos>n)return;

    //if(dp[pos][w]!=-1)return dp[pos][w];

    int ret=fun(pos,w);
    int p1 = 0;
    int p2 = 0;

    if(w-cost[pos]>=0 && value[pos]>0)p1 = value[pos] + fun(pos+1,w-cost[pos]);
    p2 = fun(pos+1,w);

    if(ret==p1){
        for(int i=0; i<gr[pos].size(); i++){
            printf("nd = %d k=%d\n", gr[pos][i].first, gr[pos][i].second);
            if(gr[pos][i].second==0)vu[gr[pos][i].first]=1;
            if(gr[pos][i].second==1)vv[gr[pos][i].first]=1;
        }
        path(pos+1,w-cost[pos]);
    }
    else{
        path(pos+1,w);
    }

}
int solve1(int id)
{
    int ans=0;

    memset(value,0,sizeof(value));
    memset(dp,-1,sizeof(dp));
    memset(vu,0,sizeof(vu));
    memset(vv,0,sizeof(vv));

    for(int i=1; i<=id; i++){
        if(cnt[i].second!=0)value[i] = cnt[i].second - cnt[i].first;
    }

    ans += fun(1,B);
    path(1,B);

    printf("ans=%d\n",ans);

    int res=0;
    for(int i=1; i<=D; i++){
        if(vu[i]==0){
            ans++;
            res++;
            printf("u=%d\n",i);
        }
    }

    for(int i=1; i<=P; i++){
        if(vv[i]==1){
            ans++;
            res++;
            printf("v=%d\n",i);
        }
    }

    return res;
}
int solve2(int id)
{
    int ans=0;
    memset(value,0,sizeof(value));
    memset(dp,-1,sizeof(dp));
    memset(vu,0,sizeof(vu));
    memset(vv,0,sizeof(vv));

    for(int i=1; i<=id; i++){
        if(cnt[i].first!=0)value[i] = cnt[i].first - cnt[i].second;
    }
    ans += fun(1,B);
    path(1,B);

    printf("ans=%d\n",ans);

    int res = 0;

    for(int i=1; i<=D; i++){
        if(vu[i]==1){
            ans++;
            res++;
            printf("u=%d\n",i);
        }
    }
    for(int i=1; i<=P; i++){
        if(vv[i]==0){
            ans++;
            res++;
            printf("v=%d\n",i);
        }
    }

    return res;

}
int main()
{

    while(scanf("%d%d%d%d",&D,&P,&R,&B)==4)
    {
        for(int i=1; i<=D; i++){
            scanf("%d",&a[i][0]);
        }
        for(int i=1; i<=P; i++){
            scanf("%d",&a[i][1]);
        }

        for(int i=1; i<=R; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            ed[u][0].push_back(v);
            ed[v][1].push_back(u);
        }

        int id=0;
        memset(vis,0,sizeof(vis));

        for(int i=1; i<=D; i++){
            sum = 0;
            if(vis[i][0]==0){
                DFS(i,0,++id);
                cost[id]=sum;
            }
            printf("id=%d sum=%d\n",id,sum);
        }
        for(int i=1; i<=P; i++){
            sum=0;
            if(vis[i][1]==0){
                    DFS(i,1,++id);
                    cost[id]=sum;
            }
            printf("id=%d sum=%d\n",id,sum);
        }

        for(int i=1; i<=id; i++)
        {
            for(int j=0; j<gr[i].size(); j++)
            {
               printf("%d %d\n", gr[i][j].first, gr[i][j].second);
            }
            printf("gr=%d sum=%d\n",i,cost[i]);
            printf("\n");
        }

        //printf("id=%d\n",id);

        cnt.clear();

        n = id;
        cnt.push_back(pii(0,0));

        for(int i=1; i<=id; i++)
        {
            int x=0, y=0;
            //printf("id = %d sz=%d\n",i,gr[i].size());
            for(int j=0; j<gr[i].size(); j++)
            {
               // printf("%d %d\n", gr[i][j].first, gr[i][j].second);
                if(gr[i][j].second==0)x++;
                if(gr[i][j].second==1)y++;
                b[gr[i][j].first][gr[i][j].second]=i;
            }
            cnt.push_back(pii(x,y));
        }

        //printf("partha\n");

        int ans1 = solve1(id);
        int ans2 = solve2(id);

        printf("%d %d\n",ans1,ans2);

        for(int i=0; i<=200; i++){
            gr[i].clear();
            ed[i][0].clear();
            ed[i][1].clear();
        }

    }

    return 0;
}
