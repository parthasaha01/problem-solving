#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,m;
    scanf("%lf%lf",&n,&m);
    double minn = 1000000000.0;

    for(int i=1; i<=n; i++)
    {
        double a,b;
        scanf("%lf%lf",&a,&b);
        double d = a/b;
        minn = min(minn,d);
    }

    double ans = minn*m;

    printf("%.8lf\n",ans);

    return 0;
}
