#include<stdio.h>
int main()
{
    long int N, sqr;

    while(scanf("%ld", &N)==1 && N != 0)
    {
        sqr = (N* (N+1)*(2*N+1))/6;

        printf("%ld\n", sqr);
    }

    return 0;
}
