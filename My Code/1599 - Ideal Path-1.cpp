#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mx 100005
int sd[mx],dd[mx],vis[mx],ok[mx];
int n,m;
map<pair<int,int>,int>mp;
vector<int>ed[mx],level[mx];
vector<int>ans;
void BFS1(int src,int des,int* d)
{
    for(int i=0; i<=n; i++)d[i] = 1000000005;
    d[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
            if(d[v]>d[u]+1){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
}
void BFS2()
{
    for(int i=0; i<=n; i++)vis[i]=0;
    vis[1]=1;
    for(int k=0; k<sd[n]; k++)
    {
        int c = 1000000005;
        for(int j=0; j<level[k].size(); j++)
        {
            int u = level[k][j];
            if(vis[u]==0)continue;
            for(int i=0; i<ed[u].size(); i++){
                int v = ed[u][i];
                if(!ok[v])continue;
                if(sd[v]<=k)continue;
                int x = u, y = v;
                if(x>y)swap(x,y);
                pii p = make_pair(x,y);
                c = min(c,mp[p]);
            }
        }
        for(int j=0; j<level[k].size(); j++)
        {
            int u = level[k][j];
            if(vis[u]==0)continue;
            for(int i=0; i<ed[u].size(); i++){
                int v = ed[u][i];
                if(!ok[v])continue;
                if(sd[v]<=k)continue;
                int x = u, y = v;
                if(x>y)swap(x,y);
                pii p = make_pair(x,y);
                if(mp[p]==c)vis[v]=1;
            }
        }

        ans.push_back(c);
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

//        for(int i=1; i<=n; i++){
//            for(int j=i+1; j<=n; j++){
//                cout<<"u="<<i<<" v="<<j<<" mp=" << mp[make_pair(i,j)]<<endl;
//            }
//        }

        BFS1(1,n,sd);
        BFS1(n,1,dd);

//        for(int i=1; i<=n; i++){
//            printf("i=%d sd[i]=%d dd[i]=%d tot=%d\n",i,sd[i],dd[i],sd[i]+dd[i]);
//        }

        memset(ok,0,sizeof(ok));
        int ret = sd[n];
        for(int i=1; i<=n; i++){
            if(ret==(sd[i]+dd[i])){
                ok[i] = 1;
            }
        }

        for(int i=1; i<=n; i++){
            if(ok[i]){
                level[sd[i]].push_back(i);
            }
        }

        //cout << "patyha" << endl;

        BFS2();

        int k = ans.size();
        printf("%d\n",ret);
        for(int i=0; i<k; i++){
            if(i==k-1)printf("%d\n",ans[i]);
            else printf("%d ",ans[i]);

        }

        for(int i=1; i<=n; i++)ed[i].clear(),level[i].clear();
        ans.clear();
    }
    return 0;
}

