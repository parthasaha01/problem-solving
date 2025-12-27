#include<cstdio>
#include<cmath>
#define max 10000000
using namespace std;

int check(long n, long pos)   // here n = index
{
    if(n & (1<<pos))
        return 1;
    else
        return 0;
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
    long prime[max/32], p=0;

    scanf("%ld", &N);

    sqrtN = (long) sqrt(N);

    for(i=3; i<=sqrtN; i+=2)
    {
        if(check(prime[i/32], i%32)==0)
        {
            for(j=i*i; j<=N; j+=2*i)
            {
                prime[j/32] = set(prime[j/32], j%32);
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
        if( check(prime[i/32], i%32)==0)
        {
            printf("%ld ",i);
            ++p;
        }
    }



    printf("\n\nTotal prime is: %ld\n", p);

    return 0;
}
