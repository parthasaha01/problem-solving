#include<bits/stdc++.h>
using namespace std;
#define mx 200005
set<int>ss;
set<int>ed[mx+5];
int n,m,a[mx+5],vis[mx+5],cnt;
void BFS(int s)
{
    vis[s] = 1;
    ss.erase(s);
    queue<int>qq;
    qq.push(s);
    cnt++;
    set<int> :: iterator it,jt;

    while(!qq.empty())
    {
        int u = qq.front(); qq.pop();

        for(it=ss.begin(); it!=ss.end();)
        {
            if(ed[u].find(*it)==ed[u].end())
            {
                jt = it;
                it++;
                cnt++;
                vis[*jt]=1;
                qq.push(*jt);
                ss.erase(*jt);
            }else{
                it++;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        ed[u].insert(v);
        ed[v].insert(u);
    }

    for(int i=1; i<=n; i++){
        ss.insert(i);
    }

    int k=0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            cnt = 0;
            BFS(i);
            a[++k] = cnt;
        }
    }

    sort(a+1,a+k+1);

    printf("%d\n",k);
    for(int i=1; i<=k; i++)
    {
        if(i==k)printf("%d\n",a[i]);
        else printf("%d ",a[i]);
    }

    return 0;
}
