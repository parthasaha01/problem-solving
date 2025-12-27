#include<bits/stdc++.h>
using namespace std;
#define mx 100002
struct dt
{
    int lf,rg,df;
}st[mx+5];
int a[mx+5];
int main()
{
    int n,m;

    while(scanf("%d%d",&n,&m)==2)
    {
        int maxx=-1;
        for(int i=1; i<=m; i++)
        {
            int lf,rg,df;
            scanf("%d%d",&lf,&rg);
            df = rg-lf+1;
            st[i].lf = lf;
            st[i].rg = rg;
            st[i].df = df;
            maxx=min(maxx,df);
        }

        int ans=0;

        for(int i=1; i<=m; i++)
        {

        }


        printf("%d\n",ans);
    }

    return 0;
}
