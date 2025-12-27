#include<cstdio>
#include<cmath>
using namespace std;
long int num[32800], prime[3550];
void sieve(void)
{
    long int i, j, p=0;

    for(i=3; i <= 182; i+=2)
    {
        if(num[i] == 0)
        {
            prime[p++]= i;

            for(j=i*i; j<=32800; j += (i+i))
            {
                num[j]=1;
            }
        }
    }

    for(i=183; i<=32800; i+=2)
    {
            if(!num[i])
            {
               prime[p++] = i;
            }
    }

}
int main()
{
    long int N, i, j, res;

    sieve();

    while(scanf("%ld", &N) && N)
    {
        res=0;
        for(i=0; prime[i] < N; i++)
        {
            j=i;
            while((prime[i]+prime[j] ) <= N)
            {
                if( (prime[i]+prime[j] ) == N)
                {
                    ++res;
                    break;
                }
                ++j;
            }
        }

        if(res==0)
            res=1;

        printf("%ld\n",res);
    }

    return 0;
}
