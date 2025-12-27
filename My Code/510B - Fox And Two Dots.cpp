#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};
int r,c,vis[55][55];
string s[55];
bool valid(int x,int y,char ch)
{
    if(x<0||x>=r||y<0||y>=c||s[x][y]!=ch)return false;
    return true;
}
int DFS(int ux,int uy,int px,int py,char ch)
{
    vis[ux][uy]=1;
    int ret = 0;
    for(int k=0; k<4; k++){
        int vx = ux+fx[k];
        int vy = uy+fy[k];
        if(!valid(vx,vy,ch))continue;
        if(vx==px&&vy==py)continue;
        if(vis[vx][vy]==1){
            return 1; break;
        }
        ret |= DFS(vx,vy,ux,uy,ch);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>r>>c;

    for(int i=0; i<r; i++)cin>>s[i];
    memset(vis,0,sizeof(vis));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(vis[i][j]==0){
                bool flag = DFS(i,j,i,j,s[i][j]);
                if(flag){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}

