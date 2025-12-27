#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
queue< pii >qq;
unordered_set<int>ss;
vector<int>ed[10005];
map< pii,int > vs;
int a[10005];
void BFS()
{
    while(!qq.empty())
    {
        pii nd = qq.front();
        qq.pop();

        int u = nd.first;
        int w = nd.second;

        for(int i=0; i<ed[u].size(); i++)
        {
            int v = ed[u][i];
            int g = __gcd(w,a[v]);

            if(vs.find(mp(v,g))==vs.end())
            {
                ss.insert(g);
                vs[mp(v,g)]=1;
                qq.push(mp(v,g));
            }
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        for(int i=1; i<=m; i++){
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        ss.clear();
        vs.clear();

        for(int i=1; i<=n; i++){
            vs[mp(i,a[i])]=1;
            qq.push(mp(i,a[i]));
            ss.insert(a[i]);
        }

        BFS();

        int ans = ss.size();
        printf("%d\n",ans);

        for(int i=0; i<=n; i++)ed[i].clear();
    }

    return 0;
}
