#include<bits/stdc++.h>
using namespace std;
int n,a[2005];
int fun(int v)
{
    int lo=1; int hi=n;
    int cnt=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(a[md]<v){
            cnt=md;
            lo=md+1;
        }
        else{
            hi=md-1;
        }
    }
    return cnt;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        sort(a+1,a+n+1);

        int ans=0;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<=n; j++){
                int sum = a[i]+a[j];
                int cnt = fun(sum)-j;
                ans += cnt;
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
