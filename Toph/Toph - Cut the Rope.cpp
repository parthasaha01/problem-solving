#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define ll long long
#define pll pair<ll,ll>

typedef tree<
pll,
null_type,
less<pll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ordered_set os;
set<pll>ss;

int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        printf("Case %d:\n",ks);
        ll n,q; scanf("%lld %lld",&n,&q);

        os.clear();
        ss.clear();

        int id = 0;
        os.insert({0,0});
        os.insert({n,++id});

        ss.insert({n,1});

        while(q--){
            char ch[2]; ll x;
            scanf("%s %lld",&ch,&x);
            if(ch[0]=='C'){
                auto it = ss.upper_bound({x,-1});
                pll cur = (*it);
                ll st = cur.second, ed = cur.first;
                ll len = ed-st+1;

                int cnt = os.order_of_key({len,-1});
                auto jt = os.find_by_order(cnt);

                os.erase(*jt);
                os.insert({x-st+1, ++id});
                os.insert({ed-x, ++id});

                ss.erase(it);
                ss.insert({x,st});
                ss.insert({ed,x+1});

            }else{
                ll ans = (*os.find_by_order(x)).first;
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
