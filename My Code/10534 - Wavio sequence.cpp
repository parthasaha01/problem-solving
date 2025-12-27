#include<bits/stdc++.h>
using namespace std;
int n,L[10005],R[10005],a[10005],s[10005];
int binarySearch(int v)
{
    int lo=0;
    int hi=n;
    int ans;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(s[md]<v){
            ans=md;
            lo=md+1;
        }
        else{
            hi = md-1;
        }
    }
    return ans+1;
}
int main()
{
    while(scanf("%d",&n)==1)
    {

        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        s[0] = -1000000000;
        for(int i=1; i<=n; i++)
            s[i]=1000000000;

        int lis = 0;

        for(int i=1; i<=n; i++)
        {
            int v = a[i];
            int p = binarySearch(v);
            s[p] = v;
            L[i] = p;
        }

        s[0] = -1000000000;
        for(int i=1; i<=n; i++)
            s[i]=1000000000;

        for(int i=n; i>=1; i--)
        {
            int v = a[i];
            int p = binarySearch(v);
            s[p] = v;
            R[i] = p;
        }

        for(int i=1; i<=n; i++){
            int x = min(L[i],R[i]);
            s[i] = 2*x-1;
        }

        int ans=0;
        for(int i=1; i<=n; i++){
            ans = max(ans,s[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

