#include<bits/stdc++.h>
using namespace std;
int a[10];
int dp[10][120005];
int ans;
int fun(int p,int v)
{
    if(ans==1)return true;

    if(v==0){
        ans = 1;
        return 1;
    }

    if(p>6){
        if(v==0)return 1;
        else return 0;
    }

    if(dp[p][v]!=-1)return dp[p][v];

    int ret1=0, ret2=0;

    for(int m=1; m<=a[p]; m++){
        if(v-(p*m)>=0) ret1 |= fun(p+1,v-(p*m));
    }

    ret2 = fun(p+1,v);

    return dp[p][v] = ret1 | ret2;
}
int main()
{
    int ks=0;
    while(1)
    {
        int s=0;
        for(int i=1; i<=6; i++){
            scanf("%d",&a[i]);
            s += (a[i]*i);
        }

        if(s==0)break;

        printf("Collection #%d:\n",++ks);

        if(s&1){
            printf("Can't be divided.\n\n");
            continue;
        }

        int v = s/2;
        ans = 0;

        memset(dp,-1,sizeof(dp));
        int flag = fun(1,v);

        if(ans)printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
