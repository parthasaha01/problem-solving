#include<stdio.h>
int main()
{
    long int a[100], div, sum, i, j;

    for(i=0; i<99; i++)
    {
        scanf("%ld",&a[i]);
        if(a[i]==0)
            break;
    }
    printf("PERFECTION OUTPUT\n");

        for(j=0; j<i; j++)
        {
            sum=0;
            div=a[j]/2;
            while(div >= 1)
            {
                if(a[j]%div == 0)
                {
                    sum += div;
                }
                div--;
            }

            if(sum == a[j])
            {
                printf("%5ld  PERFECT\n",a[j]);
            }
            else if(sum < a[j])
            {
                printf("%5ld  DEFICIENT\n",a[j]);
            }
            else
            {
                printf("%5ld  ABUNDANT\n",a[j]);
            }
        }

        printf("END OF OUTPUT\n");

    return 0;
}
