#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx],s[mx],b[mx],t[mx];
int main()
{
    int n,k; scanf("%d%d",&n,&k);

    for(int i=1; i<=n; i++)scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)scanf("%d",&t[i]);

    for(int i=1; i<=n; i++){
        s[i] = s[i-1]+a[i];
        b[i] = b[i-1]+(t[i]*a[i]);
    }

    int ans = 0;

    for(int i=1; i<=n-k+1; i++)
    {
        int lo,md,hi,x,y;
        lo = b[i-1];
        md = s[i+k-1]-s[i-1];
        hi = b[n]-b[i+k-1];
        int sum = lo+md+hi;
        ans = max(ans,sum);
    }

    printf("%d\n",ans);
    return 0;
}
