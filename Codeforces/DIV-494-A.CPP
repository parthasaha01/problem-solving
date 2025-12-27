#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main()
{
    int n; cin>>n;
    int ans = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        b[a[i]]++;
        ans = max(ans,b[a[i]]);
    }

    cout << ans << endl;

    return 0;
}
