#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int r,c,a[12][102],dp[12][102];
struct dt{
    int x,y;
}st[12][102];
int fun(int i, int j)
{
    if(i<1 || i>r)return 2000000000;
    if(j==c+1)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int ret,ret1,ret2,ret3;
    int d1,d2,d3;

    if(i==1){
        ret1 = a[i][j] + fun(i,j+1);
        ret2 = a[i][j] + fun(i+1,j+1);
        ret3 = a[i][j] + fun(r,j+1);

        d1=i, d2=i+1,d3=r;
    }
    else if(i==r){
        ret1 = a[i][j] + fun(1,j+1);
        ret2 = a[i][j] + fun(i-1,j+1);
        ret3 = a[i][j] + fun(i,j+1);

        d1=1, d2=i-1,d3=i;
    }
    else{
        ret1 = a[i][j] + fun(i-1,j+1);
        ret2 = a[i][j] + fun(i,j+1);
        ret3 = a[i][j] + fun(i+1,j+1);

        d1=i-1, d2=i,d3=i+1;
    }

    ret = min(ret1,min(ret2,ret3));

    if(ret1==ret) st[i][j].x=d1;
    else if(ret2==ret) st[i][j].x=d2;
    else st[i][j].x=d3;

    st[i][j].y=j+1;

    return dp[i][j] = ret;
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

        printf("%d",start);
        for(int i=1; i<c; i++){
            printf(" %d",st[start][i].x);
            start = st[start][i].x;
        }
        printf("\n%d\n",minn);
    }
    return 0;
}

