#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
vector< pair<int, int> >odd, even, ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int t=1; t<=tt; t++){
        int n; cin>>n;
        odd.clear(); even.clear(); ans.clear();
        for(int i=1; i<=2*n; i++){
            int x; cin>>x;
            if(x%2==1){
                odd.push_back(make_pair(i, x));
            }else{
                even.push_back(make_pair(i, x));
            }
        }

        int odd_size = odd.size();
        int even_size = even.size();

        if(odd_size%2==1){
            odd.pop_back();
            even.pop_back();
        }else{
            if(odd_size==0){
                even.pop_back();
                even.pop_back();
            }else{
                odd.pop_back();
                odd.pop_back();
            }
        }

        odd_size = odd.size();
        even_size = even.size();

        if(odd_size>0){
            for(int i=1; i<odd_size; i+=2){
                pii x = odd[i-1];
                pii y = odd[i];
                ans.push_back(make_pair(x.first, y.first));
            }
        }
        if(even_size>0){
            for(int i=1; i<even_size; i+=2){
                pii x = even[i-1];
                pii y = even[i];
                ans.push_back(make_pair(x.first, y.first));
            }
        }

        for(int i=0; i<(int)ans.size(); i++) {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }

    return 0;
}

