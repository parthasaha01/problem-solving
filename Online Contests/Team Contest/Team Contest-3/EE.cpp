#include<bits/stdc++.h>
using namespace std;
#define mx 100002
vector<int>graph[mx+5];
int node[mx+5],mxdepth[mx+5];
map<pair<int, int>, int >depth;

int dfs1(int u)
{
    if(graph[u].size()==0){
         depth[make_pair(u,0)]=1;
        return 0;
    }

    int ret = 0;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        ret =max(ret, 1+dfs1(v));
    }

    depth[make_pair(u,0)]=1;
    for(int i=0; i<graph[u].size(); i++){
        int v = graph[u][i];
        for(int k=0; k<mxdepth[v]; k++){
            pair<int,int>p=make_pair(v,k);
            depth[make_pair(u,k+1)]+=depth[p];
        }
    }

    return mxdepth[u]=ret;
}
int dfs2(int u)
{
    if(graph[u].size()==0){
        node[u]=0;
        return 0;
    }

    int ret = 0;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        int n1=1+dfs2(v);
        ret +=n1;
    }

    return node[u] = ret;
}
int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        memset(node,0,sizeof(node));
        for(int i=0; i<=n; i++) graph[i].clear();
        depth.clear();

        for(int i=1; i<=n-1; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }

        dfs1(1);
        dfs2(1);

        for(int i=1; i<=n; i++)node[i]++;

        //map<pair<int, int>, int>m;
        map<pair< int, map<pair<int, int>, int > >, int >m;

        for(int i=1; i<=n; i++) {
            m[make_pair(node[i], depth)]++;
        }

        map<pair< int, map<pair<int, int>, int > >, int > :: iterator it;
        long long ans=0;
        for(it= m.begin(); it!=m.end(); it++) {
            long long var = it->second;
            ans+=((var)*(var-1))/2;
        }

        printf("%lld\n",ans);

    }

    return 0;
}
