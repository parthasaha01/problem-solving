#include<bits/stdc++.h>
using namespace std;
int a[5001], dp[5001][5001];
int fun(int pos,int cnt){
    if(pos==0)return 0;
    int &ret = dp[pos][cnt];
    if(ret!=-1)return ret;
    ret = -1000000000;
    if(a[pos]>=0) {
        ret = max(ret, a[pos]+fun(pos-1,cnt));
    }else{
        if(cnt>0) ret = max(ret, fun(pos-1,cnt-1));
        ret = max(ret, a[pos]+fun(pos-1,cnt));
    }
    return ret = max(ret, a[pos]);
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int n,k; scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        int ans = -1000000000;
        for(int i=1; i<=n; i++){
            ans = max(ans, fun(i,k));
        }
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
