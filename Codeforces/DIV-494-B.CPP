#include<bits/stdc++.h>
using namespace std;
int a,b,x;
int dp[105][105][205][3];
string s;
int fun(int ca,int cb,int cx,int pr)
{
    if(cx<0)return 0;
    if(ca==0&&cb==0){
        if(cx==0)return 1;
        return 0;
    }
    if(dp[ca][cb][cx][pr]!=-1)return dp[ca][cb][cx][pr];

    int ret = 0;
    if(ca>0){
        if(pr==1) ret |= fun(ca-1,cb,cx-1,0);
        else ret |= fun(ca-1,cb,cx,0);
    }
    if(cb>0){
        if(pr==0)ret |= fun(ca,cb-1,cx-1,1);
        else ret |= fun(ca,cb-1,cx,1);
    }

    return dp[ca][cb][cx][pr] = ret;
}
void path(int ca,int cb,int cx,int pr)
{
    if(cx<0)return;
    if(ca==0&&cb==0)return;

    int ret = 0;
    if(ca>0){
        int ret1=0,ret2=0;
        if(pr==1) ret1 = fun(ca-1,cb,cx-1,0);
        else ret2 = fun(ca-1,cb,cx,0);

        if(ret1==1){
            ret = 1;
            s+='0';
            path(ca-1,cb,cx-1,0);
        }
        else if(ret2==1){
            ret = 1;
            s+='0';
            path(ca-1,cb,cx,0);
        }
    }
    if(cb>0 && ret==0){
        int ret1=0,ret2=0;
        if(pr==0)ret1 = fun(ca,cb-1,cx-1,1);
        else ret2 = fun(ca,cb-1,cx,1);

        if(ret1==1){
            ret = 1;
            s+='1';
            path(ca,cb-1,cx-1,1);
        }
        else if(ret2==1){
            ret = 1;
            s+='1';
            path(ca,cb-1,cx,1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>a>>b>>x;
    memset(dp,-1,sizeof(dp));
    fun(a,b,x,2);
    path(a,b,x,2);
    cout << s << endl;

    return 0;
}
