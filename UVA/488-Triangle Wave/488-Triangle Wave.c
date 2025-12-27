#include<stdio.h>
int main()
{
    long int T, amp, freq;
    long int i, j, k, x, y, a, c;

    scanf("%ld", &T);

    for(k=1; k <= T; k++)
    {
        scanf("%ld %ld", &amp, &freq);

        for(j=1;  j<=freq;  j++)
        {
            a=1;
            x=1;
            y=amp-1;

            for(i=1; i <= 2*amp-1; i++)
            {
                if(a <= amp && a <= i)
                {
                    for(c=0; c < x; c++)
                    {
                        printf("%ld",x);
                    }

                    x++;
                }

                else if(a <= i && a > amp)
                {
                    for(c=0; c < y; c++)
                    {
                        printf("%ld",y);
                    }
                    y--;
                }

                a++;
                printf("\n");
            }

            if(k != T || j != freq)
            printf("\n");

        }

    }

    return 0;
}
