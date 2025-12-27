#include<bits/stdc++.h>
using namespace std;
struct dt
{
    int lf,rg;
}st[200];
int a[200];
int main()
{
    int n,m;

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }

        for(int i=1; i<=m; i++)
        {
            int lf,rg;
            scanf("%d%d",&lf,&rg);
            st[i].lf = lf;
            st[i].rg = rg;
        }

        int ans=0;

        for(int i=1; i<=m; i++)
        {
            int lf,rg;
            lf = st[i].lf;
            rg = st[i].rg;
            int sum=0;
            for(int k=lf; k<=rg; k++)
            {
                sum+=a[k];
            }

            ans += max(0,sum);
        }


        printf("%d\n",ans);
    }

    return 0;
}
