#include<cstdio>
using namespace std;

int main()
{
    long long N,LCM;

    while(scanf("%lld",&N)==1)
    {
        if(N<=2)
        {
            LCM=N;
        }
        else if(N&1) // ODD
        {
            LCM = N*(N-1)*(N-2);
        }
        else
        {

            if(N%3 == 0)
            {
                LCM = (N-1)*(N-2)*(N-3);
            }
            else
            {
                LCM = N*(N-1)*(N-3);
            }

        }

        printf("%lld\n",LCM);
    }

    return 0;
}