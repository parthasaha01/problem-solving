#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main()
{
    int n; scanf("%d",&n);
    int k = n/2;
    for(int i=1; i<=k; i++){
        scanf("%d",&a[i]);
    }

    sort(a+1,a+k+1);

    int cnt1 = 0;
    int cur = 1;
    for(int i=1; i<=k; i++)
    {
        cnt1 += abs(a[i]-cur);
        cur += 2;
    }

    int cnt2 = 0;
    cur = 2;
    for(int i=1; i<=k; i++)
    {
        cnt2 += abs(a[i]-cur);
        cur += 2;
    }

    int ans = min(cnt1,cnt2);

    printf("%d\n",ans);

    return 0;
}
