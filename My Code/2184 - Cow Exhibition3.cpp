#include<cstdio>
#include<algorithm>
#include <cstring>
using namespace std;
const int inf = 1000000000;
const int offset = 100000;
int n,smart[101],funny[101],dp[101][100001];
int fun(int pos,int smartness)
{
    if(pos==n){
        if(smartness==0)return 0;
        return -10000000;
    }

    int& ret = dp[pos][smartness];
    if(ret!=-inf) return ret;

    ret = max(ret,fun(pos+1,smartness));
    if(smartness-smart[pos]>=0)
    ret = max(ret,funny[pos]+fun(pos+1,smartness-smart[pos]));
    return ret;
}
int main()
{
    scanf("%d",&n);
    int maxsmart = 0;
    for(int i=0; i<n; i++){
        scanf("%d%d",&smart[i],&funny[i]);
        maxsmart += max(0,smart[i]);
    }
    //cout << maxsmart<<endl;
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<100001; j++){
            dp[i][j] = -inf;
        }
    }

    for(int x=maxsmart; x>=0; x--){
        int cnt = fun(0,x);
        //cout << x << " " << cnt << " " << x+cnt << " " << ans << endl;
        if(cnt>=0)ans = max(ans,x+cnt);
    }

    printf("%d\n",ans);

    return 0;
}

