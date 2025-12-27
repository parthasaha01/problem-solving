#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
vector<ll>vv;
set<ll>ss;
ll dd[mx];
ll lowerBound(int val)
{
    int id = 0;
    int lo=0;
    int hi = vv.size()-1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(vv[md]<val){
            id = md;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }

    return id;
}
int main()
{
    ll k,n,L,a,b,g1;

    while(scanf("%lld%lld%lld%lld%lld%lld",&k,&n,&L,&a,&b,&g1)==6)
    {
        ss.clear();
        ss.insert(0);
        ss.insert(g1);
        ll p = g1;

        for(int i=2; i<=n; i++){
            ll gg = (a*p+b)%(L+1);
            ss.insert(gg);
            p = gg;
        }

        vv.clear();
        set<ll> :: iterator it;

        for(it=ss.begin(); it != ss.end(); it++){
            vv.push_back(*it);
        }

        ll maxx = 0;
        dd[0] = 0;
        for(int i=1; i<vv.size(); i++){
            ll d  = vv[i]-vv[i-1]-1;
            maxx  = max(maxx,d);
            dd[i] = maxx;
        }

        ll sz = vv.size();
        ll high = vv[sz-1];

        for(int q=1; q<=k; q++)
        {
            ll wj; scanf("%lld",&wj);

            if(wj==1){ printf("0\n"); continue; }

            if(wj>high){
                ll ans = max(dd[sz-1],wj-high-1);
                printf("%lld\n",ans);
            }
            else{
                int id = lowerBound(wj);
                ll ans = dd[id];
                if(vv[id+1]==wj){
                    ans = max(ans,wj-vv[id]-2);
                }
                else{
                    ans = max(ans,wj-vv[id]-1);
                }
                printf("%lld\n",ans);
            }
        }
    }

    return 0;
}
