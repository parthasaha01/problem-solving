#include<stdio.h>
int main()
{
    long long T, i, sum, n, m;

    scanf("%lld", &T);

    for(i=1; i<=T; i++)
    {
        scanf("%lld %lld", &n, &m);

        sum = (n*m)/2;

        printf("Case %lld: %lld\n", i, sum);
    }

    return 0;
}
