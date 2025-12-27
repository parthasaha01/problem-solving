#include<bits/stdc++.h>
using namespace std;
int n,w,k,vv[105],last[105],dp[105][105];
struct dt{
    int x,y;
}st[105];
bool cmp(dt a,dt b){
    return a.y<b.y;
}
int fun(int pos,int k)
{
    if(k==0) return 0;
    if(pos==n){
        if(k>=0)return 0;
    }

    int &ret = dp[pos][k];
    if(ret != -1)return ret;

    ret = 0;
    ret = max(ret,fun(pos+1,k));
    ret = max(ret,vv[pos]+fun(last[pos]+1,k-1));
    return ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d%d",&n,&w,&k);
        for(int i=0; i<n; i++){
            int x,y; scanf("%d%d",&x,&y);
            st[i].x = x;
            st[i].y = y;
        }

        sort(st,st+n,cmp);

        for(int i=0; i<n; i++){
            int ww = st[i].y+w;
            int kk = i;
            for(int j=i+1; j<n; j++){
                if(st[j].y>ww)break;
                kk=j;
            }
            last[i]=kk;
            vv[i] = kk-i+1;
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,k);
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
