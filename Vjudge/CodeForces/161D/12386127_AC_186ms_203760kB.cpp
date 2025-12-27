#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[50002][502], wp[50002][502];
vector<int>ed[50002];
void DFS(int u,int pr)
{
    int sz = ed[u].size();
    if(u!=1)sz--;
    if(sz==0){
        dp[u][0] = 1;
        return;
    }
    dp[u][0]=1;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(v==pr)continue;

        DFS(v,u);

        for(int j=0; j<k; j++){
            wp[u][k] += dp[u][j]*dp[v][k-j-1];
        }

        for(int j=1; j<=k; j++){
            dp[u][j] += dp[v][j-1];
        }

//        for(int j=1; j<=k; j++){
//            for(int x=0; x<j; x++){
//                dp[u][j] += dp[u][x]*dp[v][j-x-1];
//            }
//        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<n; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    DFS(1,0);

    int ans=0;
    for(int i=1; i<=n; i++){
        ans += wp[i][k];
    }

    printf("%d\n",ans);

    return 0;
}

/*
10 3
1 2
2 3
2 5
3 4
3 6
3 7
3 8
3 9
5 10

16 3
1 2
2 3
2 5
3 4
3 6
3 7
3 8
3 9
5 10
5 11
5 12
2 13
13 14
13 16
14 15
*/
