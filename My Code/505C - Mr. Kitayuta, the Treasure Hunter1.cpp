#include<bits/stdc++.h>
using namespace std;
int n,d,offshift,cnt[30005];
int dp[30005][2005];
int go(int cur,int jump)
{
    if(cur>30000)return 0;
    if(dp[cur][jump]!=-1)return dp[cur][jump];
    int ret = 0;
    if(cur+jump-1>cur)ret = max(ret, cnt[cur] + go(cur+jump-1,jump-1));
    ret = max(ret, cnt[cur] + go(cur+jump,jump));
    ret = max(ret, cnt[cur] + go(cur+jump+1,jump+1));
    return dp[cur][jump] = ret;
}
int gogo(int cur,int jump)
{
    if(cur>30000)return 0;
    int ret = 0;
    if(cur+jump-1>cur)ret = max(ret, cnt[cur] + gogo(cur+jump-1,jump-1));
    ret = max(ret, cnt[cur] + gogo(cur+jump,jump));
    ret = max(ret, cnt[cur] + gogo(cur+jump+1,jump+1));
    return ret;
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; i++){
        int x; scanf("%d",&x);
        cnt[x]++;
    }

    if(d<=2000){
        memset(dp,-1,sizeof(dp));
        int ans = go(d,d);
        printf("%d\n",ans);
    }
    else{
        int ans = gogo(d,d);
        printf("%d\n",ans);
    }

    return 0;
}
/*
To make the dp feasible in this problem is to use brute force
when the first jump is very large. Define very large to be 2000.
Then the brute force would have maximum depth of 16, and about 3^16(43046721) operations.
When less than 2000, dp[30001][2000] would fit into time and memory.
*/

/*
Yes!! I did this in the same way you have explained! But In this way, Among addition
of 3 length, l-1,l,l+1 one shouldn't call the function of length l-1 first.
I have got many accepted code failed on a test case I have made!
The program stop executing because of stack capacity since function calling with
the length l-1 don't bring any solution.
My function have called above 16000 times without return any value in any call
and have stopped for stack capacity! It was indeed a tricky problem!!!)
*/
