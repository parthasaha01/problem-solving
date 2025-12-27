#include<bits/stdc++.h>
using namespace std;
int a[15],m,n;
int dp[11][11];
int call(int pos, int digit)
{
    int ret=0;
    if(pos==n)
        return 1;

    if(dp[pos][digit]!=-1)
        return dp[pos][digit];

    for(int i=0; i<m; i++)
    {
        if(abs(digit-a[i])<=2){
            ret += call(pos+1,a[i]);
            dp[pos][digit]=ret;
        }
    }

    return ret;
}
int main()
{
    int T,test,cnt;
    cin >> T;

    for(test=1; test<=T; test++)
    {
        memset(dp,-1,sizeof(dp));
        cin >> m >> n;
        cnt=0;

        for(int i=0; i<m; i++)
            cin >> a[i];

        for(int i=0; i<m; i++){
            cnt += call(1,a[i]);
        }

        cout<<"Case "<<test<<": "<<cnt<<endl;
    }

    return 0;
}
