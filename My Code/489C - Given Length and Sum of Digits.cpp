#include<bits/stdc++.h>
using namespace std;
int n,s,dp[105][905];
string maxx,minn;
int fun(int pos,int sum)
{
    if(sum<0)return 0;
    if(pos==0){
        if(sum==0)return 1;
        return 0;
    }

    if(dp[pos][sum]!=-1)return dp[pos][sum];

    int ret = 0;
    for(int i=0; i<10; i++){
        if(i==0&&pos==n)continue;
        ret |= fun(pos-1,sum-i);
    }
    return dp[pos][sum] = ret;
}
void pathmin(int pos,int sum)
{
    if(pos==0)return;
    int ret = 0;
    for(int i=0; i<10; i++){
        if(i==0&&pos==n)continue;
        ret |= fun(pos-1,sum-i);
        if(ret==1){
            minn += i+'0';
            pathmin(pos-1,sum-i);
            break;
        }
    }
}
void pathmax(int pos,int sum)
{
    if(pos==0)return;
    int ret = 0;
    for(int i=9; i>=0; i--){
        if(i==0&&pos==n)continue;
        ret |= fun(pos-1,sum-i);
        if(ret==1){
            maxx += i+'0';
            pathmax(pos-1,sum-i);
            break;
        }
    }
}
int main()
{
    cin>>n>>s;

    if(n==1 && s==0){
        cout << 0 << " " << 0 << endl;
    //    main();
        return 0;
    }

    memset(dp,-1,sizeof(dp));
    int ase = fun(n,s);

    if(ase==0){
        cout << -1 << " " << -1 << endl;
    }
    else{
        pathmin(n,s);
        pathmax(n,s);
        cout << minn << " " << maxx << endl;
    }

    //maxx="";
    //minn="";
    //main();

    return 0;
}
