#include<stdio.h>
int main()
{
    long long T,rev, C, Q, D, N, P, i=0;

    scanf("%lld", &T);

    while(T--)
    {
        Q = 0,D = 0, N = 0, P = 0;

        scanf("%lld", &C);

            if(C >= 25)
            {
                rev = C / 25;
                Q += rev;
                C = C % 25;
            }
            if(C >= 10)
            {
                rev = C / 10;
                D += rev;
                C = C % 10;
            }
            if(C >= 5)
            {
                rev = C / 5;
                N += rev;
                C = C % 5;
            }

            P = C;

            printf("%lld %lld QUARTER(S), %lld DIME(S), %lld NICKEL(S), %lld PENNY(S)\n", ++i, Q, D, N, P);


    }

    return 0;
}