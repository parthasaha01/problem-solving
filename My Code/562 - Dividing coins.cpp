#include<bits/stdc++.h>
using namespace std;
int dp[101][50001];
int a[101],m,total;
int solve(int pos, int sum)
{
    if(dp[pos][sum]!=-1){
        return dp[pos][sum];
    }

    if(pos==m){
        return dp[pos][sum] = abs(2*sum-total); //sum - (total-sum)
    }

    int left = solve(pos+1,sum);
    int right = solve(pos+1,sum+a[pos]);

    return dp[pos][sum]=min(left,right);
}
int main()
{
    int T;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&m);
        total=0;
        for(int i=0; i<m; i++){
            scanf("%d",&a[i]);
            total+=a[i];
        }
        memset(dp,-1,sizeof(dp));
        int minn=solve(0,0);
        printf("%d\n",minn);
    }

    return 0;
}
/*

1
5
68
50
32
30
20
