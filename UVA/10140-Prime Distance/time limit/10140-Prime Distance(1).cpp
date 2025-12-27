#include<cstdio>
#include<cmath>
using namespace std;
#define S 50000
long long num[S], prime[90000], sp, k;
int isprime(long long n)
{
    long long i;

    if(n<S)
        return !num[n];

    sp = (long)sqrt((double)n);

    for(i=0; i<k && prime[i]<=sp; i++)
    {
        if(! (n%prime[i]) )
            return 0;
    }

    return 1;
}
void sieve(void)
{
    long int  i, j;

    num[1]=1;
    k=0;

    prime[k++]=2;

    for(i=3; i <= 223; i += 2)
    {
        if(num[i] == 0)
        {
            prime[k++]=i;
            for(j=i*i; j<S; j += (i+i))
            {
                num[j]=1;
            }
        }
    }
    for(i=225; i<S; i+=2)
    {
        if(!num[i])
            prime[k++]=i;
    }
}
int main()
{
    long long L, U, i, j, Max, Min, a, b, c, d, p, m, n, diff;

    sieve();

    while(scanf("%lld %lld", &L, &U)==2)
    {
        Max=0;
        Min = 2e7;
        n=-1;

        if(L<3 && U>2)
        {

            Max=1;
            Min=1;
            a=c=2;
            b=d=3;
        }

        if(!(L&1))
            L = L+1;

        for(i=L; i<=U; i+=2)
        {
            if(isprime(i))
            {
                m=i;
                if(n!=-1)
                {
                    diff=m-n;

                    if (diff > Max)
                        Max = diff, c=n, d=m;
                    if (diff < Min)
                        Min = diff, a=n, b=m;
                }
                n=m;
            }
        }

        if(Max)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a, b, c, d);
        else
            puts("There are no adjacent primes.");
    }

    return 0;
}
