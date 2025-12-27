#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long n, m, ara[10000], i, k, flag;

    while(scanf("%lld %lld", &n, &m)==2)
    {
        k=0;
        flag=1;

        if(!n || !m)
            flag=0;
        else
        {
            ara[k++]=n;

            while(n!=1)
            {
                if(!(n%m))
                {
                    n=n/m;

                    if(n == ara[k-1])
                    {
                        flag=0;
                        break;
                    }

                    ara[k++]=n;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
        }

        if(flag && k !=1)
        {
            printf("%lld", ara[0]);
            for(i=1; i<k; i++)
            {
                printf(" %lld", ara[i]);
            }
            printf("\n");
        }
        else
            printf("Boring!\n");
    }

    return 0;
}
