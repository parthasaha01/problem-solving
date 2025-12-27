#include<bits/stdc++.h>
using namespace std;
#define LLI long long int
#define mx 205
int N,row;
LLI banana[mx][mx];
LLI dp[mx][mx];
LLI f(int i, int j, LLI sum)
{
    if(i==row){
        return banana[i][1];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    LLI profit1=0,profit2=0;

    if(i<N)
    {
        profit1=banana[i][j]+f(i+1,j,sum+banana[i][j]);
        profit2=banana[i][j]+f(i+1,j+1,sum+banana[i][j]);
    }
    else
    {
        if(j==1){
            profit1=banana[i][j]+f(i+1,j,sum+banana[i][j]);
            profit2=0;
        }
        else if(j==row-i+1){
            profit1=banana[i][j]+f(i+1,j-1,sum+banana[i][j]);
            profit2=0;
        }
        else{
            profit1=banana[i][j]+f(i+1,j-1,sum+banana[i][j]);
            profit2=banana[i][j]+f(i+1,j,sum+banana[i][j]);
        }
    }

    return dp[i][j]=max(profit1,profit2);
}
int main()
{
    int T;
    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        memset(banana,0,sizeof(banana));
        memset(dp,-1,sizeof(dp));

        scanf("%d",&N);
        row=2*N-1;

        for(int i=1; i<=row; i++){
            int col=N-abs(N-i);
            for(int j=1; j<=col; j++){
                scanf("%lld",&banana[i][j]);
            }
        }

        LLI result=f(1,1,0);
        printf("Case %d: %d\n",test,result);
    }

    return 0;
}
