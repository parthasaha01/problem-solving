#include<bits/stdc++.h>
using namespace std;
#define ll long long
    ll arr[110];
    ll c[110];
int main()
{
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        scanf("%lld",&c[i]);
    sort(c,c+n);

    ll cost=0;
    int cnt=0;
    int cur=1;
    for(int i=n-1;i>=0;i--)
    {
        cost += (arr[cur] + 1)*c[i];
        arr[cur]++;
        cur++;
        if(cur>k)cur=1;
    }
    cout<<cost<<endl;

    return 0;
}
