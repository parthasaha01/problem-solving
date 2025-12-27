#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int MOD = 1000000000;
set<int>s;
int main(){
    int q; cin>>q;
    char prev = '+';
    int ans = 0;
    while(q--){
        char type; int x;
        cin>>type>>x;
        if(type=='+'){
            if(prev=='+')s.insert(x);
            else s.insert((x+ans)%MOD);
            prev = '+';
            ans = 0;
        }else{
            set<int> :: iterator it;
            it = s.lower_bound(x);
            if(it==s.end()){
                cout << -1 << endl;
                ans = -1;
            }else {
                cout << *it << endl;
                ans = *it;
            }
            prev = '?';
        }
    }
    return 0;
}
