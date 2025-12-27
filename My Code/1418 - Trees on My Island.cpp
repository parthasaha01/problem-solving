#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int MAXN=10005;
struct Point{
    LL x,y;
}P[MAXN];
LL getArea(int n)
{
    LL sum1=0,sum2=0;
    for(int i=0; i<n; i++){
        sum1 += (P[i].x*P[i+1].y);
        sum2 += (P[i].y*P[i+1].x);
    }
    LL area = abs(sum1-sum2);
    return area/2;
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
    LL Area = getArea(n);
    LL boundaryPoint = getBoundaryPoint(n);
    LL innerPoint = Area - (boundaryPoint/2) + 1;
    return innerPoint;
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

        LL innerPoint = solve(n);

        printf("Case %d: %lld\n",ks,innerPoint);
    }
    return 0;
}
