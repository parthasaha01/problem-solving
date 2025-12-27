#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef pair<int,int> pii;
map<pii,int>mp;
vector<pii>circle;
vector<int>adj[50005];
queue<int>qq;
int col[50005];
struct Point{
    int x,y;
}p[50005];

int BFS(int s)
{
    int c0=0,c1=0;
    col[s]=0;
    c0++;
    qq.push(s);

    //printf("\n");

    while(!qq.empty())
    {
        int u = qq.front();
        qq.pop();
        //printf("%d %d\n",u,col[u]);
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(col[v]==-1){
                col[v] = 1-col[u];
                if(col[v]==1)c1++;
                else c0++;
                qq.push(v);
            }
        }
    }

    return min(c0,c1);
}
int main()
{
    for(int i=-5; i<=5; i++){
        for(int j=-5; j<=5; j++){
            if((i*i)+(j*j)<=25){
                circle.pb(pii(i,j));
            }
        }
    }

    int n;
    while(scanf("%d",&n)==1)
    {
        mp.clear();

        for(int i=1; i<=n; i++){
            scanf("%d%d",&p[i].x,&p[i].y);
            mp[pii(p[i].x,p[i].y)] = i;
        }

        for(int i=1; i<=n; i++){
            for(int j=0; j<circle.size(); j++){
                int nx = p[i].x + circle[j].first;
                int ny = p[i].y + circle[j].second;
                if(mp.find(pii(nx,ny)) != mp.end()){
                    adj[i].pb(mp[pii(nx,ny)]);
                    adj[mp[pii(nx,ny)]].pb(i);
                }
            }
        }

        int ans = 0;
        memset(col,-1,sizeof(col));

        for(int i=1; i<=n; i++){
            if(col[i]==-1){
                ans += BFS(i);
            }
        }

        printf("%d\n",ans);

        for(int i=0;i<=n; i++)adj[i].clear();
    }

    return 0;
}
/*
4
0 0
3 4
3 3
4 3
*/