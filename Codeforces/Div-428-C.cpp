#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>ed[mx+5];
//vector<double>ans;
double res;
int vis[mx+5];
void dfs(int u,int lv,double pr)
{
    vis[u]=1;

//    if(ed[u].size()==1)
//    {
//        //printf("%d %d\n",u,lv);
//        ans.push_back(lv);
//    }

    int cn = 0;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==0)cn++;
    }
    if(cn==0)
    {
        double xx = ((double)lv)*pr;
        res += xx;
        //ans.push_back(xx);
        return;
    }
    double npr = pr/((double)cn);

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==0)
        {
            dfs(v,lv+1,npr);
        }
    }
}
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n-1; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    res = 0.0;

    dfs(1,0,1.0);

//    int sz = ans.size();
//    double sum=0.0;
//
//    for(int i=0; i<ans.size(); i++)
//    {
//        sum += (double)ans[i];
//    }
//
//    double res = sum/((double)sz);

    printf("%.10lf\n",res);

//    for(int i=0; i<=n; i++)ed[i].clear();
//    memset(vis,0,sizeof(vis));
//    ans.clear();

    //main();

    return 0;
}

/*
6
1 2
2 3
2 5
3 4
4 6

*/
