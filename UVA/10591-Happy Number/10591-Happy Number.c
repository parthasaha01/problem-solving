#include<stdio.h>
int main()
{
    long int T, N, i=0, sum, num, rem;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &N);

        num = N;

        while(num > 9)
        {

            sum =0 ;

            while(num != 0)
            {
                rem = num%10;

                num = num/10;

                sum += (rem*rem);

            }

            num = sum;

        }

        if(num == 1 || num ==7)
        {
            printf("Case #%ld: %ld is a Happy number.\n", ++i, N);
        }
        else
        {
            printf("Case #%ld: %ld is an Unhappy number.\n", ++i, N);
        }

    }

    return 0;
}
