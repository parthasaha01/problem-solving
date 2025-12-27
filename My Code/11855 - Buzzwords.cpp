#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  MOD = 999998777;
#define base 1000117LL
string s;
ll power[1005],hh[1005];
vector<int>ans;
unordered_map<ll,int>mp;
ll BIGMOD(ll b,ll p,ll MOD)
{
    ll res = 1%MOD, x = b%MOD;
    while(p)
    {
        if(p&1) res = (res*x)%MOD;
        x = (x*x)%MOD;
        p >>= 1LL;
    }
    return res;
}
void gethash()
{
    ll v = 0;
    for(int i=0; i<s.size(); i++){
        v += s[i]*power[i];
        v %= MOD;
        hh[i] = v;
    }
}
int main()
{
    power[0]=1;
    for(ll i=1; i<=1005; i++){
        power[i] = power[i-1]*base;
        power[i] %= MOD;
    }
    string ss;
    while(getline(cin,ss))
    {
        if(ss=="")break;
        s="";
        for(int i=0; i<ss.size(); i++){
            if(ss[i]>='A'&&ss[i]<='Z')s+=ss[i];
        }

        gethash();

        int n = s.size();

//        for(int i=0; i<n; i++){
//            printf("%lld ",hh[i]);
//        }
//        printf("\n");

        ans.clear();
        for(int i=1; i<n; i++){
            int maxx = 0;
            mp.clear();
            for(int j=0; (j+i)<=n; j++){
                ll v = hh[j+i-1];
                if(j>0){
                    v -= hh[j-1];
                    if(v<0){
                        v = (v+MOD)%MOD;
                    }

                    ll hor = BIGMOD(power[j],MOD-2,MOD);
                    v *= hor;
                    v %= MOD;
                }

                mp[v]++;
                maxx = max(maxx,mp[v]);
            }

            if(maxx<2)break;

            ans.push_back(maxx);
        }

        for(int i=0; i<ans.size(); i++){
            printf("%d\n",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
