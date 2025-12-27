#include<bits/stdc++.h>
using namespace std;
#define mx 500005
unordered_set<int>node;
unordered_set<int>forbid[mx+5];
vector<int>gr[mx+5];
int n,m,a[mx+5],vis[mx+5],cnt;
void BFS(int s,int id)
{
    vis[s] = 1;
    gr[id].push_back(s);
    node.erase(s);
    queue<int>qq;
    qq.push(s);
    cnt++;
    unordered_set<int> :: iterator it,jt;

    while(!qq.empty())
    {
        int u = qq.front(); qq.pop();

        for(it=node.begin(); it!=node.end();)
        {
            int x = min(u,*it);
            int y = max(u,*it);
            if(forbid[x].find(y)==forbid[x].end())
            {
                jt = it;
                it++;
                cnt++;
                vis[*jt]=1;
                gr[id].push_back(*jt);
                qq.push(*jt);
                node.erase(*jt);
            }
            else it++;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++){
        int u,v; scanf("%d%d",&u,&v);
        if(u>v)swap(u,v);
        forbid[u].insert(v);
    }

    for(int i=1; i<=n; i++) node.insert(i);

    int id = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            cnt = 0;
            BFS(i,++id);
            a[id] = cnt;
        }
    }

    printf("%d\n",id);
    for(int i=1; i<=id; i++){
        printf("%d",a[i]);
        for(int j=0; j<a[i]; j++){
            printf(" %d",gr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

