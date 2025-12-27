#include<bits/stdc++.h>
using namespace std;
double sum[5005],a[5005];
int n,k;
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++)cin>>a[i];

    sum[0]=0.0;
    for(int i=1; i<=n; i++)sum[i] = sum[i-1]+a[i];

    double ans = 0.0;
    for(int x=k; x<=n; x++){
        for(int i=1; i+x-1<=n; i++){
            double avg = (sum[i+x-1]-sum[i-1])/(double)x;
            ans = max(ans,avg);
        }
    }

    printf("%.15f\n",ans);

    return 0;
}
