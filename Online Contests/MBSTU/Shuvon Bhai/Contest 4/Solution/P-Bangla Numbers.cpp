#include<cstdio>
using namespace std;
int kuti_number(long long);
int main()
{
    long long num, amount, test=0;

    while(scanf("%lld", &num) == 1)
    {
        printf("%4lld.",++test);

        if(num < 100)
        {
            printf(" %lld", num);
        }
        else
        {
            if(num >= 10000000)
            {
                amount = num/10000000;
                kuti_number(amount);
                num = num%10000000;
                printf(" kuti");
            }
            if(num >= 100000)
            {
                amount = num/100000;
                num = num%100000;
                printf(" %lld lakh", amount);
            }
            if(num >= 1000)
            {
                amount = num/1000;
                num = num%1000;
                printf(" %lld hajar", amount);
            }
            if(num >= 100)
            {
                amount = num/100;
                num = num%100;
                printf(" %lld shata", amount);
            }
            if(num != 0)
            {
                printf(" %lld", num);
            }
        }

        printf("\n");
    }

    return 0;
}
int kuti_number(long long num1)
{
    long long amount1;

        if(num1 >= 10000000)
        {
            amount1 = num1/10000000;
            num1 = num1%10000000;
            printf(" %lld kuti", amount1);
        }
        if(num1 >= 100000)
        {
            amount1 = num1/100000;
            num1 = num1%100000;
            printf(" %lld lakh", amount1);
        }
        if(num1 >= 1000)
        {
            amount1 = num1/1000;
            num1 = num1%1000;
            printf(" %lld hajar", amount1);
        }
        if(num1 >= 100)
        {
            amount1 = num1/100;
            num1 = num1%100;
            printf(" %lld shata", amount1);
        }
        if(num1 != 0)
        {
            printf(" %lld", num1);
        }

        return 0;

}
