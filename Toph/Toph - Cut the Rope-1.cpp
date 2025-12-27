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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++){
        cout<<"Case "<<ks<<":"<<endl;
        ll n,q; cin>>n>>q;

        os.clear();
        ss.clear();

        int id = 0;
        os.insert({0,0});
        os.insert({n,++id});

        ss.insert({n,1});

        while(q--){
            char ch; ll x;
            cin>>ch>>x;
            if(ch=='C'){
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
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}

