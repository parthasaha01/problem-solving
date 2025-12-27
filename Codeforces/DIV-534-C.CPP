#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector< pii > ans;
string s;
void solve(){
    ans.clear();
    int zero = 0,one = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1'){
            if(one==0){
                ans.push_back(make_pair(4,3));
                one=1;
            }else{
                ans.push_back(make_pair(4,1));
                one=0;
            }
        }else{
            if(zero==0){
                ans.push_back(make_pair(1,1));
                zero=1;
            }else{
                ans.push_back(make_pair(3,1));
                zero=0;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    solve();
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    //main();
    return 0;
}
