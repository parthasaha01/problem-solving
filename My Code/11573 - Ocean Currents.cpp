#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int fx[] = {-1,-1,+0,+1,+1,+1,+0,-1};
int fy[] = {+0,+1,+1,+1,+0,-1,-1,-1};
int r,c,d[1005][1005];
string s[1005];
int BFS(int sx,int sy,int dx,int dy)
{
    if(sx==dx && sy==dy)return 0;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            d[i][j] = 1000000000;
        }
    }

    deque< pair<int,int> > Q;
    d[sx][sy] = 0;
    Q.push_front(make_pair(sx,sy));

    while(!Q.empty())
    {
        int ux = Q.front().first;
        int uy = Q.front().second;
        Q.pop_front();

        if(ux==dx&&uy==dy)return d[dx][dy];

        for(int k=0; k<8; k++){
            int vx = ux+fx[k];
            int vy = uy+fy[k];
            if(vx<0||vx>=r||vy<0||vy>=c)continue;
            int w = d[ux][uy]+1;
            if(k==(s[ux][uy]-'0'))w = d[ux][uy];
            if(w<d[vx][vy]){
                d[vx][vy] = w;
                if(k==(s[ux][uy]-'0'))Q.push_front(make_pair(vx,vy));
                else Q.push_back(make_pair(vx,vy));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>r>>c;
    for(int i=0; i<r; i++)cin>>s[i];
    int q; cin>>q;
    while(q--)
    {
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        sx--,sy--,dx--,dy--;

        int ans = BFS(sx,sy,dx,dy);
        cout << ans << endl;
    }
    return 0;
}
