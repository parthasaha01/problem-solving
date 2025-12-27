#include<bits/stdc++.h>
using namespace std;
string cell[15];
int n;
int cost[15][15];
bool vis[15][15];
int fx[]={-1,+0,+0,+1};
int fy[]={+0,-1,+1,+0};
struct dt
{
    int x,y;
}st[30];
bool valid(int tx, int ty,int ch)
{
    if(tx>=0&&tx<n&&ty>=0&&ty<n&&cell[tx][ty]!='#'&&(cell[tx][ty]<=ch||cell[tx][ty]=='.')&&vis[tx][ty]==false){
        return true;
    }
    return false;
}
int bfs(int sx,int sy,int dx,int dy,char ch)
{
    memset(vis,false,sizeof(vis));
    cost[sx][sy]=0;
    vis[sx][sy]=true;
    queue<int>q;
    q.push(sx);
    q.push(sy);

    while(!q.empty())
    {
        int ux=q.front();
        q.pop();
        int uy=q.front();
        q.pop();

        if(ux==dx&&uy==dy){
            return cost[ux][uy];
        }

        for(int k=0; k<4; k++)
        {
            int tx=ux+fx[k];
            int ty=uy+fy[k];

            if(valid(tx,ty,ch))
            {
                cost[tx][ty]=cost[ux][uy]+1;
                vis[tx][ty]=true;
                q.push(tx);
                q.push(ty);
            }
        }
    }

    if(vis[dx][dy]==false){
        return -1;
    }
    else{
        return cost[dx][dy];
    }
}
int main()
{
    int t;
    cin>>t;

    for(int ks=1; ks<=t; ks++)
    {
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>cell[i];
        }

        int letter=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(cell[i][j]>='A'&&cell[i][j]<='Z'){
                    int ch=cell[i][j]-'A';
                    st[ch].x=i;
                    st[ch].y=j;
                    letter++;
                }
            }
        }

        int ans=0;
        bool flag=true;
        for(int i=0; i<letter-1; i++)
        {
            int sx,sy,dx,dy;
            sx=st[i].x;
            sy=st[i].y;
            dx=st[i+1].x;
            dy=st[i+1].y;
            char ch=cell[dx][dy];
            int cnt=bfs(sx,sy,dx,dy,ch);
            //cout << ch << " " << cnt << endl;
            if(cnt==-1){
                flag=false;
                break;
            }
            ans+=cnt;
        }

        if(flag){
            printf("Case %d: %d\n",ks,ans);
        }
        else{
            printf("Case %d: Impossible\n",ks);
        }
    }

    return 0;
}
/*
10

3
ABC
DEF
...

6
ABCDEF
GHIJKL
MNOPQR
STUVWX
YZ####
......

2
AC
BD

10
A........L
B#..E..J..
D#G.......
C##RF....K
....P.....
....Q.....
..HTSWO...
..UV......
......I...
...N.....M

8
UGM.L...
#..#.K.N
#.JVIA..
...#..S.
#.#PC#..
.XFR.O..
HDQ#.#.E
..B..T.W

8
.####.##
#..##...
........
#.###.A.
#..B#.#.
#...#C.#
..#....D
####....

*/
