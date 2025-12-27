#include<bits/stdc++.h>
using namespace std;
int n,m,dp[100005][2][2];
vector<int>v;
int fun(int p,int f,int k)
{
    if(p>=n)return 0;
    if(dp[p][f][k]!=-1)return dp[p][f][k];

    int ret = 0;
    int w = v[p+1]-v[p];
    //printf("v[%d]=%d v[%d]=%d w=%d\n",p,v[p],p+1,v[p+1],w);
    //getchar();
    if((f==0) && (w>1))
    {
        if(k==0){
            ret = max(ret, (w-1)+fun(p+1,1,0));
            ret = max(ret, w+fun(p+1,0,1));
        }
        else{
            ret = max(ret, (w-1)+fun(p+1,1,1));
            ret = max(ret, fun(p+1,0,0));
        }
    }
    else
    {
        if(k==0){
            ret = max(ret, w + fun(p+1,f,1));
        }
        else{
            ret = max(ret, fun(p+1,f,0));
        }
    }

    return dp[p][f][k] = ret;
}
int main()
{
    scanf("%d%d",&n,&m);
    v.push_back(0);
    for(int i=1; i<=n; i++){
        int x; scanf("%d",&x);
        v.push_back(x);
    }
    v.push_back(m);
    n++;

    memset(dp,-1,sizeof(dp));
    int ans = fun(0,0,0);

    printf("%d\n",ans);

    return 0;
}
