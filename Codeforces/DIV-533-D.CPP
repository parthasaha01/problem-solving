#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,m,p,cnt,s[15],ans[15],d[1005][1005];
string grid[1005],temp[1005];
vector<pii>q[10];
int fx[] = {-1,+0,+0,+1};
int fy[] = {+0,-1,+1,+0};
struct dt{
    int _x,_y,_s;
};
bool isValid(int x, int y,int c){
    if(x<0||y<0||x>=n||y>=m)return false;
    if(grid[x][y]=='.') return true;
    if(grid[x][y]==(c+'0')) return true;
    return false;
}
void fun(int x){
    vector<pii>v;
    queue<dt>qq;
    for(int i=0; i<q[x].size(); i++){
        int _x = q[x][i].first;
        int _y = q[x][i].second;
        qq.push({_x,_y,s[x]});
    }

    while(!qq.empty()){
        dt u = qq.front();
        qq.pop();
        int _x = u._x;
        int _y = u._y;
        int _s = u._s;

        for(int k=0; k<4; k++){
            int tx = _x + fx[k];
            int ty = _y + fy[k];
            if(isValid(tx,ty,x) && _s-1 > d[tx][ty]){
                qq.push({tx,ty,_s-1});
                d[tx][ty] = _s-1;
                grid[tx][ty] = x+'0';
                v.push_back(make_pair(tx,ty));
                cnt++;
            }
        }
    }

    q[x].clear();
    q[x] = v;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m>>p;
    for(int i=1; i<=p; i++)cin>>s[i];
    for(int i=0; i<n; i++){
        cin>>grid[i];
        temp[i] = grid[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]>='1' && grid[i][j]<='9'){
                int x = grid[i][j]-'0';
                q[x].push_back(make_pair(i,j));
            }

        }
    }

    cnt = 0;
    memset(d,-1,sizeof(d));
    for(int i=1; i<=p; i++){

        fun(i);

        if(i==p){
            if(cnt==0)break;
            i = 0;
            cnt = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]>='1' && grid[i][j]<='9'){
                int x = grid[i][j]-'0';
                ans[x]++;
            }
        }
    }

    for(int i=1; i<=p; i++){
        if(i==p)cout<<ans[i]<<endl;
        else cout<<ans[i]<<" ";
    }

    return 0;
}
