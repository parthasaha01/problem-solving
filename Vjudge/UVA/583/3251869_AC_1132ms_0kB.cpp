#include <cstdio>
#include <cmath>
using namespace std;
long long num[60005], prime[10000];
void sieve()
{
    long long i, j, k=0;

    prime[k++] = 2;

    for (i = 3; i <= 245; i+=2)
   {
      if (!num[i])
     {
        prime[k++] = i;
        for (j = i * i; j <= 60000; j += 2*i)
            num[j] = 1;
    }
  }

  for(i=247; i<=60000; i+=2)
  {
      if(!num[i])
        prime[k++] = i;
  }
}
int main()
{
    long long N, sq, k, i, factor[10000];

    sieve();

    while(scanf("%lld", &N) && N)
    {
            if(N < 0)
            {
                printf("%lld = -1 x ", N);
                N = -N;
            }
            else
                printf("%lld = ", N);

            sq = sqrt((double)N);

             k = 0;

            if(N==1)
                factor[k++] = 1;

             for(i=0; prime[i] <= sq; i++)
             {
                 if( (N%prime[i] ) == 0)
                 {
                     while((N%prime[i] ) == 0)
                     {
                         N /= prime[i];
                         //printf("%d-",prime[i]);
                         factor[k++] = prime[i];
                     }
                 }
             }

             if(N>1)
                factor[k++] = N;

            for(i = 0; i < k; i++)
            {
                printf("%lld", factor[i]);
                if(i != k-1)
                    printf(" x ");
            }
            printf("\n");
    }
    return 0;
}
