#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define ll long long
vector<int>ed[mx+5];
int n,a[mx+5],vis[mx+5],ans[mx+5];
int gcd(int a,int b)
{
    if(b==0)return a;
    //if(a==0)return b;
    return gcd(b,a%b);
}
void dfs(int u,int gd,int pp)
{
    vis[u]=1;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];

        if(vis[v]==1)continue;

        ans[v] = max(ans[v])
    }
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=1; i<n; i++)
    {
        int u,v;

        scanf("%d %d",&u,&v);

        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    ans[1]=a[1];
    dfs(1,a[1]);

    for(int i=1; i<=n; i++)
    {
        if(i<n)printf("%d ",ans[i]);
        else printf("%d\n",,ans[i]);
    }

    return 0;
}

