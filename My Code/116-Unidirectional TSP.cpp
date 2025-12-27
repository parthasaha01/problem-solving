#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int r,c,a[12][102],dp[12][102],dr[12][102];
int fun(int i, int j)
{
    if(i<1 || i>r)return 2000000000;
    if(j==c+1)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int ret,ret1,ret2,ret3;

    if(i==1){
        ret1 = a[i][j] + fun(i,j+1);
        ret2 = a[i][j] + fun(i+1,j+1);
        ret3 = a[i][j] + fun(r,j+1);
    }
    else if(i==r){
        ret1 = a[i][j] + fun(1,j+1);
        ret2 = a[i][j] + fun(i-1,j+1);
        ret3 = a[i][j] + fun(i,j+1);
    }
    else{
        ret1 = a[i][j] + fun(i-1,j+1);
        ret2 = a[i][j] + fun(i,j+1);
        ret3 = a[i][j] + fun(i+1,j+1);
    }

    ret = min(ret1,min(ret2,ret3));

    return dp[i][j] = ret;
}
void path(int i, int j)
{
    if(j==c+1)return;

    v.push_back(i);

    int ret,ret1,ret2,ret3;

    ret = fun(i,j);

    if(i==1){
        ret1 = a[i][j] + fun(i,j+1);
        ret2 = a[i][j] + fun(i+1,j+1);
        ret3 = a[i][j] + fun(r,j+1);

        if(ret1==ret)path(i,j+1);
        else if(ret2==ret)path(i+1,j+1);
        else path(r,j+1);
    }
    else if(i==r){
        ret1 = a[i][j] + fun(1,j+1);
        ret2 = a[i][j] + fun(i-1,j+1);
        ret3 = a[i][j] + fun(i,j+1);

        if(ret1==ret)path(1,j+1);
        else if(ret2==ret)path(i-1,j+1);
        else path(i,j+1);
    }
    else{
        ret1 = a[i][j] + fun(i-1,j+1);
        ret2 = a[i][j] + fun(i,j+1);
        ret3 = a[i][j] + fun(i+1,j+1);

        if(ret1==ret)path(i-1,j+1);
        else if(ret2==ret)path(i,j+1);
        else path(i+1,j+1);
    }
}
int main()
{
    while(scanf("%d%d",&r,&c)==2)
    {
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                scanf("%d",&a[i][j]);
            }
        }

        memset(dp,-1,sizeof(dp));
        int start=0,minn=2000000000;
        for(int i=1; i<=r; i++)
        {
            int cnt = fun(i,1);
            if(cnt<minn){
                minn  = cnt;
                start = i;
            }
        }

        v.clear();
        path(start,1);

        printf("%d",start);
        for(int i=1; i<v.size(); i++){
            printf(" %d",v[i]);
        }
        printf("\n%d\n",minn);
    }
    return 0;
}
