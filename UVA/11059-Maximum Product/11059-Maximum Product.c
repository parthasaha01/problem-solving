#include<stdio.h>
long long Max_product(long long N)
{
    long long i, ara[N], Maxp=0, product , k;

    for(i=0; i<N; i++)
        scanf("%lld", &ara[i]);


    for(i=0; i<N; i++)
    {
        product=1;
        for(k=i; k<N && product; k++)
        {
            product *= ara[k];

            if(product > Maxp)
                Maxp=product;
        }
    }

    return Maxp;
}
int main()
{
    long long N, Max, test=1;

    while(scanf("%lld", &N)==1)
    {
        Max = Max_product(N);

        printf("Case #%lld: The maximum product is %lld.\n\n", test++, Max);

    }

    return 0;
}
