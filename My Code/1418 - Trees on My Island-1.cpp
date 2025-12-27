#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int MAXN=10005;
struct Point{
    LL x,y;
}P[MAXN];
LL getArea(int n)
{
    // Shoelace formula
    // The vertices must be in clockwise or anti-clockwise order.
    // And they will form a simple polygon(don't cross)
    LL area=0;
    for(int i=0; i<n; i++){
        area += (P[i].x*P[i+1].y);
        area -= (P[i].y*P[i+1].x);
    }
    area = abs(area)/2;
    return area;
}
LL getTriangleArea(Point a,Point b,Point c)
{
    // Thus there are three points.
    // Their order will be always clockwise or anti-clockwise
    LL area = 0;
    area += (a.x*b.y) + (b.x*c.y) + (c.x*a.y);
    area -= (b.x*a.y) + (c.x*b.y) + (a.x*c.y);

    // LL area = (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
    // LL area = (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
    return area;
    // here area may be negetive
    // but we can not return abs(area)
}
LL getPolygonArea(int n)
{
    LL area=0;
    for(int i=0; i<n; i++){
        area += getTriangleArea(P[0],P[i],P[i+1]);
    }
    area = abs(area)/2;
    return area;
}
LL getBoundaryPoint(int n)
{
    LL boundaryPoint = 0;
    for(int i=0; i<n; i++){
        LL a = abs(P[i].x-P[i+1].x);
        LL b = abs(P[i].y-P[i+1].y);
        boundaryPoint += __gcd(a,b);
    }
    return boundaryPoint;
}
LL solve(int n)
{
    // Pick's Theorem : A = I + (B/2) - 1
    // Area = innerPoint + (BoundaryPoint/2) - 1
    // LL Area = getArea(n);
    LL Area = getPolygonArea(n);
    LL BoundaryPoint = getBoundaryPoint(n);
    LL InnerPoint = Area - (BoundaryPoint/2) + 1;
    return InnerPoint;
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        for(int i=0; i<n; i++){
            LL x,y; scanf("%lld %lld",&x,&y);
            P[i].x = x; P[i].y = y;
        }
        P[n].x = P[0].x; P[n].y = P[0].y;

        LL InnerPoint = solve(n);

        printf("Case %d: %lld\n",ks,InnerPoint);
    }
    return 0;
}

