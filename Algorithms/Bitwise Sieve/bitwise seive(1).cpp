#include<cstdio>
#include<cmath>
#define max 10000000
using namespace std;

//This function is used to check a bit position. The pos th bit of the integer n is checked by this.
//It returns 1 if the bit position is ON or 1 that means this is prime
// Otherwise retruns 0;

// prime[0] er zero bit(right most bit) represents primelity of number 0
// prime[0] er 1st bit(right most bit er previous bit) represents primelity of number 1
// prime[0] er 2nd bit represents primelity of number 2
// prime[0] er 31st bit represents primelity of number 31
// prime[1] er zero bit(right most bit) represents primelity of number 32
// prime[1] er 1st bit(right most bit er previous bit) represents primelity of number 33
// prime[2] er zero bit(right most bit) represents primelity of number 64

int check(long n, long pos)
{
    if(n & (1<<pos))
        return 1;
    else
        return 0;     // if it is prime
}

//This function is used to Set  a bit position of integer n. the pos th bit is setted ON or 1.

long set(long n, long pos)
{
    n = n | (1<<pos);
    return n;
}

int main()
{
    long i, j, sqrtN, N;
    long prime[max>>5], p=0;

    scanf("%ld", &N);

    sqrtN = (long) sqrt(N);

    for(i=3; i<=sqrtN; i+=2)
    {
        if(check(prime[i>>5], i&31)==0)             //  (i >> 5) means ( i / 2^5) where 2^5=32
        {
            for(j=i*i; j<=N; j+=2*i)
            {
                prime[j>>5] = set(prime[j>>5], j&31);           // ( i & 31 ) means ( i % 32 )
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
        if( check(prime[i>>5], i&31)==0)
        {
            printf("%ld ",i);
            ++p;
        }
    }

    printf("\n\nTotal prime is: %ld\n", p);

    return 0;
}
