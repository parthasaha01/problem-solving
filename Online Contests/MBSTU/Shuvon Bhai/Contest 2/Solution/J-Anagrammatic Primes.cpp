/*
    Anagramatic primes are prime no matter how you rearrange their digits.

    only 22 anagramatic primes IN THE RANGE (1 to 100000000)...
    they are: {2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};

    But there can have bigger anagramatic prime upper than 10^8.
    here 1111111111111111111 is also an anagrammatic prime.


*/
#include <cstdio>
using namespace std;

int main()
{
    int A[]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
    long int N;
    int i,j,flag;

    while(scanf("%ld",&N) && N)
    {
        flag=0;

        if(N>991)
        {
            flag=0;
        }
        else
        {
            j=1;

            while(j<=N)
            {
                j *= 10;
            }

            for(i=0; i<22 && A[i]<j; i++)
            {
                if(A[i]>N)
                {
                    flag=1;
                    break;
                }
            }
        }

        if(flag)
            printf("%d\n",A[i]);
        else
            printf("0\n");
    }

    return 0;
}

