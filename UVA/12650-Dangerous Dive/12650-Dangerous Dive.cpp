#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long int N, R, i, num;

    while(scanf("%ld %ld", &N, &R)==2)
    {
        long int ara[10000]={0};

        for(i=0; i<R; i++)
        {
            scanf("%ld", &num);

            ara[num] = 1;
        }

        if(N==R)
            printf("*\n");
        else
        {
            for(i=1; i<=N; i++)
            {
                if(!ara[i])
                    printf("%ld ", i);
            }
            printf("\n");
        }

    }

    return 0;
}
