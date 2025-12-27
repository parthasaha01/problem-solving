#include<bits/stdc++.h>
using namespace std;
int fr[105],a[55][2];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(fr,0,sizeof(fr));

        for(int i=1; i<=n; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            a[i][0]=u;
            a[i][1]=v;
            fr[u]++;
            fr[v]++;
        }

        int maxx  = 0;
        for(int i=1; i<=n; i++)
        {
            maxx = max(maxx,fr[i]);
        }

        int ans = 0;
        for(int i=1; i<=n; i++)
        {

        }

        printf("%d\n",ans);
    }
    return 0;
}
