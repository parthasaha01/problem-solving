#include<bits/stdc++.h>
using namespace std;
int t1,t2,s,k,a[35][25],b[35][25],sz[35],dp[35][305];
vector<int>vv;
int fun(int p,int x)
{
    if(p==s+1){
        if(x==t1)return 0;
        return 1000000000;
    }

    if(dp[p][x]!=-1)return dp[p][x];

    int ret=1000000000;

    for(int i=0; i<=sz[p]; i++){
        int ret1 = a[p][i] + b[p][sz[p]-i] + fun(p+1,x+i);
        ret = min(ret,ret1);
    }

    return dp[p][x] = ret;
}
void path(int p,int x)
{
    if(p==s+1)return;

    int ret = fun(p,x);

    for(int i=0; i<=sz[p]; i++){
        int ret1 = a[p][i] + b[p][sz[p]-i] + fun(p+1,x+i);
        if(ret==ret1){
            vv.push_back(i);
            path(p+1,x+i);
            break;
        }
    }
}
int main()
{
    while(scanf("%d%d",&t1,&t2))
    {
        if(!t1&&!t2)break;

        scanf("%d",&s);
        for(int i=1; i<=s; i++)
        {
            scanf("%d",&sz[i]);
            a[i][0]=b[i][0]=0;
            for(int j=1; j<=sz[i]; j++){
                scanf("%d",&a[i][j]);
            }
            for(int j=1; j<=sz[i]; j++){
                scanf("%d",&b[i][j]);
            }
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(1,0);

        vv.clear();
        path(1,0);

        printf("%d\n",ans);
        for(int i=0; i<vv.size(); i++){
            if(i<vv.size()-1)printf("%d ",vv[i]);
            else printf("%d\n",vv[i]);
        }
        printf("\n");
    }
    return 0;
}
/*
10 12
5
5
10 30 70 150 310
10 20 40 60 180
7
30 60 90 120 160 200 240
20 60 100 130 160 200 240
4
40 60 80 100
30 70 100 120
3
60 120 180
20 50 90
3
30 70 100
30 70 100
*/
