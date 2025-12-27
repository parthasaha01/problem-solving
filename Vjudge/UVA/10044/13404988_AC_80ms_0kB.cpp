#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
map<string, int>mp;
vector<int>vv;
vector<int>ed[100005];
int n,vis[100005],d[100005];
void BFS(int src)
{
    for(int i=0; i<=n; i++) d[i] = inf;
    memset(vis,0,sizeof(vis));
    d[src] = 0;
    queue<int>q;
    q.push(src);
    vis[src]=1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<ed[u].size(); i++)
        {
            int v = ed[u][i];
            if(d[v]>1+d[u])
            {
                d[v] = 1+d[u];
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int tt;
    cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cout << "Scenario " << ks << endl;
        int p,q;
        cin>>p>>q;
        getchar();
        n=0;
        mp.clear();


        for(int x=1; x<=p; x++)
        {
            string s;

            getline(cin,s);
            // cout << s << endl;
            string nd;
            vv.clear();
            int coma = 0;

            for(int i=0; i<s.size(); i++)
            {
                if(s[i]==':')
                {
                    if(mp.find(nd)==mp.end())mp[nd]=++n;
                    vv.push_back(mp[nd]);
                    nd = "";
                    coma = 0;

                    for(int u=0; u<vv.size(); u++)
                    {
                        for(int v=0; v<vv.size(); v++)
                        {
                            if(vv[u]==vv[v]) continue;
                            ed[vv[u]].push_back(vv[v]);
                            ed[vv[v]].push_back(vv[u]);
                        }
                    }

                    break;
                }
                else if(s[i]==',')
                {
                    if(coma==0){
                        nd += s[i];
                        coma++;
                    }
                    else{
                        if(mp.find(nd)==mp.end())
                        mp[nd]=++n;
                        vv.push_back(mp[nd]);
                        nd = "";
                        coma = 0;
                        i++;
                    }
                }
                else
                {
                    nd+=s[i];
                }
            }

        }

        BFS(mp["Erdos, P."]);

//        for (auto& x: mp)
//        {
//            std::cout << x.first << " - " << x.second << '\n';
//        }

        for(int i=1; i<=q; i++)
        {
            string nd;
            getline(cin,nd);

            if(mp.find(nd)!=mp.end())
            {
                if(vis[mp[nd]]!=0)
                {
                    cout << nd << " " << d[mp[nd]] << endl;
                }
                else
                {
                    cout << nd << " " << "infinity" << endl;
                }
            }
            else{
                cout << nd << " " << "infinity" << endl;
            }
        }

        for(int i=0; i<=100000; i++) ed[i].clear();
    }
    return 0;
}
