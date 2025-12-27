#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int dp[mx],ans;
vector<int>ed[mx];
void DFS(int u,int pr)
{
    dp[u] = 1;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==pr)continue;
        DFS(v,u);
        dp[u] += dp[v];
    }

    if(dp[u]%2==0){
        ans++;
        dp[u] = 0;
    }
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<n; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    if(n==1){
        printf("-1\n");
        return 0;
    }
//    if(n==2){
//        printf("0\n");
//        return 0;
//    }

    memset(dp,-1,sizeof(dp));

    DFS(1,0);

    if(dp[1]!=0){
        printf("-1\n");
    }
    else{
        printf("%d\n",ans-1);
    }
    return 0;
}
