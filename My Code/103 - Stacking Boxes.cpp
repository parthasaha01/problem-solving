#include<bits/stdc++.h>
using namespace std;
vector<int>ed[35];
int k,n,a[35][15],dp[35],dir[35];
int lis(int u)
{
    if(ed[u].size()==0)return dp[u]=1;

    if(dp[u]!=-1)return dp[u];

    int ret=0;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        int x = lis(v);
        if(x>ret){
            ret = x;
            dir[u]=v;
        }
    }
    return dp[u]=1+ret;
}
bool possible(int u,int v)
{
    bool flag = true;
    for(int i=1; i<=n; i++){
        if(a[u][i]>=a[v][i]){
            flag=false;
            break;
        }
    }
    return flag;
}
int main()
{
    while(scanf("%d%d",&k,&n)==2)
    {
        for(int i=1; i<=k; i++){
            for(int j=1; j<=n; j++)scanf("%d",&a[i][j]);
            sort(a[i]+1,a[i]+n+1);
        }

        for(int u=1; u<=k; u++){
            for(int v=1; v<=k; v++){
                if(possible(u,v)){
                    ed[u].push_back(v);
                }
            }
        }

        int maxx=0,start=0;
        memset(dp,-1,sizeof(dp));
        memset(dir,-1,sizeof(dir));

        for(int i=1; i<=k; i++){
            int cnt = lis(i);
            if(cnt>maxx){
                maxx=cnt;
                start=i;
            }
        }

        printf("%d\n",maxx);

        for(int i=1; i<=maxx; i++)
        {
            if(i<maxx)printf("%d ",start);
            else printf("%d\n",start);

            start = dir[start];
        }

        for(int i=1; i<=k; i++)ed[i].clear();
    }
    return 0;
}
