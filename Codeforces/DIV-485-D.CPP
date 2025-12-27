#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx],ans[mx],vis[mx],c[105];
int n,m,k,s;
vector<int>ed[mx];
int BFS(int src)
{
    vis[src] = src;
    memset(c,0,sizeof(c));
    c[a[src]]=1;
    queue< pair<int,int> >q;
    q.push(make_pair(src,0));
    int sum = 0;
    int cnt = 1;
    if(cnt==s)return 0;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int u = p.first;
        int w = p.second;

        for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
            if(vis[v]<src){
                if(c[a[v]]==0){
                    sum += w+1;
                    cnt++;
                }
               // printf("src=%d u=%d v=%d w=%d sum=%d\n",src,u,v,w,sum);
                if(cnt>=s)return sum;
                vis[v] = src;
                c[a[v]] = 1;
                q.push(make_pair(v,w+1));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&s);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    for(int i=1; i<=m; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        ans[i] = BFS(i);
    }


    for(int i=1; i<=n; i++){
        if(i==n)printf("%d\n",ans[i]);
        else printf("%d ",ans[i]);
    }

    return 0;
}
