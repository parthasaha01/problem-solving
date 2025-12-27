#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int way[10005],a[105];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,k;
        scanf("%d%d",&n,&k);

        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        memset(way,0,sizeof(way));
        way[0]=1;

        for(int i=1; i<=n; i++)
        {
            for(int v=1; v<=k; v++)
            {
                if(v-a[i]>=0)
                {
                    way[v] += way[v-a[i]];
                    way[v]%=mod;
                }
            }
        }

        printf("Case %d: %d\n",ks,way[k]);
    }

    return 0;
}
