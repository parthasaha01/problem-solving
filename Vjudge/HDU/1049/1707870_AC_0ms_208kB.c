#include<stdio.h>
int main()
{
    long int n,  u, d, x, time, i;
    double diff, y;

    while(scanf("%ld %ld %ld", &n, &u, &d) == 3)
    {
        if(n == 0)
            break;

        x = n-u;

        diff = u-d;

        y = x/diff;

        if( y == (int)y)
            i = y;
        else
            i = y+1;

        time = i+i+1;

        printf("%ld\n", time);

    }

    return 0;
}