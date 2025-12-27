#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[] = {4,8,9,12,13,16,17,18,20,21,22};
int vis[30];
int main()
{
    for(int i=0; i<=10; i++)vis[a[i]]=1;

    int tt; scanf("%d",&tt);

    while(tt--)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        if(l>r)swap(l,r);

        ll ans = 0;
        for(ll i=l; i<=22&&i<=r; i++)
        {
            if(vis[i]==1)ans++;
        }

        if(r>=24){
            l = max(24LL,l);
            ans += (r-l+1);
        }

        printf("%lld\n",ans);
    }
    return 0;
}
