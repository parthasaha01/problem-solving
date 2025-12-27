#include<stdio.h>
int main()
{
    long int T, N, i, j=0, max_, a;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &N);

        max_ = 0;

        for(i=0; i<N; i++)
        {
            scanf("%ld", &a);

            if(a > max_)
                max_ = a;
        }

        printf("Case %ld: %ld\n", ++j, max_);
    }

    return 0;
}
