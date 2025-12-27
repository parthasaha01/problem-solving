#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int MAXN = 50005;
const int MAXC = 500005;
const int INF = 1000000000;
struct Point{
    int x,y,id;
    Point(int a=0,int b=0, int c=0){
        x = a, y = b, id = c;
    }
}p[MAXN];
bool operator < (const Point &u, const Point &v){
    return u.y<v.y;
}
vector<Point>vv[MAXC];
vector<int>adj[MAXN];
queue<int>qq;
int n,col[50005];

int BFS(int s) // Bicoloring
{
    int c0=0,c1=0;
    col[s]=0;
    c0++;
    qq.push(s);

    while(!qq.empty())
    {
        int u = qq.front();
        qq.pop();
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
void edgeCreate()
{
    for(int i=1; i<=MAXC; i++)
        sort(vv[i].begin(),vv[i].end());

    for(int i=1; i<=n; i++){
        int ux  = p[i].x;
        int uy  = p[i].y;
        int uid = p[i].id;

        int leftX  = max(1, ux-5);
        int rightX = min(MAXC, ux+5);

        for(int x=leftX; x<=rightX; x++){
            int minY = max(1, uy-5);
            int maxY = min(MAXC, uy+5);

            int lo = (int)(lower_bound(vv[x].begin(),vv[x].end(),Point(-INF,minY,-INF))-vv[x].begin());
            int hi = (int)(upper_bound(vv[x].begin(),vv[x].end(),Point(-INF,maxY,-INF))-vv[x].begin());

            for(int k=lo; k<hi; k++){
                int vx  = vv[x][k].x;
                int vy  = vv[x][k].y;
                int vid = vv[x][k].id;
                if(uid==vid)continue;
                int d = (ux-vx)*(ux-vx)+(uy-vy)*(uy-vy);
                if(d<=25){
                    adj[uid].pb(vid);
                    adj[vid].pb(uid);
                }
            }
        }
    }
}
int solve()
{
    edgeCreate();

    memset(col,-1,sizeof(col));
    int ret = 0;

    for(int i=1; i<=n; i++){
        if(col[i]==-1){
            ret += BFS(i);
        }
    }

    return ret;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            int x,y; scanf("%d%d",&x,&y);
            p[i].x  = x;
            p[i].y  = y;
            p[i].id = i;
            vv[x].pb(Point(x,y,i));
        }

        int ans = solve();
        printf("%d\n",ans);

        for(int i=0; i<MAXC; i++)vv[i].clear();
        for(int i=0; i<MAXN; i++)adj[i].clear();
    }
    return 0;
}
