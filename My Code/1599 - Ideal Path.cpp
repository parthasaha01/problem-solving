#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mx 100005
int d[mx],col[mx],par[mx];
int n,m;
map<pair<int,int>,int>mp;
vector<int>ed[mx];
void BFS()
{
    memset(par,0,sizeof(par));
    for(int i=0; i<=n; i++)d[i] = 1000000005;
    for(int i=0; i<=n; i++)col[i] = 1000000005;
    d[1] = 0;
    col[1]=0;
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(u==n)return;

        for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
            int x = u, y = v;
            if(x>y)swap(x,y);
            pii p = make_pair(x,y);
            int c = mp[p];
            if(d[v]>d[u]+1){
                col[v] = c;
                par[v] = u;
                d[v] = d[u]+1;
                q.push(v);
            }
            else if(d[v]==d[u]+1){
                if(c<col[v]){
                    col[v] = c;
                    par[v] = u;
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        mp.clear();

        for(int i=1; i<=m; i++)
        {
            int u,v,c; scanf("%d%d%d",&u,&v,&c);
            if(u>v)swap(u,v);
            if(u==v)continue;
            pii p = make_pair(u,v);
            if(mp.find(p)==mp.end()){
                ed[u].push_back(v);
                ed[v].push_back(u);
                mp[p] = c;
            }
            else {
                mp[p] = min(mp[p],c);
            }
        }

        BFS();

        stack<int>st;
        int node = n;
        while(node!=1)
        {
            st.push(col[node]);
            node = par[node];
        }
        int k = st.size();
        printf("%d\n",d[n]);
        for(int i=0; i<k; i++){
            if(i==k-1)printf("%d\n",st.top());
            else printf("%d ",st.top());
            st.pop();
        }

        for(int i=1; i<=n; i++)ed[i].clear();
    }
    return 0;
}
