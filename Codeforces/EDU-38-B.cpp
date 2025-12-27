#include<bits/stdc++.h>
using namespace std;
int a[100005];
int xx[100005];
int main()
{
    int n; scanf("%d",&n);

    int ans = 0;

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        xx[i] = min(a[i]-1,1000000-a[i]);
        ans = max(ans,xx[i]);
    }

    printf("%d\n",ans);

    return 0;
}
