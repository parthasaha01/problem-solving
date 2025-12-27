#include<cstdio>
#include<cmath>
#define max 10000000
using namespace std;

long check(long n, long pos)
{
        return n & (1<<pos);   // if it is prime, it returns 0
}

long set(long n, long pos)
{
    return n | (1<<pos);
}

int main()
{
    long i, j, sqrtN, N;
    long prime[max>>5], p=0;

    scanf("%ld", &N);

    sqrtN = (long) sqrt(N);

    for(i=3; i<=sqrtN; i+=2)
    {
        printf("i=%ld   %ld\n",i,check(prime[i>>5], i&31));

        if(!check(prime[i>>5], i&31))             //  (i >> 5) means ( i / 2^5) where 2^5=32
        {
           // printf("i=%ld   %ld\n",i,check(prime[i>>5], i&31));

            for(j=i*i; j<=N; j += (i<<1))           // ( i<<1) means ( i*2)
            {
                prime[j>>5] = set(prime[j>>5], j&31);           // ( i & 31 ) means ( i % 32 )

                printf("j=%ld   %ld\n",j,set(prime[j>>5], j&31));
            }
        }
    }

    if(N>1)
    {
        printf("2 ");
        ++p;
    }
    for(i=3;i<=N;i+=2)
    {
        if( !check(prime[i>>5], i&31))
        {
            printf("%ld ",i);
            ++p;
        }
    }

    printf("\n\nTotal prime is: %ld\n", p);

    return 0;
}
