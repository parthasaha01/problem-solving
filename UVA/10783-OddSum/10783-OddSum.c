#include<stdio.h>
int main()
{
    long int T,n,i,a, b, sum;

    scanf("%ld",&T);

    for(i=1; i <= T; i++)
    {
        scanf("%ld %ld", &a, &b);
        if(a%2 == 0)
        {
            a += 1;
        }
        if(b%2 == 0)
        {
            b -= 1;
        }
        sum = 0;
        for(n=a; n <= b; n+=2)
        {
            sum += n;
        }
        printf("Case %ld: %ld\n", i, sum);
    }

    return 0;
}
