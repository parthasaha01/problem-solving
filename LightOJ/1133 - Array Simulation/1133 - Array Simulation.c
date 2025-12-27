#include<stdio.h>
int main()
{
    long int T, n, m, i, j, Z, K, temp;
    char ch;

    scanf("%ld", &T);

    for(i=1; i<=T; i++)
    {
        scanf("%ld %ld", &n, &m);

        long int a[n], b[n];

        for(j=0; j<n; j++)
        {
            scanf("%ld", &a[j]);
        }

        getchar();

        while(m--)
        {
            scanf("%c", &ch);

            if(ch == 'S')
            {
                scanf("%ld", &K);

                for(j=0; j<n; j++)
                    a[j] = a[j]+K;
            }

            if(ch == 'M')
            {
                scanf("%ld", &K);

                for(j=0; j<n; j++)
                    a[j] = a[j]*K;
            }

            if(ch == 'D')
            {
                scanf("%ld", &K);

                for(j=0; j<n; j++)
                    a[j] = a[j] / K;
            }

            if(ch == 'R')
            {
                for(j=0; j<n; j++)
                    b[j] = a[j];

                for(j=0; j<n; j++)
                    a[j] = b[n-j-1];
            }

            if(ch == 'P')
            {
                scanf("%ld %ld", &K, &Z);

                temp = a[K];
                a[K] = a[Z];
                a[Z] = temp;
            }

            if(m > 0)
            getchar();
        }

        printf("Case %ld:\n", i);

        for(j=0; j<n; j++)
        {
            printf("%ld", a[j]);

            if(j < n-1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
