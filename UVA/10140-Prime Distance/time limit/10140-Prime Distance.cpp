#include<cstdio>
#include<cmath>
using namespace std;
#define S 50000
long long num[S], check[90001], prime[90000], sp, k;
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
    long long L, U, i, j, Max, Min, a, b, c, d, p, diff;

    sieve();

    while(scanf("%lld %lld", &L, &U)==2)
    {
        Max=p=0;
        Min = 2e7;

        if(L<3)
            check[p++]=2;

        if(!(L&1))
            L = L+1;

        for(i=L; i<=U; i+=2)
        {
            if(isprime(i))
            {
                check[p++] = i;
            }
        }

        for(i=0; i<p-1; i++)
        {
            diff = check[i+1]-check[i];

            if(diff > Max)
            {
                Max=diff;
                c=check[i];
                d=check[i+1];
            }
            if(diff<Min)
            {
                Min = diff;
                a=check[i];
                b=check[i+1];
            }
        }

        if(Max)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a, b, c, d);
        else
            puts("There are no adjacent primes.");
    }

    return 0;
}
