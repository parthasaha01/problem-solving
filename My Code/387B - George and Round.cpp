#include<bits/stdc++.h>
using namespace std;
int n,m,a[3005],b[3005],cnt[1000005],f[3005],g[3005];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=m; i++)cin>>b[i];

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(g[j]==0 && b[j]>=a[i]){
                g[j]=1;
                f[i]=1;
                break;
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(f[i]==0)ans++;
    }

    cout << ans << endl;

    return 0;
}
