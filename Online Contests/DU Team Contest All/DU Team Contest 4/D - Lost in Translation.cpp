#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1LL<<60)
string ss,xu,xv;
int wt;
bool vis[110];
vector<int>ed[110],ct[110];

bool bfs(int sr)
{
    for(int i=0; i<105; i++)dd[i]=inf;
    memset(vis,false,sizeof(vis));

    queue<int>qq;
    qq.push(sr);
    vis[sr]=true;
    dd[sr]=0;

    while(!qq.empty())
    {
        int u = qq.front();
        qq.pop();

        for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
            if(vis[v])continue;
            dd[v] = dd[u]+1;
            qq.push(v);
            vis[v]=true;
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        map<string,int>mp;
        ss = "English";
        mp[ss]=0;
        for(int i=1; i<=n; i++){
            cin>>ss;
            mp[ss]=i;
        }

        for(int i=1; i<=m; i++)
        {
            cin >> xu >> xv >> wt;

            ed[mp[xu]].push_back(mp[xv]);
            ed[mp[xv]].push_back(mp[xu]);

            ct[mp[xu]].push_back(wt);
            ct[mp[xv]].push_back(wt);
        }
    }

    return 0;
}

