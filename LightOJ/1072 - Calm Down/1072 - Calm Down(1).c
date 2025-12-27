#include<stdio.h>
#include<math.h>
#define PI acos(-1)

int main()
{
    long int T, i=0, n;
    double R, r;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%lf %ld", &R, &n);

        r = ( sin(PI/n) / (1+sin(PI/n) ) ) * R;

            printf("Case %ld: %.10lf\n", ++i, r);
    }

    return 0;
}
