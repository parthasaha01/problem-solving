#include <cstdio>
#include <cmath>
using namespace std;
long int num[50000], prime[7000];
void sieve()
{
    long int i, j, k=0;

    prime[k++] = 2;

    for (i = 3; i <= 223; i+=2)
   {
      if (!num[i])
     {
        prime[k++] = i;
        for (j = i * i; j <= 50000; j += 2*i)
            num[j] = 1;
    }
  }

  for(i=225; i<=50000; i+=2)
  {
      if(!num[i])
        prime[k++] = i;
  }
}
int main()
{
    long int N, sq, k, i;

    sieve();

    while(scanf("%ld", &N) && N)
    {
            if(N < 0)
            {
                printf("%ld = -1 x", N);
                N = -N;
            }
            else
                printf("%ld =", N);

            //sq = sqrt((double)N);

             k = 0;

            if(N==1)
            {
                printf(" 1\n");
                continue;
            }

             for(i=0; prime[i] <= sqrt(N); i++)
             {
                 if( (N%prime[i] ) == 0)
                 {
                     while((N%prime[i] ) == 0)
                     {
                         N /= prime[i];

                         if (N>1)
                            printf(" %ld x",prime[i]);
                        else
                            printf(" %ld",prime[i]);
                     }
                 }
             }

             if (N>1)
                printf(" %d",N);
            printf("\n");
    }
    return 0;
}
