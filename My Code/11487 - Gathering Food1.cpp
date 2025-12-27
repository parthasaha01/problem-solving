#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=20437;
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};
string ss[12];
int n,vis[15][15],cost[15][15];
ll dp[11][11][101];
struct node{
    int x,y;
    node(int _x=0,int _y=0){
        x = _x; y =_y;
    }
}st[30];
int valid(int x,int y,char ch)
{
    if(x<0||x>=n||y<0||y>=n||ss[x][y]=='#'||vis[x][y]==1)return 0;
    if(ss[x][y]=='.')return 1;
    if(ss[x][y]<=ch)return 1;
    return 0;
}
ll BFS(int sx,int sy,int dx,int dy,char ch)
{
    memset(vis,0,sizeof(vis));
    memset(cost,-1,sizeof(cost));
    queue<node>qq;
    qq.push(node(sx,sy));
    vis[sx][sy]=1;
    cost[sx][sy]=0;

    while(!qq.empty())
    {
        node u = qq.front();
        qq.pop();

        if(u.x==dx&&u.y==dy)return cost[dx][dy];

        for(int k=0; k<4; k++){
            int x = u.x + fx[k];
            int y = u.y + fy[k];
            if(valid(x,y,ch)){
                qq.push(node(x,y));
                cost[x][y] = 1+cost[u.x][u.y];
                vis[x][y] = 1;
            }
        }
    }

    return -1;
}
ll fun(int x,int y,int w,char ch,int px,int py)
{
    if(w<0)return 0;
    if(ss[x][y]==ch){
        if(w>=0)return 1LL;
        else return 0LL;
    }

    if(dp[x][y][w]!=-1)return dp[x][y][w];
    ll ret = 0;
    for(int k=0; k<4; k++){
        int vx = x + fx[k];
        int vy = y + fy[k];
        if(vx==px&&vy==py)continue;
        if(vx>=0&&vx<n&&vy>=0&&vy<n&&ss[vx][vy]!='#'){
            if(ss[vx][vy]>='A'&&ss[vx][vy]<='Z'){
                if(ss[vx][vy]<=ch){
                    ret += fun(vx,vy,w-1,ch,x,y);
                    ret %= MOD;
                }
            }
            else{
                ret += fun(vx,vy,w-1,ch,x,y);
                ret %= MOD;
            }
        }
    }
        return dp[x][y][w] = ret;
}



int main()
{
    int ks = 0;
    while(cin>>n && n)
    {
        for(int i=0; i<n; i++)cin>>ss[i];

        int letter=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(ss[i][j]>='A'&&ss[i][j]<='Z'){
                    int id=ss[i][j]-'A';
                    st[id].x=i;
                    st[id].y=j;
                    letter++;
                }
            }
        }

        ll ans=0;
        bool flag=true;
        ll way = 1LL;

        for(int i=0; i<letter-1; i++)
        {
            int sx,sy,dx,dy;
            sx=st[i].x; sy=st[i].y;
            dx=st[i+1].x; dy=st[i+1].y;
            char ch=ss[dx][dy];
            ll cnt=BFS(sx,sy,dx,dy,ch);
           // printf("sx=%d sy=%d dx=%d dy=%d\n",sx,sy,dx,dy);
            //cout << ch << " " << cnt << endl;
            if(cnt==-1){
                flag=false;
                break;
            }
            ans+=cnt;

            memset(dp,-1,sizeof(dp));
            ll res = fun(sx,sy,cnt,ch,15,15);

            way = ((way%MOD)*(res%MOD))%MOD;
        }

        if(flag){
            printf("Case %d: %lld %lld\n",++ks,ans,way);
        }
        else{
            printf("Case %d: Impossible\n",++ks);
        }
    }
    return 0;
}
