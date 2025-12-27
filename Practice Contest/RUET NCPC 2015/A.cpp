#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define D double
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define SZ 105
#define MOD 1000000007
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define mem(a, b) memset(a, b, sizeof a)
const int inf = INT_MAX;

int r, c;
char ss[SZ][SZ], dd[SZ][SZ];
int d[SZ][SZ];
bool seen[SZ][SZ];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y)
{
    if(x>=0 && x<r && y>=0 && y<c && seen[x][y]==0) return 1;
    return 0;
}

int bfs(int x, int y)
{
    mem(seen, 0);
    seen[x][y] = 1;
    d[x][y] = 0;

    queue<int>q;
    q.push(x); q.push(y);

    while(!q.empty())
    {
        x = q.front(); q.pop();
        y = q.front(); q.pop();

        if(ss[x][y]=='#') return d[x][y];

        for(int i=0; i<4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(valid(xx, yy)) {
                d[xx][yy] = d[x][y] + 1;
                seen[xx][yy] = 1;
                q.push(xx); q.push(yy);
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int ks = 0;
    while(sff(r, c)==2)
    {
        if(r==0 && c==0) break;

        for(int i=0; i<r; i++) scanf("%s", ss[i]);
        for(int i=0; i<r; i++) scanf("%s", dd[i]);

        int ans = -inf;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(dd[i][j]=='#') {
                    ans = max(ans, bfs(i, j));
                }
            }
        }

        printf("Case %d: %d\n", ++ks, ans);
    }

    return 0;
}
