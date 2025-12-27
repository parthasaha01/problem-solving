#include<stdio.h>
#include<math.h>
int main()
{
    long int N, i, prime, num, rev, rem;
    double root;

    while(scanf("%ld", &N)==1)
    {
        if(N == 2)
            prime = 1;
        else if(N % 2 == 0)
            prime = 0;
        else
        {
            root = sqrt(N);

            prime = 1;

            for(i=3; i <= (int)root; i += 2)
            {
                if(N%i == 0)
                {
                    prime=0;
                    break;
                }
                prime = 1;
            }

            if(prime == 1)
            {
                num = N;
                rev = 0;

                while(num != 0)
                {
                    rem = num%10;
                    rev = (rev*10)+rem;
                    num = num/10;
                }

                if( rev != N)
                {
                    if(rev%2 == 0)
                        prime = 1;
                    else
                    {
                        root = sqrt(rev);
                        for(i=3; i <= (int)root; i += 2)
                        {
                            if(rev % i == 0)
                            {
                                prime = 1;
                                break;
                            }
                            prime = 2;
                        }
                    }
                }
            }
        }

        if(prime == 0)
            printf("%ld is not prime.\n", N);
        else if(prime == 1)
            printf("%ld is prime.\n", N);
        else
            printf("%ld is emirp.\n", N);
    }

    return 0;
}
