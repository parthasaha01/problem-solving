#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1005],b[1005],c[1005];
bool binarySearch(ll v,ll n)
{
    ll lo=1, hi=n;
    while(lo<=hi){
        ll md = (lo+hi)/2;
        if(c[md]==v)return true;
        if(c[md]>v)hi=md-1;
        else lo=md+1;
    }
    return false;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll sa,sb,sc,ss;
        scanf("%lld%lld%lld%lld",&sa,&sb,&sc,&ss);

        for(int i=1; i<=sa; i++)scanf("%lld",&a[i]);
        for(int i=1; i<=sb; i++)scanf("%lld",&b[i]);
        for(int i=1; i<=sc; i++)scanf("%lld",&c[i]);

        if(sa==0 || sb==0 || sc==0){
            printf("Case %d: NO\n",ks);
            continue;
        }

        sort(c+1,c+sc+1);

        bool flag = false;

        for(int i=1; i<=sa; i++){
            for(int j=1; j<=sb; j++){
                flag = binarySearch(ss-a[i]-b[j],sc);
                if(flag)break;
            }
            if(flag)break;
        }

        if(flag)printf("Case %d: YES\n",ks);
        else printf("Case %d: NO\n",ks);
    }
    return 0;
}
