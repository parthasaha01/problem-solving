#include<bits/stdc++.h>
using namespace std;
#define mx 100005
map<int,int>mp;
vector<int>vv[mx],ed[mx];
int vis[mx],a[mx],b[mx],cnt;
void dfs(int u)
{
    vis[u]=true;
    vv[cnt].push_back(u);

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==0)dfs(v);
    }
}
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }

    sort(b+1,b+n+1);

    for(int i=1; i<=n; i++){
        mp[b[i]]=i;
    }

    for(int i=1; i<=n; i++)
    {
        ed[mp[a[i]]].push_back(i);
    }

    cnt=0;

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            cnt++;
            dfs(i);
        }
    }

    printf("%d\n",cnt);
    for(int i=1; i<=cnt; i++)
    {
        printf("%d",vv[i].size());
        for(int j=0; j<vv[i].size(); j++){
            printf(" %d",vv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
