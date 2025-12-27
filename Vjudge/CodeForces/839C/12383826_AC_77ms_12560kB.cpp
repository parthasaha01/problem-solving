#include<bits/stdc++.h>
using namespace std;
vector<int>ed[100005];
double ans;
void DFS(int u,int pr,int lv,double prob)
{
    int sz = ed[u].size();
    if(u!=1)sz--;

    if(sz==0){
        ans += (lv*prob);
        return;
    }

    double np = prob/sz;
    double ret = 0.0;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;
        DFS(v,u,lv+1,np);
    }
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    DFS(1,0,0,1.0);

    printf("%.15lf\n",ans);

    return 0;
}
