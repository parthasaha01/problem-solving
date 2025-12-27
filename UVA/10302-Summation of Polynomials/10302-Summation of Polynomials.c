#include<stdio.h>
int main()
{
    long int n,sum;

    while(scanf("%ld",&n) == 1)
    {
        sum=((n*(n+1))/2)*((n*(n+1))/2);
        printf("%ld\n",sum);
    }

    return 0;
}
