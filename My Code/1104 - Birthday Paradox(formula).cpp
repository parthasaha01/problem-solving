#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        double sq = sqrt((double)n);
        int ans = (int)(1.177*sq);
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}

