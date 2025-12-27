#include <cstdio>
#include <cmath>
#include<iostream>
using namespace std;
#define Max 1000000
#define sqt 1000
long int num[Max], prime[80000];
void sieve()
{
    long int i, j, k=0,doubleI;

    prime[k++] = 2;

    for (i = 3; i <= sqt; i+=2)
   {
      if (!num[i])
     {
        prime[k++] = i;
        doubleI=i+i;
        for (j = i * i; j <= Max; j += doubleI)
            num[j] = 1;
    }
  }

  for(i=sqt+1; i<=Max; i+=2)
  {
      if(!num[i])
        prime[k++] = i;
  }
}
int main()
{
    long int T, sq, i;
    long long N;
    int flag;

    sieve();

    cin >> T;

    while(T--)
    {
        cin >> N;

        flag=0;

        if(N>3)
        {
            sq = sqrt((double)N);

            for(i=0; prime[i] <= sq; i++)
            {
                if( (N%prime[i] ) == 0)
                {
                    while((N%prime[i] ) == 0)
                    {
                        N /= prime[i];
                    }

                    if(N==1)
                    {
                        flag=1;
                    }
                    break;
                }
            }
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
