#include<stdio.h>
#include<math.h>
int main()
{
    long long T, k, i=0;
    double tax;

    scanf("%lld", &T);

    while(T--)
    {
        scanf("%lld", &k);

        if(k <= 180000)
            tax=0.0;
        else if(k <= 480000)
        {
            k=k-180000;

            tax = (k*10)/100.0;

            if(tax < 2000.0)
                tax = 2000.0;
        }
        else if(k <= 880000)
        {
            k=k-480000;

            tax = 30000.0+((k*15)/100.0);

        }
        else if(k <= 1180000)
        {
            k=k-880000;

            tax = 90000.0+((k*20)/100.0);
        }
        else
        {
            k = k-1180000;

            tax = 150000.0+((k*25)/100.0);
        }

        tax = ceil(tax);

        printf("Case %lld: %0.0lf\n", ++i, tax);


    }

    return 0;

}
