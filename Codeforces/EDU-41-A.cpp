#include<bits/stdc++.h>
using namespace std;
int fr[10000];
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);

    for(int i=1; i<=c; i++)
    {
        int x; scanf("%d",&x);
        fr[x]++;
    }
    int ans = 10000;
    for(int i=1; i<=n; i++)
    {
        ans = min(ans,fr[i]);
    }

    printf("%d\n",ans);

    return 0;
}
