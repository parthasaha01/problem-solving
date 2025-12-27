#include<cstdio>
#include<cmath>
using namespace std;
long int num[32800];
void sieve(void)
{
    long int i, j, p=0;

    for(i=3; i <= 181; i+=2)
    {
        if(num[i] == 0)
        {
            for(j=i*i; j<=32800; j += (i<<1))
            {
                num[j]=1;
            }
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
        for(i=3;  i<=N-i; i+=2)
        {
            if((!num[i]) && (!num[N-i]))
                res++;
        }

        if(!res)
            res=1;

        printf("%ld\n",res);
    }

    return 0;
}

