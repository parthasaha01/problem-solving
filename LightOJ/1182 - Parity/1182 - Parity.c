#include<stdio.h>

int main()
{
    long int T, n, i, parity;

    scanf("%ld", &T);

    for(i=1; i<=T; i++)
    {
        parity = 0;

        scanf("%ld", &n);

        while(n != 0)
        {
            if(n%2 == 1)
                ++parity;

            n = n/2;
        }

        if(parity%2 == 0)
            printf("Case %ld: even\n", i);
        else
            printf("Case %ld: odd\n", i);
    }

    return 0;
}
