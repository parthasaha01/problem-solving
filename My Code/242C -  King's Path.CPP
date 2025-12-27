#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define sc second
map< pair<int,int>, int>gg;
map< pair<int,int>, int>vs;
int fx[]={-1,-1,-1,+0,+0,+1,+1,+1};
int fy[]={-1,+0,+1,-1,+1,-1,+0,+1};
int BFS(int sx,int sy,int dx,int dy)
{
    if(sx==dx&&sy==dy)return 0;
    queue < pair< pair<int,int>, int > > Q;
    Q.push(mp(mp(sx,sy),0));
    vs[mp(sx,sy)]=1;
    while(!Q.empty())
    {
        auto u = Q.front();
        Q.pop();

        int x = u.fi.fi;
        int y = u.fi.sc;
        int w = u.sc;

        for(int k=0; k<8; k++){
            int xx = x+fx[k];
            int yy = y+fy[k];

            if(gg.find(mp(xx,yy))==gg.end())continue;
            if(vs.find(mp(xx,yy))!=vs.end())continue;

            if(xx==dx&&yy==dy)return w+1;
            vs[mp(xx,yy)]=1;
            Q.push(mp(mp(xx,yy),w+1));
        }
    }

    return -1;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int sx,sy,dx,dy;
    cin>>sx>>sy>>dx>>dy;

    int q; cin>>q;
    while(q--){
        int r,a,b; cin>>r>>a>>b;
        for(int i=a; i<=b; i++){
            gg[mp(r,i)]=1;
        }
    }

    cout << BFS(sx,sy,dx,dy) << endl;

    return 0;
}
