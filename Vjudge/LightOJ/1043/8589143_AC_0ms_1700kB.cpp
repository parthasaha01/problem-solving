#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        double AB,AC,BC,RATIO,AD,DE,AE,ADE,BCED,ABC,RAT,S;

        scanf("%lf%lf%lf%lf",&AB,&AC,&BC,&RATIO);

        S = (AB+AC+BC)/2.0;

        ABC = sqrt(S*(S-AB)*(S-AC)*(S-BC));

        double lo = 0.0;
        double hi = AB;

        for(int i=1; i<=200; i++)
        {
            double md = (lo+hi)/2.0;

            AD = md;
            AE = (AD*AC)/AB;
            DE = (AD*BC)/AB;

            S = (AD+AE+DE)/2.0;
            ADE = sqrt(S*(S-AD)*(S-AE)*(S-DE));
            BCED = ABC-ADE;

            RAT = ADE/BCED;

            if(RAT>RATIO)hi=md;
            else lo=md;
        }

        printf("Case %d: %.10lf\n",ks,AD);
    }

    return 0;
}
