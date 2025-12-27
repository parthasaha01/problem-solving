#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx+5],b[mx+5],cs[mx+5],n,m;
int UpperBound(int x)
{
    int lo=1;
    int hi=n;
    int ans=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(cs[md]==x)return md;
        if(cs[md]<x)lo=md+1;
        else {ans=md; hi=md-1;}
    }
    return ans;
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)cs[i]=cs[i-1]+a[i];
    scanf("%d",&m);
    for(int i=1; i<=m; i++)scanf("%d",&b[i]);

    for(int k=1; k<=m; k++){
        int x = b[k];
        int ans = UpperBound(x);
        printf("%d\n",ans);
    }

    return 0;
}
