#include<bits/stdc++.h>
using namespace std;
#define pis pair<int,string>
int fr[15],vis[10005];
vector<int>a;
int n,m;
string BFS()
{
    memset(vis,0,sizeof(vis));
    queue< pair<int,string> > Q;
    Q.push(make_pair(0,""));
    vis[0] = 1;

    while(!Q.empty())
    {
        pis pp;
        pp = Q.front();
        Q.pop();

        int v = pp.first;
        string s = pp.second;

        //if(v==0 && s!="")return s;

        //if(s.size()>100)break;

        for(int i=0; i<a.size(); i++)
        {
            if(a[i]==0&&s=="")continue;
            int u = ((v*10)+a[i])%n;
            string ss = s;
            ss += a[i]+'0';
            //cout << u << " " << ss <<" " << vis[u] << endl;
            if(u==0)return ss;
            if(vis[u]==0){
               Q.push(make_pair(u,ss));
               vis[u] = 1;
            }
        }
    }
    return "-1";
}
int main()
{
    int ks=0;
    ios :: sync_with_stdio(false); cin.tie(0);

    while(cin>>n>>m)
    {
        memset(fr,0,sizeof(fr));
        for(int i=1; i<=m; i++){
            int x; cin>>x;
            fr[x] = 1;
        }

        a.clear();
        for(int i=0; i<10; i++){
            if(fr[i]==0)a.push_back(i);
        }

        cout << "Case " << ++ks << ": " << BFS() << endl;
        //cout << BFS().size() << endl;
    }
    return 0;
}
