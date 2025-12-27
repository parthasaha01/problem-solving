#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct dt{
    string uu,vv;
}st[mx+5];
vector<int>ed[mx+5];
bool vs[mx+5];
int pa[mx+5];
void bfs(int sr)
{
    memset(pa,-1,sizeof(pa));
    memset(vs,false,sizeof(vs));

    queue<int>qq;
    qq.push(sr);
    vs[sr] = true;

    while(!qq.empty())
    {
        int u = qq.front();
        qq.pop();

        for(int i=0; i<ed[u].size(); i++)
        {
            int v = ed[u][i];

            if(vs[v]==false)
            {
                vs[v] = true;
                pa[v] = u;
                qq.push(v);
            }
        }
    }

}
int main()
{
    int m;
    int ks=0;
    while(cin>>m)
    {
        if(ks)cout << endl;
        ks=1;

        set<string>ss;
        for(int i=1; i<=m; i++)
        {
            string uu,vv;
            cin >> uu >> vv;
            st[i].uu = uu;
            st[i].vv = vv;
            ss.insert(uu);
            ss.insert(vv);
        }

        string src,des;
        cin>>src>>des;
        ss.insert(src);
        ss.insert(des);

        int n = ss.size();
        int k = 0;
        map<string,int>mp;
        map<int,string>pp;
        set<string>::iterator it;

        for(it=ss.begin(); it!=ss.end(); it++)
        {
            mp[*it] = ++k;
            pp[k] = *it;
        }

        for(int i=0; i<=n; i++)ed[i].clear();

        for(int i=1; i<=m; i++)
        {
            string uu,vv;
            uu = st[i].uu;
            vv = st[i].vv;
            int u,v;
            u = mp[uu];
            v = mp[vv];
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        int sr = mp[src];
        int ds = mp[des];

        bfs(sr);

        if(vs[ds]==false)printf("No route\n");
        else
        {
            if(sr==ds) cout << pp[sr] << " " << pp[ds] << endl;
            else
            {
                vector<int>pt;
                pt.push_back(ds);
                int xx = ds;

                while(pa[xx]!=-1)
                {
                    xx = pa[xx];
                    pt.push_back(xx);
                }

                reverse(pt.begin(),pt.end());

                for(int i=0; i<pt.size()-1; i++)
                {
                    cout << pp[pt[i]] << " " << pp[pt[i+1]] << endl;
                }
            }
        }
    }

    return 0;
}
