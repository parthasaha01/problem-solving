#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
int main()
{
        int T;

        scanf("%d", &T);

        long long x,k;

        while(T--)
        {
                scanf("%lld%lld", &x, &k);

                int qi = floor((double)x/k);
                int pi = ceil((double)x/k);

                if( qi == 0 )
                {
                        printf("0 %lld\n", x);
                }
                else
                {
                        printf("%lld %lld\n", k - (x%k), x%k);
                }
        }

        return 0;
}
