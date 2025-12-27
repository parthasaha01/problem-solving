#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        double R1,R2,R3;
        scanf("%lf%lf%lf",&R1,&R2,&R3);

        double R1R2, R1R3, R2R3;
        R1R2 = R1+R2;
        R1R3 = R1+R3;
        R2R3 = R2+R3;

        double S = (R1R2 + R1R3 + R2R3) / 2.0;

        double A = sqrt(S*(S-R1R2)*(S-R1R3)*(S-R2R3));

        double r,r1,r2,r3,s1,s2,s3,a1,a2,a3,a;

        double lo=0.0;
        double hi=1000000005.0;

        for(int i=1; i<=200; i++)
        {
            r  = (lo+hi)/2.0;

            r1 = r+R1;
            r2 = r+R2;
            r3 = r+R3;

            s1 = (r1 + r2 + R1R2) / 2.0;
            s2 = (r1 + r3 + R1R3) / 2.0;
            s3 = (r2 + r3 + R2R3) / 2.0;

            a1 = sqrt(s1*(s1-r1)*(s1-r2)*(s1-R1R2));
            a2 = sqrt(s2*(s2-r1)*(s2-r3)*(s2-R1R3));
            a3 = sqrt(s3*(s3-r2)*(s3-r3)*(s3-R2R3));
            a  = a1+a2+a3;

            if(a<A)lo=r;
            else hi=r;
        }

        printf("%0.6lf\n",r);
    }

    return 0;
}
