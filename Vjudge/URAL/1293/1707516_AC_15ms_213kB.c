#include<stdio.h>
int main()
{
    long int N, A, B, res;

    while(scanf("%ld %ld %ld", &N, &A, &B) == 3)
    {
        res = (A*B)*(N*2);

        printf("%ld\n", res);
    }

    return 0;
}