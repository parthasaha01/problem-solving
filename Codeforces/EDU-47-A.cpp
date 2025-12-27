#include<bits/stdc++.h>
using namespace std;
int c[1005],a[1005];
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>c[i];
    }
    for(int i=1; i<=m; i++){
        cin>>a[i];
    }

    int ans = 0;
    for(int i=1,j=1; i<=n&&j<=m; i++){
        if(a[j]>=c[i]){
            ans++;
            j++;
        }
    }

    cout << ans << endl;

    //main();
    return 0;
}
