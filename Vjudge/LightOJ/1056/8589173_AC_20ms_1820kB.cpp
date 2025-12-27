#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        double a,b,L,W,S,PERI,r,ang;

        scanf("%lf : %lf",&a,&b);

        double lo = 0.0;
        double hi = 400.0;

        for(int i=1; i<=200; i++)
        {
            double md = (lo+hi)/2.0;

            L = md;
            W = (b/a)*L;

            r = sqrt(L*L + W*W) / 2.0;
            ang = acos((r*r + r*r - W*W)/(2*r*r));
            S = r*ang;
            PERI = 2*(L+S);

            if(PERI<400.0)lo=md;
            else hi=md;
        }

        printf("Case %d: %.10lf %.10lf\n",ks,L,W);
    }

    return 0;
}

