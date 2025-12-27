#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s; cin>>n>>s;
    int ans = 0;
    for(int i=n; i>=1; i--){
        int ret = (s/i);
        if(ret>0){
            ans += ret;
            s -= (ret*i);
        }
        if(s<=0)break;
    }

    cout << ans << endl;

   // main();

    return 0;
}
