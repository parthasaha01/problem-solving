#include<stdio.h>
int main()
{
    int T, amp, freq;
    int i, j, k, x, y, a, c;

    scanf("%d", &T);

    for(k=1; k <= T; k++)
    {
        scanf("%d %d", &amp, &freq);

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
                        printf("%d",x);
                    }

                    x++;
                }

                else if(a <= i && a > amp)
                {
                    for(c=0; c < y; c++)
                    {
                        printf("%d",y);
                    }
                    y--;
                }

                a++;
                printf("\n");
            }

            if(j<freq)printf("\n");

        }

        if(k<T)printf("\n");
    }

    return 0;
}

