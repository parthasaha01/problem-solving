#include<bits/stdc++.h>
using namespace std;
#define sz 100005
#define ll long long int
ll arr[sz+5];
bool flag[sz+5];
vector<ll>s[sz+5],c[sz+5];
map<pair<ll,ll>, ll >mp;
ll n,m;

ll fun(ll pos,ll rem)
{
    if(pos==n+1) return 0;
    //getchar();
    //cout<<pos<<" "<<rem<<endl;
    pair<ll,ll>p;
    p.first = pos;
    p.second = rem;
    if(mp.find(p)!=mp.end())
        return mp[p];

    ll ret1 = 11111111111111LL,ret2 = 11111111111111LL,ret3 = 11111111111111LL;
    if(arr[pos]>rem)
    {
        bool chk = 0;
        for(int i=0; i<s[pos].size(); i++)
        {
            if(s[pos][i]>=arr[pos])
            {
                chk = 1;
                ret1 = min(ret1,c[pos][i]+fun(pos+1,s[pos][i]-arr[pos]));
            }
        }
        if(chk==0)
            return 11111111111111LL;
    }
    else
    {
        if(flag[pos]==1)
        {

            // bool chk = 0;
            for(int i=0; i<s[pos].size(); i++)
            {
                if(s[pos][i]>=arr[pos])
                {
                    //flag = 1;
                    ret1 = min(ret1,c[pos][i]+fun(pos+1,s[pos][i]-arr[pos]));
                }
            }
            ret2 = fun(pos+1,rem - arr[pos]);
        }
        else
            ret3 = fun(pos+1,rem - arr[pos]);
    }

    mp[p] = min(min(ret1,ret2),ret3);
    return mp[p];

}
int main()
{
    while(scanf("%lld%lld",&n,&m)==2)
    {
        for(int i=0; i<sz; i++)
        {
            s[i].clear();
            c[i].clear();
        }
        memset(flag,0,sizeof(flag));
        mp.clear();
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
        }
        ll a,b,cc;
        for(int i=1; i<=m; i++)
        {
            scanf("%lld%lld%lld",&a,&b,&cc);
            flag[a] = 1;
            s[a].push_back(b);
            c[a].push_back(cc);
        }
        if(flag[1]==0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        ll ans = 11111111111111LL;
        for(int i=0; i<s[1].size(); i++)
        {
            ll res = 11111111111111LL;
            if(s[1][i]>=arr[1])
                res=c[1][i] + fun(2,s[1][i]-arr[1]);
            ans = min(ans,res);
        }

        if(ans>=11111111111111LL)
            printf("-1\n");
        else
            printf("%lld\n",ans);

    }
    return 0;
}
