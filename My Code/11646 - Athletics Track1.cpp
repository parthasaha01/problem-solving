#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ks=1;
    double a,b;
    while(scanf("%lf : %lf",&a,&b)==2)
    {
        double hi=400.0;
        double lo=0.0;
        double L,W;
        for(int i=0; i<200; i++)
        {
            double md=(hi+lo)/2.0;
            L=md;
            W=(b*L)/a;
            double d=sqrt((L*L)+(W*W));
            double r=d/2;
            double v=((2*r*r)-(W*W))/(2*r*r);
            double ang=acos(v);
            double arc=r*ang;
            double peri=2*(L+arc);

            if(peri>400.0){
                hi=md;
            }
            else if(peri<400){
                lo=md;
            }
            else{
                break;
            }
        }

        printf("Case %d: %.8lf %.8lf\n",ks++,L,W);
    }

    return 0;
}

