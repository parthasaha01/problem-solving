#include<bits/stdc++.h>
using namespace std;
struct dt{
    string u,v;
}st[205];
set<string>ss;
map<string, int>mp;
//map<int, string>sp;
vector<int>ed[405];
int DFS(int u)
{
   // cout << u << " " << sp[u] << endl;

    if(ed[u].size()==0)return 1;

    int ret = 0;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        ret = max(ret,1+DFS(v));
    }
    return ret;
}
int main()
{
    int n; cin>>n;
    for(int i=1; i<=n; i++)
    {
        string u,w,v;
        cin>>u>>w>>v;
        for(int k=0; k<u.size(); k++){
            if(u[k]>='A'&&u[k]<='Z'){
                u[k] += 32;
            }
        }
        for(int k=0; k<v.size(); k++){
            if(v[k]>='A'&&v[k]<='Z'){
                v[k] += 32;
            }
        }
        ss.insert(u);
        ss.insert(v);
        st[i].u = u;
        st[i].v = v;
    }


    set<string> ::  iterator it;
    int x = 0;
    for(it = ss.begin(); it!=ss.end(); it++)
    {
        mp[*it]=++x;
        //sp[x]=*it;
        //cout << sp[x] << " " << x << " " << mp[sp[x]] << endl;
    }

    for(int i=1; i<=n; i++)
    {
        int u = mp[st[i].u];
        int v = mp[st[i].v];
        ed[v].push_back(u);
    }

    int ans = DFS(mp["polycarp"]);

    cout << ans << endl;

    return 0;
}
