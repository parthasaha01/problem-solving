#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000LL
#define mx 100005
ll n,a[mx+5],k;
map<ll,ll>mp;
map<ll,ll>cn;
vector<ll>vv;
int main()
{
    while(cin>>n>>k)
    {
        mp.clear();
        vv.clear();
        cn.clear();

        ll vl = 1;
        mp[vl]=1;
        vv.push_back(vl);

        if(k==-1 || k==1)
        {

        }

        while(vl<=inf && vl>0LL){
            vl*=k;
            vv.push_back(vl);
            mp[vl]=1;
        }

        for(int i=1; i<=n; i++){
            scanf("%I64d",&a[i]);
        }

        ll ans = 0;

        for(int i=1; i<=n; i++)
        {
            ll pp = a[i];

            if(a[i]==0)
            {
                if(mp[pp]==1)ans++;

                for(int x=0; x<vv.size(); x++)
                {
                    ll need = vv[x]-pp;
                    ll ct = cn[need];

                }
            }
            else if(a[i]<0)
            {
                if(mp[pp]==1)ans++;

                for(int x=0; x<vv.size(); x++)
                {
                    ll need = vv[x]-pp;
                    ll ct = cn[need];

                }
            }
            else
            {
                if(mp[pp]==1)ans++;

                for(int x=0; x<vv.size(); x++)
                {
                    ll need = vv[x]-pp;
                    ll ct = cn[need];

                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
