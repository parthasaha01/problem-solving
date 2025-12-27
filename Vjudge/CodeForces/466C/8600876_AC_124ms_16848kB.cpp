#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 500005
ll a[mx+5],sum[mx+5],sec[mx+5];
vector<int>v;
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%I64d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }

    if(sum[n]%3 != 0){
        printf("0\n");
        return 0;
    }

    ll each = sum[n]/3;

    for(int i=1; i<=n; i++)
    {
        if(sum[i]==each && i<n-1){
            v.push_back(i);
        }

        if(sum[i]==2*each && i<n){
            sec[i]=sec[i-1]+1;
        }
        else{
            sec[i]=sec[i-1];
        }
    }

    ll ans=0;

    for(int i=0; i<v.size(); i++)
    {
        int x = v[i];
        ans += sec[n]-sec[x];
    }

    printf("%I64d\n",ans);

    return 0;
}
