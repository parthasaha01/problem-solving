#include<bits/stdc++.h>
using namespace std;
int main()
{
    int maxx=0;
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        int x; scanf("%d",&x);
        maxx=max(x,maxx);
    }

    int ans = maxx-25;
    ans = max(0,ans);
    printf("%d\n",ans);

    return 0;
}
