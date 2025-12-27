#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;
int x[1005],y[1005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s[n+5];
    for(int i=0; i<n; i++){
        cin>>s[i];
    }

    int a[n+5][m+5];
    ll dp[n+5][m+5], mp[n+5][m+5];
    for(int i=0; i<=n+2; i++){
        for(int j=0; j<=m+2; j++){
            dp[i][j]=mp[i][j]=a[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
            if(s[i][j]=='#')a[i+1][j+1]=1;
            else a[i+1][j+1]=0;
        }
    }

    dp[1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1&&j==1)continue;
            if(a[i][j]==0)dp[i][j]=0;
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }

    mp[n][m]=1;
    for(int i=n; i>=1; i--){
        for(int j=m; j>=1; j--){
            if(i==n&&j==m)continue;
            if(a[i][j]==0)mp[i][j]=0;
            else{
                mp[i][j] = mp[i][j+1]+mp[i+1][j];
                mp[i][j] %= mod;
            }
        }
    }

    int q; cin>>q;
    while(q--)
    {
        int p; cin>>p;
        for(int k=1; k<=p; k++){
            cin>>x[k]>>y[k];
        }

        ll ans = 0;
        for(int k=1; k<=p; k++){
            ans += (dp[x[k]][y[k]]*mp[x[k]][y[k]])%mod;
            ans %= mod;
        }
        cout << ans << endl;
    }

    return 0;
}
