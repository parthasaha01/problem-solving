#include<stdio.h>
int main()
{
    double N, M, C, diff, i, j;

    while(scanf( "%lf %lf", &N, &M) == 2)
    {
        if(N == 0.0 && M == 0.0)
            break;

        if(N == M)
        {
            printf("%.0lf things taken %.0lf at a time is 1 exactly.\n", N, M);
            continue;
        }

        C=1;
        diff = N-M;

        if(diff > M)
        {
            i = diff+1;
            j=2;

            while(i <= N)
            {
                C = C*i;
                i = i+1;

                if(j <= M)
                {
                    C = C/j;
                    j = j+1;
                }
            }
        }
        else
        {
            i = M+1;
            j=2;

            while(i <= N)
            {
                C = C*i;
                i = i+1;

                if(j <= diff)
                {
                    C = C/j;
                    j = j+1;
                }
            }

        }

        printf("%.0lf things taken %.0lf at a time is %.0lf exactly.\n", N, M, C);
    }

    return 0;
}
