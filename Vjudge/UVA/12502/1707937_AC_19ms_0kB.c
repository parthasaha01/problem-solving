#include<stdio.h>
int main()
{
    long int T, i, x, y, z, A;

    scanf("%ld",&T);

    for(i=1; i<=T; i++)
    {
        scanf("%ld %ld %ld", &x, &y, &z);

        if(x>=y)
            A = (z * (2*x - y)) / (x+y);

        else
            A = z - ( (z* (2*y - x)) / (x+y) );

            printf("%ld\n", A);
    }

    return 0;
}