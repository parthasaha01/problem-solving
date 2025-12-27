#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int n,q,dis[mx],fin[mx],tym=-1;
vector<int>ed[mx],a;
void DFS(int u,int p)
{
    dis[u]=++tym;
    a.push_back(u);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==p)continue;
        DFS(v,u);
    }
    fin[u]=tym;
}
int solve(int u,int k)
{
    int cnt =fin[u]-dis[u]+1;
    if(k>cnt)return -1;

    int id = dis[u]+k-1;
    return a[id];
}
int main()
{
    cin>>n>>q;
    for(int i=2; i<=n; i++){
        int v; cin>>v;
        ed[i].push_back(v);
        ed[v].push_back(i);
    }

    for(int i=1; i<=n; i++){
        sort(ed[i].begin(),ed[i].end());
    }

    DFS(1,0);

//    for(int i=1; i<=n; i++){
//        printf("i=%d dis=%d fin=%d\n",i,dis[i],fin[i]);
//    }
//    for(int i=0; i<a.size(); i++){
//        printf("%d ",a[i]);
//    }
//    printf("\n");

    while(q--)
    {
        int u,k;
        cin>>u>>k;
        int ans = solve(u,k);
        cout<<ans<<endl;
    }

    return 0;
}
