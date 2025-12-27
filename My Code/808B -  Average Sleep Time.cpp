#include<bits/stdc++.h>
using namespace std;
#define ll long long
double a[200005],sum[200005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++)cin>>a[i];

    a[0]= 0.0;
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1]+a[i];
    }

    double ans = 0.0;
    for(int i=k; i<=n; i++){
        double temp = (sum[i]-sum[i-k])/(n-k+1.0);
        ans += temp;
    }

    cout<<fixed<<setprecision(10)<<ans<<endl;

    return 0;
}
