#include<stdio.h>
int main()
{
    long int T, a, b, i;

    scanf("%ld", &T);

    for(i=1; i<=T; i++)
    {
        scanf("%ld %ld", &a, &b);

        printf("Case %ld: %ld\n", i, a+b);
    }

    return 0;
}
