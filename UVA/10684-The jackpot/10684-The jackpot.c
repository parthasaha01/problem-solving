#include<stdio.h>
int main()
{
    long int N, Max, i, sum, num;

    while(scanf("%ld", &N) && N)
    {

        Max = sum = 0;

        for(i=0; i<N; i++)
        {
            scanf("%ld", &num);

            sum += num;

            if(sum < 0)
                sum = 0;

            if(sum > Max)
                Max = sum;

        }

        if(Max)
            printf("The maximum winning streak is %ld.\n", Max);
        else
            printf("Losing streak.\n");

    }

    return 0;
}
