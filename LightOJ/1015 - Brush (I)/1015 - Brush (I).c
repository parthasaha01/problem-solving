#include<stdio.h>
int main()
{
    long int T, N, sum, num, i=0;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &N);

        sum = 0;

        while(N--)
        {
            scanf("%ld", &num);

            if(num < 0)
                num = 0;

            sum += num;

        }

        printf("Case %ld: %ld\n", ++i, sum);
    }

    return 0;
}
