#include<bits/stdc++.h>
using namespace std;
int w[25];
int main()
{
    int n; scanf("%d",&n);
    int tot = 0;
    for(int i=0; i<n; i++){
        scanf("%d",&w[i]);
        tot += w[i];
    }

    int ans = 1000000000;

    for(int mask=0; mask<(1<<n); mask++)
    {
        int sum = 0;
        for(int i=0; i<n; i++){
            if(mask&(1<<i))sum+=w[i];
        }
        int d = abs(sum-(tot-sum));
        ans = min(ans,d);
    }

    printf("%d\n",ans);

    return 0;
}
