#include<bits/stdc++.h>
using namespace std;
double INF = 10000000000000.0;
double EPS = 1e-12;
double PI = acos(-1.0);
int main()
{
    printf("INTERSECTING LINES OUTPUT\n");
    int t; cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        double x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        double m1 = INF, m2 = INF;
        if((x2-x1)!=0.0) m1 = (y2-y1) / (x2-x1);
        if((x4-x3)!=0.0) m2 = (y4-y3) / (x4-x3);

        double a1,b1,c1;
        a1 = (y1-y2);
        b1 = (x2-x1);
        c1 = (y1*(x1-x2)) + (x1*(y2-y1));

        double a2,b2,c2;
        a2 = (y3-y4);
        b2 = (x4-x3);
        c2 = (y3*(x3-x4)) + (x3*(y4-y3));

        double a3,b3,c3;
        a3 = (y2-y3);
        b3 = (x3-x2);
        c3 = (y2*(x2-x3)) + (x2*(y3-y2));

        if(fabs(m1-m2)<EPS)
        {
            double v = ((a1*b3)-(b1*a3)) / ((a1*a3)+(b1*b3));
            double theta = atan(v);
            //double angle = atan(v) * (180.0 / PI);
            //printf("theta=%.6f angle=%.6f \n",theta,angle);
            if(fabs(theta-0.0)<EPS)
            {
                printf("LINE\n");
            }
            else
            {
                printf("NONE\n");
            }
        }
        else
        {
            double x,y;
            x = ((b1*c2)-(b2*c1)) / ((a1*b2)-(a2*b1));
            y = ((c1*a2)-(c2*a1)) / ((a1*b2)-(a2*b1));
            printf("POINT %.2f %.2f\n",x,y);
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}
