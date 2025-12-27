#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
map<ll,ll>mp;
ll sum[100005];
void calc(){
    sum[0]=1;
    for(int i=1; i<=100002; i++) sum[i] = (sum[i-1]*31);
}
int fun1(ll pos, ll hh)
{
    int ret = 0;
    for(int v='a'; v<='z'; v++){
        ll gg = hh; gg += (v*sum[pos]);
        if(mp.find(gg)!=mp.end()){
            int f = fun1(pos+1,gg);
            ret |= f;
        }
    }
    return !ret;
}
int fun2(ll pos, ll hh)
{
    int ret = 0; int isleaf = 1;
    for(int v='a'; v<='z'; v++){
        ll gg = hh; gg += (v*sum[pos]);
        if(mp.find(gg)!=mp.end()){
            isleaf = 0;
            int f = fun2(pos+1,gg);
            ret |= f;
        }
    }
    if(isleaf==1)ret = 1;
    return !ret;
}
int main()
{
    calc();
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        string s; cin>>s;
        ll hh = 0;
        for(int j=0; j<s.size(); j++){
            hh += (s[j]*sum[j]);
            if(mp.find(hh)==mp.end()) mp[hh] = 1;
        }
    }

    int win=!fun1(0,0);
    int lose=!fun2(0,0);

    if(win==0) printf("Second\n");
    else if(win==1&&lose==1) printf("First\n");
    else{
        if(k&1) printf("First\n");
        else printf("Second\n");
    }
    return 0;
}
