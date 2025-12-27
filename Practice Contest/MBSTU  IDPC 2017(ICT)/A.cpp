#include<bits/stdc++.h>
using namespace std;
#define mx 100015
int n,m,a[mx+5],cum[mx+5];
int binarySearch(int st)
{
    int lo=st;
    int hi=n;
    int maxx=0;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int vv = cum[md]-cum[st-1];

        if(vv<=m){
            maxx = max(maxx,vv);
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }

    return maxx;
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&m);

        for(int i=1; i<=n; i++) scanf("%d",&a[i]);

        for(int i=1; i<=n; i++) cum[i] = cum[i-1]+a[i];

        int ans=0;

        for(int i=1; i<=n; i++)
        {
            int maxx = binarySearch(i);
            ans = max(maxx,ans);
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
