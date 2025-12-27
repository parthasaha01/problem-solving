#include<bits/stdc++.h>
using namespace std;
#define mx 105
bool vis[mx],taken[mx];
int cnt;
vector<int>ed[mx];
void dfs(int u)
{
    vis[u]=true;
    taken[u]=true;
    cnt++;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(!vis[v])dfs(v);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i=1; i<=n; i++)
        {
            int x; scanf("%d",&x);
            while(x--)
            {
                int u; scanf("%d",&u);
                ed[i].push_back(u);
            }
        }

        memset(taken,false,sizeof(taken));

        int maxx=-1;
        int ans=0;

        for(int i=1; i<=n; i++)
        {
            if(taken[i]==false)
            {
                memset(vis,false,sizeof(vis));
                cnt=0;
                dfs(i);
                if(cnt>maxx){
                    maxx=cnt;
                    ans=i;
                }
            }
        }

        printf("%d\n",ans);

        for(int i=0; i<=n; i++)ed[i].clear();
    }
    return 0;
}

/*
7
1 2
1 3
0
2 5 7
2 6 2
1 7
1 2

7
1 2
2 3 7
0
2 5 7
2 6 2
1 7
0

*/
