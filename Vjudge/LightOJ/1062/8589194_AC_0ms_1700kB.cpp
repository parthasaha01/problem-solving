#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        double x,y,c,hx,hy,z,cc;

        scanf("%lf%lf%lf",&x,&y,&c);

        double lo = 0.0;
        double hi = min(x,y);

        for(int i=1; i<=200; i++)
        {
            double md = (lo+hi)/2.0;

            z = md;
            hx = sqrt(x*x - z*z);
            hy = sqrt(y*y - z*z);
            cc = (hx*hy)/(hx+hy);

            if(cc>c)lo=md;
            else hi=md;
        }

        printf("Case %d: %.10lf\n",ks,z);
    }

    return 0;
}

