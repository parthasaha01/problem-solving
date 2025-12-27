#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n,cnt[30][1005],a[1005],maxx;
ll dp[1005];
int dpn[1005];
string ss,s;
bool valid(int x,int y)
{
    if(y>=ss.size())return false;

    for(int i=0; i<26; i++){
        if(cnt[i][y]-cnt[i][x-1]>0){
            if(y-x+1>a[i])return false;
        }
    }
    return true;
}
ll fun(int pos)
{
    if(pos==ss.size())return 1;
    if(dp[pos] != -1)return dp[pos];

    ll ret = 0;
    for(int i=0; i<a[ss[pos]-'a']; i++){
        if(valid(pos,pos+i)){
            maxx = max(maxx,i+1);
            ret = ((ret%mod)+(fun(pos+i+1)%mod))%mod;
        }
    }
    return dp[pos] = ret%mod;
}
int funmn(int pos)
{
    if(pos==ss.size())return 0;
    if(dpn[pos] != -1)return dpn[pos];

    int ret = 1000000;
    for(int i=0; i<a[ss[pos]-'a']; i++){
        if(valid(pos,pos+i)){
            ret = min(ret,1+funmn(pos+i+1));
        }
    }
    return dpn[pos] = ret;
}
int main()
{
    while(cin>>n)
    {
        cin>>s;
        ss = "0";
        ss += s;

        for(int i=0; i<26; i++){
            scanf("%d",&a[i]);
        }
        memset(cnt,0,sizeof(cnt));
        for(int i=1; i<ss.size(); i++){
            for(int j=0; j<26; j++){
                cnt[j][i]=cnt[j][i-1];
            }
            cnt[ss[i]-'a'][i]++;
        }
        memset(dp,-1,sizeof(dp));
        maxx=0;
        ll ans=fun(1);
        memset(dpn,-1,sizeof(dpn));
        int mnn = funmn(1);
        cout << ans << endl;
        printf("%d\n",maxx);
        printf("%d\n",mnn);
    }
    return 0;
}
