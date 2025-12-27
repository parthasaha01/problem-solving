#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int fun(int x)
{
    int lo=1;
    int hi=n;
    int ans1=1000000000;

    while(lo<=hi)
    {
        int md=(lo+hi)/2;

        if(a[md]==x)return 0;
        if(a[md]<x){
            ans1=abs(a[md]-x);
            lo=md+1;
        }
        else{
            hi=md-1;
        }
    }

    lo=1;
    hi=n;
    int ans2=1000000000;

    while(lo<=hi)
    {
        int md=(lo+hi)/2;

        if(a[md]==x)return 0;
        if(a[md]<x){
            lo=md+1;
        }
        else{
            ans2=abs(a[md]-x);
            hi=md-1;
        }
    }

    int ans = min(ans1,ans2);
    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);

        int ans=1000000000;

        scanf("%d",&m);
        for(int i=1; i<=m; i++){
            int x; scanf("%d",&x);
            int df = fun(x);
            ans = min(ans,df);
        }

        printf("%d\n",ans);
    }

    return 0;
}
