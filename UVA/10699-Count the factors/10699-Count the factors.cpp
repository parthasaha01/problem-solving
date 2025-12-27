#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    long int num, i, a[1000], prime, N, j;
    double root;

    while(scanf("%ld", &num) && num != 0)
    {
            if(num == 1)
            {
                printf("1 : 0\n");
                continue;
            }
            N = num;
            prime = 0;
            j=0;

            line:

            root = sqrt(num);

            for(i=2; i <= (int)root ;)
            {
                if(num % i == 0)
                {
                    num = num/i;
                    a[j] = i;
                    ++j;
                    goto line;
                }

                if(i == 2)
                    i = 3;
                else
                    i += 2;

            }
            a[j] = num;

            ++j;

            sort(a, a+j);

            for(i=0; i<j; i++)
            {
                if(a[i] != a[i+1])
                    ++prime;
            }

            printf("%ld : %ld\n", N, prime);
    }

    return 0;
}
