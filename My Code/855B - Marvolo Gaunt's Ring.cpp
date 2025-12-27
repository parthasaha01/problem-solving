#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 3e18;
ll n,p,q,r,a[100005],dp[100005][3],vs[100005][3];
ll fun(int pos,int k)
{
    if(k==3)return 0LL;
    if(pos==n)return -INF;

    if(vs[pos][k]!=0)return dp[pos][k];
    vs[pos][k] = 1;
    ll ret = -INF;
    ll w;
    if(k==0)w=p*a[pos];
    if(k==1)w=q*a[pos];
    if(k==2)w=r*a[pos];
    ret = max(ret,w+fun(pos,k+1));
    ret = max(ret,w+fun(pos+1,k+1));
    ret = max(ret,fun(pos+1,k));
    return dp[pos][k]=ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>p>>q>>r;
    for(int i=0; i<n; i++)cin>>a[i];
    memset(vs,0,sizeof(vs));
    cout<<fun(0,0)<<endl;
    return 0;
}
