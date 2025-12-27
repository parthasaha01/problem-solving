#include<stdio.h>
int main()
{
    long int N,div,sum;

    printf("PERFECTION OUTPUT\n");

    while(scanf("%ld",&N)==1 && N != 0)
    {
            sum=0;
            div=N/2;
            while(div >= 1)
            {
                if(N%div == 0)
                {
                    sum += div;
                }
                div--;
            }

            if(sum == N)
            {
                printf("%5ld  PERFECT\n",N);
            }
            else if(sum < N)
            {
                printf("%5ld  DEFICIENT\n",N);
            }
            else
            {
                printf("%5ld  ABUNDANT\n",N);
            }
    }
    printf("END OF OUTPUT\n");

    return 0;
}
