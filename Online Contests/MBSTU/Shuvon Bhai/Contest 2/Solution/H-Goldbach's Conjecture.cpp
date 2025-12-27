#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, a, b, i, j;
    double root;

    while(scanf("%lld", &n)==1 && n!= 0)
    {

        i=1;

        line:

        i += 2;

        while(i <= n/2)
        {
            root = sqrt(i);

            for(j=3; j <= (int)root; j += 2)
            {
                if(i%j == 0)
                    goto line;
            }

            a=i;
            b=n-i;

            root = sqrt(b);

            for(j=3; j <= (int)root; j += 2)
            {
                if(b%j == 0)
                    goto line;
            }

            break;
        }

        printf("%lld = %lld + %lld\n", n, a, b);
    }

    return 0;
}

