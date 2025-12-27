#include<bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
 int main()
{
    double n, R, r;
    scanf("%lf %lf", &n, &R);

    r = ( sin(PI/n) / (1.0-sin(PI/n) ) ) * R;

    printf("%.10f\n", r);

    //main();

    return 0;
}
