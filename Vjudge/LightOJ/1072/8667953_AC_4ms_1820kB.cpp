#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        double R,r,a,b,ang,v;
        int n;

        scanf("%lf %d",&R,&n);
        double lo=0.0;
        double hi=R;
        for(int i=1; i<=200; i++)
        {
            r = (lo+hi)/2.0;
            a = r+r;
            b = R-r;
            v = (b*b+b*b-a*a)/(2*b*b);
            ang = acos(v);
            ang = n*ang;
            ang = (ang*180.0)/(double)PI;

            if(ang<=360.0)lo=r;
            else hi=r;
        }

        printf("Case %d: %.10lf\n",ks,r);
    }

    return 0;
}
