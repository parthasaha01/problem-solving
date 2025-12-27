#include<bits/stdc++.h>
using namespace std;
int  n,m,cc[16],bb[16],id,msk,flag;
vector<int>vv[16][(1<<15)+5];
int dp[16][(1<<15)+5];
bool vis[16][(1<<15)+5];
int check(int mask,int pos){ return mask & (1<<pos); }
int seton(int mask,int pos){ return mask | (1<<pos); }
int setoff(int mask,int pos) { return mask & (~(1 << pos)); }

void calc(int pos,int mask,int val)
{
    if(val==0){
        vv[id][msk].push_back(mask);
        return;
    }
    if(pos==n)return;


    if(check(mask,pos)==0 && cc[pos]<=val){
        calc(pos+1,seton(mask,pos),val-cc[pos]);
    }

    calc(pos+1,mask,val);
}
int bitcount(int mask)
{
    int cnt=0;
    for(int i=0; i<n; i++){
        if(check(mask,i)!=0)cnt++;
    }

    return cnt;
}
int fun(int pos,int mask)
{

    if(pos==m){
        flag=1;
        int cnt = bitcount(mask);
        return cnt;
    }

    int ret = 10000000;
    for(int i=0; i<vv[pos][mask].size(); i++){
        ret = min(ret,fun(pos+1,vv[pos][mask][i]));
    }

    return dp[pos][mask] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%d",&cc[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)scanf("%d",&bb[i]);


        memset(vis,false,sizeof(vis));
        for(int i=0; i<m; i++){
            for(int mask=0; mask<(1<<n); mask++){
                id=i; msk=mask;
                if(vis[id][msk]==false)calc(0,mask,bb[i]);
                vis[id][msk]=true;
            }
        }

        flag=0;
        memset(dp,-1,sizeof(dp));

        int ans = fun(0,0);

        if(flag) printf("Case %d: %d\n",ks,ans);
        else printf("Case %d: -1\n",ks);

        for(int i=0; i<m; i++){
            for(int mask=0; mask<(1<<n); mask++){
                vv[i][mask].clear();
            }
        }
    }
    return 0;
}

