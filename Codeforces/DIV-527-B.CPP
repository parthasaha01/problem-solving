#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    int ans = 0;
    for(int i=1; i<=n; i+=2){
        ans += (a[i+1]-a[i]);
    }

    cout << ans << endl;
    //main();
    return 0;
}
