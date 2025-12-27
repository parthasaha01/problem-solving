#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
int main()
{
    ll n,k; scanf("%I64d %I64d",&n,&k);

    for(int i=1; i<=k; i++)
    {
        scanf("%d",&a[i]);
    }

    ll minn = 1000000000000000005;
    ll type,cnt;
    type = 1;
    cnt = n/a[1];

    for(int i=1; i<=k; i++)
    {
        ll r = n%a[i];
        ll d = n/a[i];

        if(r<minn){
            minn = r;
            type = i;
            cnt = d;
        }
    }

    printf("%I64d %I64d\n",type,cnt);

    //main();

    return 0;
}

