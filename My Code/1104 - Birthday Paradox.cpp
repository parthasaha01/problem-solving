#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        double dn = (double)n;
        double p=1.0;
        int ans = 0;
        for(int i=0; i<=n; i++)
        {
            p *= ((double)(n-i))/dn;
            ans = i;
            if(p<=0.5)break;
        }

        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
