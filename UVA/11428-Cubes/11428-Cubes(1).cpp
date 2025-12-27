#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long long N, x, y, p, q, result;

    while(scanf("%lld", &N) && N)
    {
        y=1;
        result = 0;
        do
        {

            p=pow(y,3);
            q=N+p;

            //printf("%lld  %lld\n", q, p);

            x=pow(q, 3);

           // printf("%lld  %lld\n", x, y);

            if(x==(int)x)
            {
                result=1;
                break;
            }

            y++;

        }while(x>y);

        if(result)
            printf("%lld %lld\n", x, y);
        else
            printf("No solution\n");
    }

    return 0;
}

