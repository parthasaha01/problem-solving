#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;

int n, m;

set<int> G[MAXN + 10];

int id[MAXN + 10], ii = 0;
set<int> nvis;

int cc[MAXN + 10];

void bfs(int S)
{
    ++ii;
    queue<int> qq;
    qq.push(S);
    id[S] = ii;
    nvis.erase(S);
    set<int> :: iterator it,jt;
    while(!qq.empty())
    {
        int u = qq.front();
        qq.pop();
        cc[ii]++;
        for(it = nvis.begin(); it != nvis.end();)
        {
            if(!G[u].count(*it))
            {
                jt = it;
                ++it;
                id[*jt] = ii;
                qq.push(*jt);
                nvis.erase(jt);
            }
            else ++it;
        }
    }

}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].insert(v);
        G[v].insert(u);
    }
    for(int i = 1; i <= n; i++) nvis.insert(i);
    for(int i = 1; i <= n; i++)
    {
        if(!id[i]) bfs(i);
    }
    printf("%d\n", ii);
    sort(cc+1, cc+ii+1);
    for(int i = 1; i <= ii; i++) printf("%d ", cc[i]);
    printf("\n");
}
