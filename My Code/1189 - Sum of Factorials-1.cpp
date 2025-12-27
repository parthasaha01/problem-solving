#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
vector<pll>vv;
ll fac[20];
map<ll,int>mp;
const double inf = 1000000000000000000.0;
void preproces()
{
    fac[0]=1;
    for(int i=1; i<=19; i++){
        fac[i]=fac[i-1]*i;
    }

    for(int mask=1; mask<(1<<20); mask++)
    {
        ll val = 0;
        int f = 1;
        for(int i=0; i<20; i++){
            if(mask&(1<<i)){
                double cc = val;
                cc += (double)fac[i];
                if(cc>inf){
                    f = 0;
                    break;
                }
                val += fac[i];
            }
        }
        if(!f)continue;
        if(mp.find(val)==mp.end()){
            mp[val]=mask;
            vv.push_back(make_pair(val,mask));
        }
    }

    sort(vv.begin(),vv.end());
    cout << vv.size() << endl;
//    for(int i=0; i<vv.size(); i++){
//        cout<<i+1<<"-->"<<vv[i].first<<" = "<<vv[i].second<<endl;
//    }
}
int main()
{
    preproces();

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n; scanf("%lld",&n);

        int flag = 0;

        if(mp.find(n)!=mp.end()){
            printf("Case %d: ",ks);
            int mask = mp[n];
            for(int i=0; i<20; i++){
                if(mask&(1<<i)){
                    if(flag)printf("+%d!",i);
                    else printf("%d!",i);

                    flag = 1;
                }
            }
            printf("\n");
        }
        else{
            printf("Case %d: impossible\n",ks);
        }
    }

    return 0;
}

