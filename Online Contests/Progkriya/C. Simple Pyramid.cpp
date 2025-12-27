#include<bits/stdc++.h>
using namespace std;
struct PT{
    double x,y,z;
};
vector<PT>p;
PT H;
double TraingleArea(PT a,PT b,PT c)
{
    double x1,y1,z1;
    x1=a.x; y1=a.y; z1=a.z;
    double x2,y2,z2;
    x2=b.x; y2=b.y; z2=b.z;
    double x3,y3,z3;
    x3=c.x; y3=c.y; z3=c.z;

    double x = (x2*y1)-(x3*y1)-(x1*y2)+(x3*y2)+(x1*y3)-(x2*y3);
    x *= x;

    double y = (x2*z1)-(x3*z1)-(x1*z2)+(x3*z2)+(x1*z3)-(x2*z3);
    y *= y;

    double z = (y2*z1)-(y3*z1)-(y1*z2)+(y3*z2)+(y1*z3)-(y2*z3);
    z *= z;

    double area = sqrt(x+y+z);
    return (area/2.0);
}
double SurfaceArea()
{
    double area = 0.0;
    for(int i=0; i<p.size(); i++){
        int j = (i+1)%p.size();
        area += TraingleArea(p[i],p[j],H);
    }
    return area;
}
double ComputeArea()
{
    double area = 0.0;
    for(int i=0; i<p.size(); i++){
        int j = (i+1)%p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return fabs(area/2.0);
}
int main()
{
    int tt; cin>>tt;
    while(tt--)
    {
        int n; double h;
        cin>>n>>h;
        p.clear();
        for(int i=0; i<n; i++){
            double x,y; cin>>x>>y;
            PT u; u.x = x; u.y = y; u.z=0;
            p.push_back(u);
        }
        H.x=0; H.y=0; H.z =h;
        double B = ComputeArea();
        double V = (B*h)/3.0;
        double A = SurfaceArea();

        printf("%.9f %.9f\n",V,A);
    }
    return 0;
}
