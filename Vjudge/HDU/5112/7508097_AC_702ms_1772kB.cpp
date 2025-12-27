#include<bits/stdc++.h>
using namespace std;
struct dt
{
    double tx,xx;
}st[10005];
bool cmp(dt ax, dt bx)
{
    return ax.tx<bx.tx;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%lf %lf",&st[i].tx,&st[i].xx);
        }

        sort(st+1,st+n+1,cmp);

        double maxx=0.0;

        double ptx,pxx;
        ptx=st[1].tx;
        pxx=st[1].xx;
        for(int i=2; i<=n; i++)
        {
            double btx,bxx;
            btx=st[i].tx;
            bxx=st[i].xx;
            double dtx=abs(btx-ptx);
            double dxx=abs(bxx-pxx);
            double v=dxx/dtx;
            if(v>=maxx){
                maxx=v;
            }
            ptx=btx;
            pxx=bxx;
        }

        printf("Case #%d: %.2lf\n",ks,maxx);
    }

    return 0;
}
