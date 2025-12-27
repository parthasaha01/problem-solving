#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>v;
vector<int>uu[10];
map<string,int>mp;
int k,x;
ll dp[(1<<19)][19][2];
ll fac[20];
ll check(int mask)
{

    for(int i=0; i<10; i++){
        if(uu[i].size()==0)continue;
        int f = 0;
        for(int j=0; j<uu[i].size(); j++){
            int p = uu[i][j];
            if(mask&(1<<p)){
                f++;
            }
        }
        if(f==0)return 0LL;

    }
    return 1LL;
}
ll fun(int mask, int pos, int f)
{
    if(pos<0){

       // mp[ss]++;
        return check(mask);
//        if(check(mask)){
//            cout << ss << endl;
//            return 1LL;
//        }
//        return 0LL;
    }

    if(dp[mask][pos][f]!=-1)return dp[mask][pos][f];

    ll ret = 0;
    for(int i=0; i<k; i++){
        if(v[i]==0 && f==0)continue;
        if((mask&(1<<i))==0){
//            string xx;
//            xx = ss;
//            xx += v[i]+'0';
            ret += fun(mask|(1<<i),pos-1,f|(v[i]>0));
        }
    }

    return dp[mask][pos][f] = ret;
}
int main()
{
    fac[0] = 1;
    for(ll i=1; i<=20; i++) fac[i] = fac[i-1]*i;

    ll n;
    cin>>n;
    ll m = n;

    while(m!=0)
    {
        int r = m%10LL;
        v.push_back(r);
        m/=10LL;
    }

    sort(v.begin(),v.end());
    k = v.size();

    for(int i=0; i<k; i++){
        uu[v[i]].push_back(i);
        //cout << v[i] << " ";
    }
    //cout << endl;

    int d = 0;
    for(int i=0; i<10; i++){
        if(uu[i].size()>0)d++;
    }

    ll ans = 0;
    memset(dp,-1,sizeof(dp));
    for(int i=k; i>=d; i--){
        x = i;
        ans += fun(0,i-1,0);
    }



//    cout << "size = " << mp.size() << endl;
//    int x = 0;
//    for(auto it = mp.begin(); it!=mp.end(); it++){
//        cout <<  ++x << " " << it->first << " " << it->second << endl;
//    }

    cout << ans << endl;

    return 0;
}

