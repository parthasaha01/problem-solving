#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
int a[501][501],b[501][501],d[501];
int n,m,k;
char s[505];
int fun(int pos,int cnt)
{
    if(cnt<0)return 100000000;
    if(pos==n)return 0;

    if(dp[pos][cnt]!=-1)return dp[pos][cnt];

    int ret=100000000;

    for(int j=0; j<m; j++)
    {
        ret = min(ret,a[pos][j]+fun(pos+1,cnt-b[pos][j]));
    }

    ret =min(ret,fun(pos+1,cnt-d[pos]));

    return dp[pos][cnt] = ret;
}
void path(int pos,int cnt)
{
    if(cnt<0)return;
    if(pos==n)return;

    int ret = fun(pos,cnt);

    int ret1 = fun(pos+1,cnt-d[pos]);
    if(ret1==ret)path(pos+1,cnt-d[pos]);
    else{
        for(int j=0; j<m; j++)
        {
            int ret2 = a[pos][j]+fun(pos+1,cnt-b[pos][j]);
            if(ret2==ret){
                printf("%d %d %d %d\n",pos,j,a[pos][j],b[pos][j]);
                path(pos+1,cnt-b[pos][j]);
                break;
            }
        }
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d%d",&n,&m,&k);

    for(int i=0; i<n; i++)
    {
        scanf("%s",s);
        int x = m-1;
        for(int j=m-1; j>=0; j--)
        {
            if(s[j]=='1'){
                x = j;
                break;
            }
        }

        int c=0;

        for(int j=0; j<m; j++)
        {
            if(j>x)x=m-1;
            if(s[j]=='1')
            {
                a[i][j] = x-j+1;
                b[i][j] = c;
                c++;
            }
            else
            {
                a[i][j] = 100000000;
                b[i][j] = 1000;
            }
        }
        d[i]=c;
    }

    int ans = fun(0,k);

   // path(0,k);

    printf("%d\n",ans);

    return 0;
}
