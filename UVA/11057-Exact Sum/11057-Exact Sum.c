#include<stdio.h>
int main()
{
    long int N, M, i, j, k, x, min_;

    while(scanf("%ld\n", &N)==1)
    {
        long int a[N], first[N], second[N], diff[N];

        for(i=0; i<N; i++)
            scanf("%ld", &a[i]);

        scanf("%ld", &M);

        min_=1000000;
        k=0;

        for(i=0; i<N-1; i++)
        {
            for(j=i+1; j<N; j++)
            {
                if(a[i]+a[j] == M)
                {
                    if(a[i] < a[j])
                    {
                        first[k] = a[i];
                        second[k] = a[j];
                    }
                    else
                    {
                        first[k] = a[j];
                        second[k] = a[i];
                    }

                    diff[k] = second[k] - first[k];
                    ++k;
                }
            }
        }

            for(i=0; i<k; i++)
            {
                if(diff[i] < min_)
                {
                    min_ = diff[i];
                    x=i;
                }
            }

            printf("Peter should buy books whose prices are %ld and %ld.\n\n", first[x], second[x]);

    }

    return 0;
}
