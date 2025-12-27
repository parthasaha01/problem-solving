#include<bits/stdc++.h>
using namespace std;
int n,a[105],dp[105][105],flag;
void fun(int pos,int cnt)
{
    if(flag==1)return;
    if(pos>n)
    {
        if(cnt%2==1){
            flag=1;
            return ;
        }
        return;
    }

    if(dp[pos][cnt]!=-1)return;

    dp[pos][cnt]=1;

    if(a[pos]%2==0)return;

    for(int i=0; i<=100; i+=2)
    {
        int des = pos+i;
        if(des>n)break;
        if(des<=n && a[des]%2==1)
        {
            fun(des+1,cnt+1);
        }
    }
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    if(n==1)
    {
        if(a[1]%2==0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }

        return 0;
    }

    if((a[1]%2==0) || (a[n]%2==0))
    {
        printf("NO\n");
        return 0;
    }

    memset(dp,-1,sizeof(dp));
    flag=0;

    fun(1,0);

    if(flag==1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
