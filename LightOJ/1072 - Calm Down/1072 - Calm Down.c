#include<stdio.h>
#include<math.h>
#define PI 2*acos(0.0)

int main()
{
    long int T, i=0, n;
    double R, r;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%lf %ld", &R, &n);

        r = ( sin(PI/n) / (1+sin(PI/n) ) ) * R;

        if(r == (int)r)
            printf("Case %ld: %d\n", ++i, (int)r);

        else
            printf("Case %ld: %.10lf\n", ++i, r);
    }

    return 0;
}
