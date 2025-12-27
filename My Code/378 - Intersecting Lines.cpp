#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 10000000000000LL
double EPS = 1e-12;
double PI = acos(-1.0);
int main()
{
    printf("INTERSECTING LINES OUTPUT\n");
    LL t; cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        LL x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        double m1=INF,m2=INF;
        if((x1-x2)!=0) m1 = (double)(y1-y2) / (double)(x1-x2);
        if((x3-x4)!=0) m2 = (double)(y3-y4) / (double)(x3-x4);

        LL a1,b1,c1;
        a1 = (y1-y2);
        b1 = (x2-x1);
        c1 = (y1*(x1-x2)) - (x1*(y1-y2));

        LL a2,b2,c2;
        a2 = (y3-y4);
        b2 = (x4-x3);
        c2 = (y3*(x3-x4)) - (x3*(y3-y4));

        LL g1 = __gcd(a1,__gcd(b1,c1));
        a1 /= g1; b1 /= g1; c1 /= g1;

        LL g2 = __gcd(a2,__gcd(b2,c2));
        a2 /= g2; b2 /= g2; c2 /= g2;


        if(fabs(m1-m2)<EPS)
        {
            if(a1==a2 && b1==b2 && c1==c2) printf("LINE\n");
            else printf("NONE\n");
        }
        else
        {
            double x,y;
            x = (double)((b1*c2)-(b2*c1)) / (double)((a1*b2)-(a2*b1));
            y = (double)((c1*a2)-(c2*a1)) / (double)((a1*b2)-(a2*b1));

            printf("POINT %.2f %.2f\n",x,y);
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}
