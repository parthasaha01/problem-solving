#include <cstdio>
#define S 46340
using namespace std;
long int prime[S] = {1, 1, 0}, p[S], N, check[1000001];

// if prime then return 1 and not prime then return 0
long int isprime(long int n)
{
  if (n < S)
    return !prime[n];       // if prime then return ( !0 ) = 1
  int i;
  for (i = 0; i < N && n > p[i]; i++)
  {
      if (!(n % p[i]))
        return 0;       //not prime
  }

  return 1;     // prime
}

int main()
{
    long int i, j, l, u, m;

  p[N++]=2;

  for (i = 3; i < 215; i+=2)
  {
      if (!prime[i])
     {
        p[N++] = i;
        for (j = i * i; j < S; j += 2*i)
            prime[j] = 1;
    }
  }

  for(i=215; i<S; i+=2)
  {
      if(!prime[i])
        p[N++] = i;
  }

  //for(i=0; i<25; i++)
    //printf("%d ", p[i]);

  while (scanf("%ld %ld", &l, &u) == 2)
 {
     m=1;

     if(l<3)
     {
         for(i=l; i<3 && i<=u; i++)
         {
             check[i - l] = 1;     // prime

            if (!isprime(i))
                check[i - l] = 0;
         }
         m=0;
     }

     if(m)
     {
         if(l&1)
            i=l;
         else
            i=l+1;
     }

     //printf("%ld\n", i);

    while(i<=u)
    {
      check[i - l] = 1;     // prime

      if (!isprime(i))
        check[i - l] = 0;       // not prime

        i+=2;
    }

    /*for(i=0; i<=u-l; i++)
        if(check[i] == 1)
            printf("%d ", i+l);

            printf("\n");*/

    long int a = -1, b = -1, max = 0, min = 2e9, mx1, mx2, mn1, mn2;

    for (i = 0; i <= u - l; i++)
    {
      if (check[i])
      {
         // printf("%ld ",i+l);
        a = i;
        if (b != -1)
        {
          if (a - b > max)
            max = a - b, mx1 = b, mx2 = a;
          if (a - b < min)
            min = a - b, mn1 = b, mn2 = a;
        }
        b = a;
      }
    }

   // printf("\n");

    if (max)
        printf("%ld,%ld are closest, %ld,%ld are most distant.\n", mn1 + l, mn2 + l, mx1 + l, mx2 + l);
    else
        puts("There are no adjacent primes.");
  }
  return 0;
}
