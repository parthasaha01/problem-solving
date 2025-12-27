#include<bits/stdc++.h>
using namespace std;
#define ll long long int
char start[100],ending[100];
ll st,ed,n,p;
#define SYN ios_base::sync_with_stdio(0):cin.tie(0);
ll dp[55][2][2][2],len;
ll visit[55][2][2][2];
ll solve(int pos, int x, int y,int f)
{
    if(pos>=n) return 1;

    ll &res=dp[pos][x][y][f];
    if(res!=-1&&x==1&&y==1) return res;
    else res=0;

    int  low=0, high=9;
    if(x==0) low=start[pos]-'0';
    if(y==0) high=ending[pos]-'0';

    int d=1;
    for(int i=low; i<=high; i++)
    {
        if(f||i>0) d=i;

        res=max(res,d*solve(pos+1, x|(i>start[pos-'0']),y|(i<ending[pos]-'0'),f|i>0));
    }
    return res;

}
ll path(int pos, int x, int y,int f)
{
    if(pos>=n) return 1;

    ll res=solve(pos,x,y,f);

    int  low=0, high=9;
    if(x==0) low=start[pos]-'0';
    if(y==0) high=ending[pos]-'0';

    int d=1;
    for(int i=low; i<=high; i++)
    {
        if(f||i>0) d=i;
        if(res==d*solve(pos+1,x|(i>start[pos-'0']),y|(i<ending[pos]-'0'),f|i>0))
        {
            if(f||i>0)
                cout<<i;
            return path(pos+1,x|(i>start[pos-'0']),y|(i<ending[pos]-'0'),f|i>0);
        }
    }
    return 0;
}
int main()
{
    memset(dp,-1,sizeof(dp));

    scanf("%s %s",&start,&ending);
    int l1,l2;
    l1=strlen(start);
    l2=strlen(ending);
    n=20;

    int dif(n-l1);
    for(int j=l1-1; j>=0; j--){
        start[j+dif]=start[j];
    }
    for(int i=0; i<dif; i++){
        start[i]='0';
    }

    dif=n-l2;
    for(int j=l2-1; j>=0; j--){
        ending[j+dif]=ending[j];
    }
    for(int i=0; i<dif; i++){
        ending[i]='0';
    }

    solve(0,0,0,0);
    path(0,0,0,0);

    return 0;
}
