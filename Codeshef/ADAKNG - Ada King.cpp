#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int fx[] = {-1,-1,-1,+0,+0,+0,+1,+1,+1};
int fy[] = {-1,+0,+1,-1,+0,+1,-1,+0,+1};
int grid[9][9],vis[9][9][9];
struct dt{
    int x,y,s;
};
bool isvalid(int x,int y,int s){
    if(x<1||x>8||y<1||y>8) return false;
    if(vis[x][y][s]==1)return false;
    return true;
}
int fun(int x,int y,int k){
    memset(grid,0,sizeof(grid));
    memset(vis,0,sizeof(vis));
    grid[x][y] = 1;
    vis[x][y][k] = 1;
    queue<dt>qq;
    qq.push({x,y,k});
    while(!qq.empty()){
        dt u = qq.front();
        qq.pop();
        int x = u.x;
        int y = u.y;
        int s = u.s;

        if(s<=0)continue;

        for(int i=0; i<9; i++){
            int tx = x+fx[i];
            int ty = y+fy[i];
            if(isvalid(tx,ty,s-1)){
                grid[tx][ty] = 1;
                vis[tx][ty][s-1] = 1;
                qq.push({tx,ty,s-1});
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            if(grid[i][j]==1){
                cnt++;
                //cout<<i<<" "<<j<<endl;
            }
        }
    }

    return cnt;
}
int main(){
    int tt; cin>>tt;
    while(tt--){
        int x,y,k; cin>>x>>y>>k;
        int ans = fun(x,y,k);
        cout<<ans<<endl;
    }
    return 0;
}
