#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define ll long long
ll dp[mx],a[mx],wp[mx],ans;
vector<int>ed[mx];
bool cmp(ll x,ll y){
    return x>y;
}
void DFS(int u,int pr)
{
    dp[u]=a[u];
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;
        DFS(v,u);
        dp[u]+=dp[v];
    }

    vector<ll>vv;
    wp[u] = dp[u];
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;
        wp[u] =max(wp[u],wp[v]);
        vv.push_back(wp[v]);
    }

    sort(vv.begin(),vv.end(),cmp);

    if(vv.size()>1)ans = max(ans,vv[0]+vv[1]);
    vv.clear();
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%I64d",&a[i]);
    }

    for(int i=1; i<n; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    ans = -10000000000000000;

    DFS(1,0);

    if(ans==-10000000000000000){
        printf("Impossible\n");
    }
    else{
        printf("%I64d\n",ans);
    }

    return 0;
}

