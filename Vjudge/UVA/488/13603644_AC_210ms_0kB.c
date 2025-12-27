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
            for(x=1; x<=amp; x++)
            {
                for(y=1; y<=x; y++)
                {
                    printf("%d",x);
                }
                printf("\n");
            }

            for(x=amp-1; x>=1; x--)
            {
                for(y=x; y>=1; y--)
                {
                    printf("%d",x);
                }
                printf("\n");
            }

            if(j<freq)printf("\n");

        }

        if(k<T)printf("\n");
    }

    return 0;
}

